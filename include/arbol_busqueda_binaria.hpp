#pragma once

#include "arbol_binario.hpp"
#include <stdexcept>

template<typename T>
class ArbolBusquedaBinaria
{
    ArbolBinario<T> arbol{};
    int cantidad_nodos{ 0 };

public:
    ArbolBusquedaBinaria() = default;

    ArbolBusquedaBinaria(const T &elemento)
        : arbol{ elemento }, cantidad_nodos{ 1 }
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

        liberar_memoria(&this->arbol);
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
        return (this->cantidad_nodos == 0) ? 0 : this->arbol.height();
    }

    bool contains(const T &elemento)
    {
        // por hacer
    }

    void insert(const T &elemento)
    {
        if (this->cantidad_nodos == 0)
        {
            this->arbol.set_element(elemento);
            this->cantidad_nodos = 1;

            return;
        }

        ArbolBinario<T> *nodo_actual{ &this->arbol };

        while (!nodo_actual->is_leaf())
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
        }

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
        // por hacer
    }

    void make_empty()
    {
        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;

        liberar_memoria(&this->arbol);

        this->arbol.make_tree(T{}, nullptr, nullptr);
        this->cantidad_nodos = 0;
    }

    T find_min()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ &this->arbol };
        while (nodo_actual->get_left_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_left_child();
        }

        return nodo_actual->get_element();
    }

    T find_max()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ &this->arbol };
        while (nodo_actual->get_right_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_right_child();
        }

        return nodo_actual->get_element();
    }

    void pre_order()
    {
        this->arbol.pre_order();
    }
    
    void in_order()
    {
        this->arbol.in_order();
    }

    void post_order()
    {
        this->arbol.post_order();
    }

    void level_order()
    {
        this->arbol.level_order();
    }

private:
    void verificar_contenido()
    {
        if (this->cantidad_nodos == 0)
        {
            throw std::out_of_range("El arbol esta vacio.");
        }
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
