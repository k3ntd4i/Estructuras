#pragma once

#include "arbol_binario.hpp"
#include <stdexcept>
#include <iostream>

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

public:
    ~ArbolBusquedaBinaria()
    {
        liberar_memoria(this->arbol);
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
        ArbolBinario<T> *nuevo_nodo{ new ArbolBinario<T>{ elemento } };

        if (this->cantidad_nodos == 0)
        {
            this->arbol = nuevo_nodo;
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

        if (elemento < nodo_actual->get_element())
        {
            nodo_actual->set_left_child(nuevo_nodo);
        }
        else // elemento > nodo_actual->get_element()
        {
            nodo_actual->set_right_child(nuevo_nodo);
        }        

        this->cantidad_nodos ++;
    }

    void remove(const T &elemento)
    {
        verificar_contenido();

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

        if (nodo_eliminar->is_leaf())
        {
            if (nodo_eliminar->get_parent() == nullptr)
            {       
                this->arbol = nullptr;
            }
        }
        else if (nodo_eliminar->get_left_child() != nullptr
            && nodo_eliminar->get_right_child() != nullptr)
        {
            ArbolBinario<T> *nodo_menor{ find_menor_derecho(nodo_eliminar) };
            nodo_eliminar->set_element(nodo_menor->get_element());

            nodo_eliminar = nodo_menor;
        }
        else
        {
            ArbolBinario<T> *nodo_unir{};

            if (nodo_eliminar->get_left_child() != nullptr)
            {
                nodo_unir = nodo_eliminar->get_left_child();
            }
            else
            {
                nodo_unir = nodo_eliminar->get_right_child();
            }

            if (nodo_eliminar->get_parent() == nullptr)
            {
                this->arbol = nodo_unir;
            }
            else
            {
                ArbolBinario<T> *nodo_padre{ nodo_eliminar->get_parent() };

                if (nodo_padre->get_left_child() == nodo_eliminar)
                {
                    nodo_padre->set_left_child(nodo_unir);
                }
                else
                {
                    nodo_padre->set_right_child(nodo_unir);
                }
            }
        }

        delete nodo_eliminar;
        this->cantidad_nodos --;
    }

    void make_empty()
    {
        liberar_memoria(this->arbol);

        this->arbol = nullptr;
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
        if (this->arbol != nullptr)
        {
            this->arbol->pre_order();
        }
        else
        {
            std::cout << "[]";
        }
    }
    
    void in_order()
    {
        if (this->arbol != nullptr)
        {
            this->arbol->in_order();
        }
        else
        {
            std::cout << "[]";
        }
    }

    void post_order()
    {
        if (this->arbol != nullptr)
        {
            this->arbol->post_order();
        }
        else
        {
            std::cout << "[]";
        }
    }

    void level_order()
    {
        if (this->arbol != nullptr)
        {
            this->arbol->level_order();
        }
        else
        {
            std::cout << "[]";
        }
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
        else // elemento > arbol->get_element()
        {
            encontrado = busqueda_booleana(elemento, arbol->get_right_child());
        }

        return encontrado;
    }

    ArbolBinario<T> *find_menor_derecho(ArbolBinario<T> *nodo_base)
    {
        ArbolBinario<T> *nodo_actual{ nodo_base->get_right_child() };
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
            
            delete sub_arbol;
        }
    }
};
