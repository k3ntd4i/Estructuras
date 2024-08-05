#include "include/arbol_binario.hpp"
#include "include/arbol_busqueda_binaria.hpp"
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

    // bst_1.remove(5);
    // bst_2.remove(4);
    bst_2.remove(5);

    // std::cout << bst_1.find_min();
    // std::cout << bst_1.find_max();
    std::cout << "[+] Minimo: " << bst_2.find_min() << '\n';
    std::cout << "[+] Maximo: " << bst_2.find_max() << '\n';

    bst_2.make_empty();

    std::cout << "\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Digite las entradas del arbol:\n";

    // Input:
    // 94 141 47 71 100 30 304 24 62 98 776 110 84 33 55 125 5 114 117 49 59 -9999

    int n{ 94 };
    while (n != -9999)
    {
        bst_2.insert(n);
        std::cin >> n;
    }

    std::cout << "\n[+] Arbol Pre Order:\n";
    bst_2.pre_order();

    std::cout << "\n\n[+] Arbol In Order:\n";
    bst_2.in_order();

    std::cout << "\n\n[+] Arbol Post Order:\n";
    bst_2.post_order();

    std::cout << "\n\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    std::cout << "\n\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\nContains 55: " << bst_2.contains(55);
    std::cout << "\nContains 123: " << bst_2.contains(123) << '\n';

    std::cout << "[+] Minimo: " << bst_2.find_min() << '\n';
    std::cout << "[+] Maximo: " << bst_2.find_max() << '\n';

    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    std::cout << "\n\n[+] Maximo: " << bst_2.find_max() << '\n';

    std::cout << "\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    bst_2.remove(bst_2.find_max());

    std::cout << "\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    bst_2.remove(47);

    std::cout << "\n\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    bst_2.remove(59);

    std::cout << "\n\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());
    bst_2.remove(bst_2.find_max());

    std::cout << "\n\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    std::cout << "\n[+] Minimo: " << bst_2.find_min() << '\n';
    std::cout << "[+] Maximo: " << bst_2.find_max() << '\n';

    bst_2.remove(94);

    std::cout << "\n\nSize: " << bst_2.size() << std::boolalpha << ", vacio: " << bst_2.is_empty();
    std::cout << "\nAltura: " << bst_2.height() << '\n';

    std::cout << "\n[+] Arbol Level Order:\n";
    bst_2.level_order();

    std::cout << "\n\n[+] Minimo: " << bst_2.find_min() << '\n';
    std::cout << "[+] Maximo: " << bst_2.find_max() << '\n';

    return 0;
}