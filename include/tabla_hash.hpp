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
        std::string clave{};
        T valor{};
        bool inactivo{};

        Node() = default;

        Node(const std::string &nueva_clave, const T &nuevo_valor)
            : clave{ nueva_clave }
            , valor{ nuevo_valor }
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

    void remove(std::string_view clave)
    {

    }

    void insert(const std::string &clave, const T &valor)
    {
        if (this->longitud > (this->capacidad / 2) || this->longitud == this->capacidad)
        {
            int capacidad_anterior{ this->capacidad };
            Node **nuevo_arreglo{ new Node*[this->capacidad * 2]{} };

            this->capacidad = this->capacidad * 2;

            for (int i{0}; (i < capacidad_anterior) && (this->arreglo[i] != nullptr); ++i)
            {
                int indice{ hash_code(this->arreglo[i]->clave) % this->capacidad };

                int veces{ 0 };
                while (nuevo_arreglo[indice] != nullptr)
                {
                    if (veces > this->capacidad)
                    {
                        throw std::range_error{ "Se murio la tabla :c" };
                    }

                    indice = ((indice * 227) + 1) % this->capacidad;
                    ++veces;
                }

                nuevo_arreglo[indice] = this->arreglo[i];
            }

            delete[] this->arreglo;
            this->arreglo = nuevo_arreglo;
        }

        int indice{ hash_code(clave) % this->capacidad };

        int veces{ 0 };
        while (this->arreglo[indice] != nullptr)
        {
            if (veces > this->capacidad)
            {
                throw std::range_error{ "Se murio la tabla :c" };
            }

            indice = ((indice * 227) + 1) % this->capacidad;
            ++veces;
        }

        this->arreglo[indice] = new Node{ valor, clave };
        ++this->longitud;
    }

    T search(std::string_view clave)
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
                std::cout << this->arreglo[0]->valor;
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
                    std::cout << this->arreglo[i]->valor;
                }
            }
        }

        std::cout << "]";
    }
};