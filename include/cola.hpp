#pragma once

#include "lista.hpp"

template<typename T>
class Cola
{
    Lista<T> lista{};

public:
    Cola() = default;

    int size()
    {
        return lista.size();
    }

    bool is_empty()
    {
        return lista.is_empty();
    } 

    T front()
    {
        return lista.get(0);
    }

    T back()
    {
        return lista.get(lista.length());
    }

    void put(T x)
    {
        lista.add(lista.size(), x);
    }

    T remove()
    {
        return lista.remove(0);
    }

    void output()
    {
        lista.output();
    }
};
