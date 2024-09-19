#pragma once

#include <string>
#include <string_view>
#include <stdexcept>
#include <iostream>

template <typename T>
class TablaHash
{
    struct Node
    {
        T elemento{};

        Node() = default;

        Node(const T &nuevo_elemento)
            : elemento{ nuevo_elemento }
        {
        }
    };

    Node **arreglo{};
    int capacidad{};
    int longitud{};

public:
    TablaHash()
        : arreglo{ new Node*[11]{} }
        , capacidad{ 11 }
        , longitud{ 0 }
    {
    }

    TablaHash(int capacidad_inicial)
        : capacidad{ capacidad_inicial }
        , longitud{ 0 }
    {
        if (capacidad_inicial < 1)
        {
            throw std::out_of_range{ "La capacidad inicial debe ser mayor o igual a 1" };
        }

        this->arreglo = new Node*[capacidad_inicial]{};
    }

    ~TablaHash()
    {
        for (int i{0}; i < this->capacidad; ++i)
        {
            delete this->arreglo[i];
        }

        delete[] this->arreglo;
    }

    bool is_empty()
    {
        return (this->longitud == 0);
    }

    int size()
    {
        return this->longitud;
    }

    void remove()
    {

    }

    void insert(std::string_view clave, const T &valor)
    {
        if (this->longitud > (this->capacidad / 2) || this->longitud == this->capacidad)
        {
            Node **nuevo_arreglo{ new Node*[this->capacidad * 2]{} };

            for (int i{0}; i < this->capacidad; ++i)
            {
                nuevo_arreglo[i] = this->arreglo[i];
            }

            this->capacidad = this->capacidad * 2;
            delete[] this->arreglo;

            this->arreglo = nuevo_arreglo;
        }

        int indice{ hash_code(clave) % this->capacidad };

        while (this->arreglo[indice] != nullptr)
        {
            indice = ((indice * 227) + 1) % this->capacidad;
        } 

        this->arreglo[indice] = new Node{ valor };

        ++this->longitud;
    }

    void search()
    {

    }

    int hash_code(std::string_view clave)
    {
        int sumatoria{ 0 };
        for (int i{0}; i < clave.length(); ++i)
        {
            sumatoria += clave[i] * 37;
        }

        return sumatoria;
    }

    void output()
    {
        std::cout << "[";

        if (this->longitud > 0)
        {
            if (this->arreglo[0] == nullptr)
            {
                std::cout << "";
            }
            else
            {
                std::cout << this->arreglo[0]->elemento;
            }

            for (int i{1}; i < this->capacidad; i++)
            {
                std::cout << ", ";

                if (this->arreglo[i] == nullptr)
                {
                    std::cout << "";
                }
                else
                {
                    std::cout << this->arreglo[i]->elemento;
                }
            }
        }

        std::cout << "]";
    }
};