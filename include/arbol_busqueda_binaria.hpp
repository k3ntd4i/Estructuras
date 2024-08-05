#pragma once

#include "arbol_binario.hpp"
#include <stdexcept>

template<typename T>
class ArbolBusquedaBinaria
{
    ArbolBinario<T> *arbol{ nullptr };
    int cantidad_nodos{ 0 };

public:
    ArbolBusquedaBinaria() = default;

    ArbolBusquedaBinaria(const T &elemento)
        : arbol{ new ArbolBinario<T>{ elemento } }, cantidad_nodos{ 1 }
    {
    }

private:
    int n_nodos{};
    int iterador{};

public:
    ~ArbolBusquedaBinaria()
    {
        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;

        liberar_memoria(this->arbol);
        delete this->arbol;
    }

    bool is_empty()
    {
        return (this->cantidad_nodos == 0);
    }

    int size()
    {
        return this->cantidad_nodos;
    }

    // Profundidad maxima: cantidad total de niveles (contando desde 1)
    int height()
    {
        return (this->cantidad_nodos == 0) ? 0 : this->arbol->height();
    }

    bool contains(const T &elemento)
    {
        return busqueda_booleana(elemento, this->arbol);
    }

    void insert(const T &elemento)
    {
        if (this->cantidad_nodos == 0)
        {
            this->arbol->set_element(elemento);
            this->cantidad_nodos = 1;

            return;
        }

        ArbolBinario<T> *nodo_actual{ this->arbol };

        do
        {
            if (elemento < nodo_actual->get_element()
                && nodo_actual->get_left_child() != nullptr )
            {
                nodo_actual = nodo_actual->get_left_child();
            }
            else if (elemento > nodo_actual->get_element()
                && nodo_actual->get_right_child() != nullptr)
            {
                nodo_actual = nodo_actual->get_right_child();
            }
            else if (elemento == nodo_actual->get_element())
            {
                return;
            }
            else
            {
                break;
            }
        } while (!nodo_actual->is_leaf());

        ArbolBinario<T> *nuevo_nodo{ new ArbolBinario<T>{ elemento } };

        if (elemento < nodo_actual->get_element())
        {
            nodo_actual->set_left_child(nuevo_nodo);
        }
        else if (elemento > nodo_actual->get_element())
        {
            nodo_actual->set_right_child(nuevo_nodo);
        }        

        this->cantidad_nodos ++;
    }

