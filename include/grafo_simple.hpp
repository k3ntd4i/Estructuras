#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class GrafoSimple
{
    struct Node
    {
        T elemento{};
        int grado{};

        Node() = default;
        Node(const T &nuevo_elemento) : elemento{ nuevo_elemento }, grado{ 0 } {}
    };

    Node **lista_nodos{};
    bool *matriz_adyacencia{};
    int cantidad_nodos{};
    int capacidad{};

public:
    GrafoSimple(int numero_nodos)
        : lista_nodos{ new Node*[numero_nodos]{} }
        , matriz_adyacencia{ new bool[numero_nodos * numero_nodos]{} }
        , cantidad_nodos{ 0 }
        , capacidad{ numero_nodos }
    {
    }

    ~GrafoSimple()
    {
        for (int i{0}; i < this->capacidad; ++i)
        {
            delete this->lista_nodos[i];
        }

        delete[] this->lista_nodos;
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

    T remove_node(int indice_nodo)
    {
        verificar_indice(indice_nodo);
        verificar_existencia(indice_nodo);

        T nodo_removido{ this->lista_nodos[indice_nodo]->elemento };

        delete this->lista_nodos[indice_nodo];
        this->lista_nodos[indice_nodo] = nullptr;

        for (int i{0}; i < this->capacidad; ++i)
        {
            if (this->matriz_adyacencia[(this->capacidad * i) + indice_nodo])
            {
                this->matriz_adyacencia[(this->capacidad * i) + indice_nodo] = false;
                this->matriz_adyacencia[(this->capacidad * indice_nodo) + i] = false;

                --this->lista_nodos[i]->grado;
            }
        }

        --this->cantidad_nodos;
        return nodo_removido;
    }

    void set_node(int indice_nodo, const T &elemento)
    {
        verificar_indice(indice_nodo);
        Node *nuevo_nodo{ new Node{elemento} };

        if (this->lista_nodos[indice_nodo] != nullptr)
        {
            delete this->lista_nodos[indice_nodo];

            this->lista_nodos[indice_nodo] = nuevo_nodo;
            return;
        }

        this->lista_nodos[indice_nodo] = nuevo_nodo;
        ++this->cantidad_nodos;
    }

    void update_edge(int indice_nodo_1, int indice_nodo_2, bool enlazar)
    {
        verificar_indice(indice_nodo_1, indice_nodo_2);
        verificar_existencia(indice_nodo_1);
        verificar_existencia(indice_nodo_2);

        this->matriz_adyacencia[(this->capacidad * indice_nodo_1) + indice_nodo_2] = enlazar;
        this->matriz_adyacencia[(this->capacidad * indice_nodo_2) + indice_nodo_1] = enlazar;

        if (enlazar)
        {
            ++this->lista_nodos[indice_nodo_1]->grado;
            ++this->lista_nodos[indice_nodo_2]->grado;
        }
        else
        {
            --this->lista_nodos[indice_nodo_1]->grado;
            --this->lista_nodos[indice_nodo_2]->grado;
        }
    }

    bool contains_node(int indice_nodo)
    {
        verificar_indice(indice_nodo);
        return (this->lista_nodos[indice_nodo] == nullptr) ? false : true;
    }

    bool contains_edge(int indice_nodo_1, int indice_nodo_2)
    {
        verificar_indice(indice_nodo_1, indice_nodo_2);
        verificar_existencia(indice_nodo_1);
        verificar_existencia(indice_nodo_2);

        return (this->matriz_adyacencia[(this->capacidad * indice_nodo_1) + indice_nodo_2]);
    }

    T get_element(int indice_nodo)
    {
        verificar_indice(indice_nodo);
        verificar_existencia(indice_nodo);

        return this->lista_nodos[indice_nodo]->elemento;
    }

    int get_degree(int indice_nodo)
    {
        verificar_indice(indice_nodo);
        verificar_existencia(indice_nodo);

        return this->lista_nodos[indice_nodo]->grado;
    }

    void clear()
    {
        // por hacer
    }

    // El usuario es el responsable de liberar la memoria
    T *get_adjacent_nodes(int indice_nodo)
    {
        // por hacer
    }

    void print_matrix()
    {
        for (int i{0}; i < this->capacidad; ++i)
        {
            for (int j{0}; j < this->capacidad; ++j)
            {
                std::cout << this->matriz_adyacencia[(i * this->capacidad) + j] << ' ';
            }
            std::cout << '\n';
        }
    }

    // hacer recorridos

private:
    void verificar_indice(int posicion)
    {
        if (posicion < 0 || posicion >= this->capacidad)
        {
            throw std::out_of_range{ "Indice fuera de rango." };
        }
    }

    void verificar_indice(int posicion_1, int posicion_2)
    {
        if ((posicion_1 < 0 || posicion_1 >= this->capacidad)
            || (posicion_2 < 0 || posicion_2 >= this->capacidad))
        {
            throw std::out_of_range{ "Indice fuera de rango." };
        }
    }

    void verificar_existencia(int indice)
    {
        if (this->lista_nodos[indice] == nullptr)
        {
            throw std::invalid_argument
            {
                "El nodo con indice " + std::to_string(indice) + " no existe."
            };
        }
    }
};