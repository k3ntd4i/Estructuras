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
        return (this->cantidad_nodos == 0) ? 0 : arbol.height();
    }

    bool contains(const T &elemento)
    {
        // por hacer
    }

    void insert(const T &elemento)
    {
        // por hacer
    }

    void remove(const T &elemento)
    {
        // por hacer
    }

    void make_empty()
    {
        arbol.make_tree(T{}, nullptr, nullptr);
        cantidad_nodos = 0;
    }

    T find_min()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ &arbol };
        while (nodo_actual->get_left_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_left_child();
        }

        return nodo_actual->get_element();
    }

    T find_max()
    {
        verificar_contenido();

        ArbolBinario<T> *nodo_actual{ &arbol };
        while (nodo_actual->get_right_child() != nullptr)
        {
            nodo_actual = nodo_actual->get_right_child();
        }

        return nodo_actual->get_element();
    }

    void pre_order()
    {
        arbol.pre_order();
    }
    
    void in_order()
    {
        arbol.in_order();
    }

    void post_order()
    {
        arbol.post_order();
    }

    void level_order()
    {
        arbol.level_order();
    }

private:
    void verificar_contenido()
    {
        if (this->cantidad_nodos == 0)
        {
            throw std::out_of_range("El arbol esta vacio.");
        }
    }
};
