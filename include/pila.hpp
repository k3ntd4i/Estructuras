#pragma once

#include "lista.hpp"

template<typename T>
class Pila
{
    Lista<T> lista{};

public:
    int size()
    {
        return lista.size();
    }

    bool is_empty()
    {
        return lista.is_empty();
    }

    T top()
    {
        return lista.get(0);
    }

    void push(T x)
    {
        lista.add(0, x);
    }

    T pop()
    {
        return lista.remove(0);
    }

    void output()
    {
        lista.output();
    }
};