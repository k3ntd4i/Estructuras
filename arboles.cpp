#include "include/arbol_binario.hpp"
#include "include/arbol_busqueda_binaria.hpp"
#include <iostream>

int main()
{
    ArbolBinario<int> arbol{};
    ArbolBusquedaBinaria<int> bst{};

    // Input
    // 10 6 12 3 2 1 6 7 7 7 7 7 7 7 6 6 6 4 5 8 7 7 7 9 8 8 6 8 9 10

    int valor{};
    for (int i{0}; i < 30; ++i)
    {
        std::cin >> valor;
        bst.insert(valor);
    }

    bst.level_order(); std::cout << '\n';

    bst.remove(20);
    std::cout << '\n';

    bst.level_order(); std::cout << '\n';

    return 0;
}