    void remove(const T &elemento)
    {
        verificar_contenido();
        if (this->cantidad_nodos == 1)
        {
            if (this->arbol->get_element() == elemento)
            {
                make_empty();
            }

            return;
        }

        ArbolBinario<T> *nodo_eliminar{ this->arbol };

        while (nodo_eliminar->get_element() != elemento)
        {
            if (elemento < nodo_eliminar->get_element()
                && nodo_eliminar->get_left_child() != nullptr )
            {
                nodo_eliminar = nodo_eliminar->get_left_child();
            }
            else if (elemento > nodo_eliminar->get_element()
                && nodo_eliminar->get_right_child() != nullptr)
            {
                nodo_eliminar = nodo_eliminar->get_right_child();
            }
            else
            {
                return; // Elemento no encontrado: no hacer nada
            }
        }

        if (nodo_eliminar == this->arbol)
        {
            if (nodo_eliminar->get_left_child() != nullptr
                && nodo_eliminar->get_right_child() == nullptr)
            {
                this->arbol = nodo_eliminar->get_left_child();
                nodo_eliminar->set_left_child(nullptr);
            }
            else if (nodo_eliminar->get_left_child() == nullptr
                && nodo_eliminar->get_right_child() != nullptr)
            {
                this->arbol = nodo_eliminar->get_right_child();
                nodo_eliminar->set_right_child(nullptr);
            }
            else if (nodo_eliminar->get_left_child() != nullptr
                && nodo_eliminar->get_right_child() != nullptr)
            {
                ArbolBinario<T> *nodo_menor{ find_menor_derecho(nodo_eliminar) };
                nodo_eliminar->set_element(nodo_menor->get_element());

                ArbolBinario<T> *nodo_padre{ nodo_menor->get_parent() };

                if (nodo_padre->get_left_child() == nodo_menor)
                {
                    nodo_padre->set_left_child(nullptr);
                }
                else if (nodo_padre->get_right_child() == nodo_menor)
                {
                    nodo_padre->set_right_child(nullptr);
                }

                nodo_eliminar = nodo_menor;
            }

            delete nodo_eliminar;
            this->cantidad_nodos --;

            return;
        }

        ArbolBinario<T> *nodo_padre{ nodo_eliminar->get_parent() };
        ArbolBinario<T> *padre_hijo_izquierdo{ nodo_padre->get_left_child() };
        ArbolBinario<T> *padre_hijo_derecho{ nodo_padre->get_right_child() };

        if (nodo_eliminar->is_leaf())
        {
            if (padre_hijo_izquierdo == nodo_eliminar)
            {
                nodo_padre->set_left_child(nullptr);
            }
            else if (padre_hijo_derecho == nodo_eliminar)
            {
                nodo_padre->set_right_child(nullptr);
            }
        }
        else if (nodo_eliminar->get_left_child() != nullptr
            && nodo_eliminar->get_right_child() == nullptr)
        {
            if (padre_hijo_izquierdo == nodo_eliminar)
            {
                nodo_padre->set_left_child(nodo_eliminar->get_left_child());
            }
            else if (padre_hijo_derecho == nodo_eliminar)
            {
                nodo_padre->set_right_child(nodo_eliminar->get_left_child());
            }
        }
        else if (nodo_eliminar->get_left_child() == nullptr
            && nodo_eliminar->get_right_child() != nullptr)
        {
            if (padre_hijo_izquierdo == nodo_eliminar)
            {
                nodo_padre->set_left_child(nodo_eliminar->get_right_child());
            }
            else if (padre_hijo_derecho == nodo_eliminar)
            {
                nodo_padre->set_right_child(nodo_eliminar->get_right_child());
            }
        }
        else
        {
            ArbolBinario<T> *nodo_menor{ find_menor_derecho(nodo_eliminar) };
            nodo_eliminar->set_element(nodo_menor->get_element());

            nodo_padre = nodo_menor->get_parent();

            if (nodo_padre->get_left_child() == nodo_menor)
            {
                nodo_padre->set_left_child(nullptr);
            }
            else if (nodo_padre->get_right_child() == nodo_menor)
            {
                nodo_padre->set_right_child(nullptr);
            }

            nodo_eliminar = nodo_menor;
        }

        delete nodo_eliminar;
        this->cantidad_nodos --;
    }

    void make_empty()
    {
        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;

        liberar_memoria(this->arbol);

        this->arbol->make_tree(T{}, nullptr, nullptr);
        this->cantidad_nodos = 0;
    }

    T find_min()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ this->arbol };
        while (nodo_actual->get_left_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_left_child();
        }

        return nodo_actual->get_element();
    }

    T find_max()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ this->arbol };
        while (nodo_actual->get_right_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_right_child();
        }

        return nodo_actual->get_element();
    }

    void pre_order()
    {
        this->arbol->pre_order();
    }
    
    void in_order()
    {
        this->arbol->in_order();
    }

    void post_order()
    {
        this->arbol->post_order();
    }

    void level_order()
    {
        this->arbol->level_order();
    }

private:
    void verificar_contenido()
    {
        if (this->cantidad_nodos == 0)
        {
            throw std::out_of_range("El arbol esta vacio.");
        }
    }

    bool busqueda_booleana(const T &elemento, ArbolBinario<T> *arbol)
    {
        bool encontrado{};

        if (arbol == nullptr)
        {
            encontrado = false;
        }
        else if (elemento == arbol->get_element())
        {
            encontrado = true;
        }
        else if (elemento < arbol->get_element())
        {
            encontrado = busqueda_booleana(elemento, arbol->get_left_child());
        }
        else if (elemento > arbol->get_element())
        {
            encontrado = busqueda_booleana(elemento, arbol->get_right_child());
        }

        return encontrado;
    }

    ArbolBinario<T> *find_menor_derecho(ArbolBinario<T> *sub_arbol)
    {
        ArbolBinario<T> *nodo_actual{ sub_arbol->get_right_child() };
        while (nodo_actual->get_left_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_left_child();
        }

        return nodo_actual;
    }

    void liberar_memoria(ArbolBinario<T> *sub_arbol)
    {
        if (sub_arbol != nullptr)
        {
            liberar_memoria(sub_arbol->get_left_child());
            liberar_memoria(sub_arbol->get_right_child());
            
            this->iterador ++;

            if (this->iterador < this->n_nodos)
            {
                delete sub_arbol;
            }
        }
    }
};
