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
        int indice{};
        if (this->longitud > (this->capacidad / 2) || this->longitud == this->capacidad)
        {
            Node **arreglo_anterior{ this->arreglo };
            this->arreglo = new Node*[this->capacidad * 2]{};

            int capacidad_anterior{ this->capacidad };
            this->capacidad = this->capacidad * 2;

            for (int i{0}; i < capacidad_anterior; ++i)
            {
                if (arreglo_anterior[i] != nullptr)
                {
                    indice = get_indice(arreglo_anterior[i]->clave, true);
                    if (indice == -1) { return; }

                    this->arreglo[indice] = arreglo_anterior[i];
                }
            }

            delete[] arreglo_anterior;
        }

        indice = get_indice(clave, true);
        if (indice == -1) { return; }

        this->arreglo[get_indice(clave, true)] = new Node{ clave, valor };
        ++this->longitud;
    }

    T search(std::string_view clave)
    {
        int indice{ get_indice(clave, false) };

        if (this->arreglo[indice] == nullptr || indice == -1)
        {
            throw std::invalid_argument{ "No existe un valor correspondiente." };
        }

        return this->arreglo[indice]->valor;
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
        std::cout << '[';

        if (this->longitud > 0)
        {
            if (this->arreglo[0] != nullptr)
            {
                std::cout << this->arreglo[0]->valor;
            }

            for (int i{1}; i < this->capacidad; i++)
            {
                std::cout << ", ";

                if (this->arreglo[i] != nullptr)
                {
                    std::cout << this->arreglo[i]->valor;
                }
            }
        }

        std::cout << ']';
    }

private:
    int get_indice(std::string_view clave, bool insertar)
    {
        int indice{ hash_code(clave) % this->capacidad };

        int veces{ 0 };
        while (this->arreglo[indice] != nullptr)
        {
            if (veces > this->capacidad)
            {
                if (insertar)
                {
                    throw std::range_error{ "No fue posible encontrar una posicion disponible." };
                }

                return -1;
            }

            if (this->arreglo[indice]->clave == clave)
            {
                return (insertar) ? -1 : indice;
            }

            indice = ((indice * 227) + 1) % this->capacidad;
            ++veces;
        }

        return indice;
    }
};