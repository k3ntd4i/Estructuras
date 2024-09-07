#include "include/arbol_binario.hpp"
#include "include/arbol_busqueda_binaria.hpp"
#include "include/maximo_heap.hpp"
#include "include/minimo_heap.hpp"
#include <iostream>

int main()
{
    ArbolBinario<int> arbol{};
    ArbolBusquedaBinaria<int> bst{};
    MaximoHeap<int> max_heap{};
    MinimoHeap<int> min_heap{};

    std::cout << "[+] Maximo heap:\n";
    for (int i{0}; i < 10; ++i)
    {
        // std::cout << i << ' ';
        max_heap.put(i);
    }

    max_heap.put(2);
    max_heap.put(3);
    max_heap.put(3);
    max_heap.put(0);

    std::cout << "\n- Imprimiendo: ";
    int longitud{ max_heap.size() };
    for (int i{0}; i < longitud; ++i)
    {
        std::cout << max_heap.extract_max() << ' ';
    }

    /////////////////////////////////////////////////////////////////

    std::cout << "\n\n[+] Minimo heap:\n";
    for (int i{9}; i >= 0; --i)
    {
        // std::cout << i << ' ';
        min_heap.put(i);
    }

    min_heap.put(2);
    min_heap.put(9);
    min_heap.put(9);
    min_heap.put(0);

    std::cout << "\n- Imprimiendo: ";
    longitud = min_heap.size();
    for (int i{0}; i < longitud; ++i)
    {
        std::cout << min_heap.extract_min() << ' ';
    }

    return 0;
}