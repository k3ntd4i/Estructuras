#pragma once

#include "arbol_binario.hpp"

template<typename T>
class ArbolBusquedaBinaria
{
    ArbolBinario<T> arbol{};
    int cantidad_nodos{ 0 };

public:
    ArbolBusquedaBinaria() = default;

    bool is_empty()
    {
        // por hacer
    }

    int size()
    {
        // por hacer
    }

    // Profundidad maxima: cantidad total de niveles (contando desde 1)
    int height()
    {
        return (arbol.height() - 1);
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
    }

    T find_min()
    {
        // por hacer
    }

    T find_max()
    {
        // por hacer
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
};
