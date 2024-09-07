#include "include/arbol_binario.hpp"
#include "include/arbol_busqueda_binaria.hpp"
#include "include/maximo_heap.hpp"
#include <iostream>

int main()
{
    ArbolBinario<int> arbol{};
    ArbolBusquedaBinaria<int> bst{};
    MaximoHeap<int> heap{ 15 };

    for (int i{0}; i < 10; ++i)
    {
        std::cout << i << ' ';
        heap.put(i);
    }

    heap.put(2);
    heap.put(9);
    heap.put(9);
    heap.put(0);

    std::cout << '\n';

    for (int i{0}; i < 14; ++i)
    {
        std::cout << heap.extract_max() << ' ';
    }

    return 0;
}