#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Lista
{
    T *arreglo{};
    int capacidad{};
    int longitud{};

public:
    Lista() : arreglo{ new T[1]{} }, capacidad{ 1 }, longitud{ 0 } {}

    Lista(int capacidad_inicial)
        : capacidad{ capacidad_inicial }, longitud{ 0 }
    {
        if (capacidad_inicial < 1)
        {
            throw std::out_of_range("La capacidad inicial debe ser mayor o igual a 1");
        }

        this->arreglo = new T[capacidad_inicial]{};
    }

    ~Lista() { delete[] this->arreglo; }

    bool is_empty()
    {
        return (this->longitud == 0);
    }

    // Numero de elementos total
    int size()
    {
        return this->longitud;
    }

    // Indice maximo
    int length()
    {
        return (this->longitud - 1);
    }

    T get(int posicion)
    {
        verificar_indice(posicion);
        return this->arreglo[posicion];
    }

    int index_of(T x)
    {
        for (int i{0}; i < this->longitud; i++)
        {
            if (this->arreglo[i] == x)
            {
                return i;
            }
        }

        return -1;
    }

    T remove(int posicion)
    {
        verificar_indice(posicion);
        T elemento_removido{ this->arreglo[posicion] };

        for (int i{ posicion + 1 }; i < this->longitud; i++)
        {
            this->arreglo[i - 1] = this->arreglo[i];
        }

        this->arreglo[--this->longitud] = T{}; // Le asigna el valor por defecto de T
        return elemento_removido;
    }

    void add(int posicion, T x)
    {
        if (posicion < 0 || posicion > this->longitud)
        {
            throw std::out_of_range("Indice fuera de rango.");
        }

        if (this->longitud == this->capacidad)
        {
            this->capacidad *= 2;
            T *nuevo_arreglo{ new T[this->capacidad]{} };

            for (int i{0}; i < this->longitud; i++)
            {
                nuevo_arreglo[i] = this->arreglo[i];
            }

            delete[] this->arreglo;
            this->arreglo = nuevo_arreglo;
        }

        for (int i{ this->longitud - 1 }; i >= posicion; i--)
        {
            this->arreglo[i + 1] = this->arreglo[i];
        }

        this->arreglo[posicion] = x;
        this->longitud ++;
    }

    void output()
    {
        std::cout << "[";

        if (this->longitud > 0)
        {
            std::cout << this->arreglo[0];
            for (int i{1}; i < this->longitud; i++)
            {
                std::cout << ", " << this->arreglo[i];
            }
        }

        std::cout << "]";
    }

private:
    void verificar_indice(int posicion)
    {
        if (posicion < 0 || posicion >= this->longitud)
        {
            throw std::out_of_range("Indice fuera de rango.");
        }
    }
};