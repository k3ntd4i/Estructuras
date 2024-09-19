#pragma once

#include <string>
#include <string_view>
#include <stdexcept>

template <typename T>
class TablaHash
{
    T *array{};
    int capacidad{};
    int longitud{};

public:
    TablaHash()
        : array{ new T[11]{} }
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

        this->array = new T[capacidad_inicial]{};
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

    void insert()
    {

    }

    void search()
    {

    }

    int hash_code(std::string_view llave)
    {
        int sumatoria{ 0 };
        for (int i{0}; i < llave.length(); ++i)
        {
            sumatoria += llave[i] * 37;
        }

        return sumatoria % this->capacidad;
    }
};