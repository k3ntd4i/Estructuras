#include "include/arbol_binario.hpp"
#include "include/arbol_bs.hpp"
#include <iostream>

int main()
{
    ArbolBinario<int> arbol{};

    ArbolBusquedaBinaria<int> bst_1{};
    ArbolBusquedaBinaria<int> bst_2{ 4 };

    std::cout << "Size: " << bst_1.size() << std::boolalpha << ", vacio: " << bst_1.is_empty();
    std::cout << "\nAltura: " << bst_1.height() << '\n';

    std::cout << "\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << '\n';

    // std::cout << bst_1.find_min();
    // std::cout << bst_1.find_max();
    std::cout << "[+] Minimo: " << bst_2.find_min() << '\n';
    std::cout << "[+] Maximo: " << bst_2.find_max() << '\n';

    bst_2.make_empty();

    std::cout << "\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    return 0;
}