#include "include/tabla_hash.hpp"
#include <iostream>
#include <string>

int main()
{
    TablaHash<std::string> tabla{ 10007 };

    for (int i{0}; i < 20000; ++i)
    {
        // std::cout << i << '\n';
        try
        {
            tabla.insert("clave" + std::to_string(i), "Empresa_" + std::to_string(i));
        }
        catch (const std::range_error &error)
        {
            std::cerr << "Error de rango: " << error.what() << '\n';
            return 1;
        }
    }

    std::cout << tabla.remove("clave19000") << '\n';
    tabla.insert("clave19000", "augu");

    try
    {
        std::cout << tabla.search("clave10009") << '\n';
        std::cout << tabla.search("clave19000") << '\n';
    }
    catch (const std::invalid_argument &error)
    {
        std::cerr << "Argumento invalido: " << error.what() << '\n';
        return 1;
    }

    // tabla.output();
    std::cout << "\nfunciono!\n";

    return 0;
}