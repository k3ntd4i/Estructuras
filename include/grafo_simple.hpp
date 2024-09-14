#pragma once

#include <iostream>

template <typename T>
class GrafoSimple
{
    T *nodos{};
    bool *matriz_adyacencia{};
    int cantidad_nodos{};

public:
    GrafoSimple(int numero_nodos)
        : nodos{ new T[numero_nodos]{} }
        , matriz_adyacencia{ new bool[numero_nodos * numero_nodos]{} }
        , cantidad_nodos{ 0 }
    {
    }

    ~GrafoSimple()
    {
        delete[] this->nodos;
        delete[] this->matriz_adyacencia;
    }

    bool is_empty()
    {
        return (this->cantidad_nodos == 0);
    }

    int size()
    {
        return this->cantidad_nodos;
    }

    T remove_element(int indice_nodo)
    {

    }

    void set_element(int indice_nodo, const T &elemento)
    {

    }

    void remove_edge(int indice_nodo_1, int indice_nodo_2)
    {

    }

    void add_edge(int indice_nodo_1, int indice_nodo_2)
    {

    }

    bool contains_node(int indice_nodo)
    {

    }

    T get_element(int indice_nodo)
    {
        return this->nodos[indice_nodo];
    }

    int get_degree(int indice_nodo)
    {

    }

    void clear()
    {

    }

    // El usuario es el responsable de liberar la memoria
    T *get_adjacent_nodes(int indice_nodo)
    {

    }
};