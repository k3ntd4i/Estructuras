#include <iostream>
#include "include/grafo_simple.hpp"
#include "include/lista.hpp"

class Objeto
{
    int valor{ 0 };
    std::string informacion{ "nada" };

public:
    Objeto() = default;

    Objeto(int nuevo_valor, const std::string &cadena)
        : valor{ nuevo_valor }
        , informacion{ cadena }
    {
    }

    ~Objeto()
    {
        std::cout << "Objeto destruido\n";
    }

    int get_valor()
    {
        return valor;
    }
 
    std::string_view get_informacion()
    {
        return informacion;
    }
};

int main()
{
    GrafoSimple<Objeto*> grafo{ 5 };

    std::cout << "Vacio: " << std::boolalpha << grafo.is_empty() << '\n';

    grafo.set_node(0, new Objeto{4, "cero"});

    delete grafo.get_element(0);
    grafo.set_node(0, new Objeto{314, "pi"});

    delete grafo.get_element(0);
    // grafo.remove_node(6);

    // grafo.remove_node(4);
    std::cout << "Contiene nodo 4: " << grafo.contains_node(4) << '\n';
    std::cout << "Contiene nodo 0: " << grafo.contains_node(0) << '\n';

    grafo.remove_node(0);

    grafo.set_node(0, new Objeto{10, "cero"});
    grafo.set_node(1, new Objeto{21, "dos"});

    std::cout << "\nCantidad nodos: " << grafo.size() << '\n';

    grafo.set_node(2, new Objeto{43, "tres"});
    grafo.set_node(3, new Objeto{32, "cuatro"});
    grafo.set_node(4, new Objeto{77, "cinco"});

    std::cout << "\nInformacion: " << grafo.get_element(0)->get_informacion() << '\n';
    std::cout << "Valor: " << grafo.get_element(0)->get_valor() << "\n\n";

    std::cout << std::noboolalpha;
    grafo.print_matrix();
    std::cout << '\n';

    grafo.update_edge(0, 1, true);

    grafo.print_matrix();
    std::cout << '\n';
    
    std::cout << "Hay arista entre el nodo 1 y 4: " << grafo.contains_edge(0, 3) << '\n';
    std::cout << "Grado nodo 4: " << grafo.get_degree(3) << '\n';

    grafo.update_edge(0, 3, true);
    std::cout << "\nHay arista entre el nodo 1 y 4: " << grafo.contains_edge(0, 3) << '\n';
    std::cout << "Grado nodo 4: " << grafo.get_degree(3) << '\n';
    std::cout << "Grado nodo 1: " << grafo.get_degree(0) << '\n';

    std::cout << '\n';
    grafo.print_matrix();
    std::cout << '\n';

    grafo.update_edge(0, 3, false);
    std::cout << "Grado nodo 4: " << grafo.get_degree(3) << '\n';
    std::cout << "Grado nodo 1: " << grafo.get_degree(0) << '\n';

    std::cout << "\nGrado nodo 2: " << grafo.get_degree(1) << '\n';
    std::cout << "Grado nodo 5: " << grafo.get_degree(4) << '\n';

    grafo.update_edge(0, 4, true);
    std::cout << "Grado nodo 5: " << grafo.get_degree(4) << '\n';

    std::cout << '\n';
    grafo.print_matrix();
    std::cout << '\n';

    grafo.update_edge(1, 4, true);
    grafo.update_edge(1, 3, true);
    grafo.update_edge(1, 2, true);
    grafo.update_edge(4, 3, true);
    grafo.update_edge(2, 3, true);

    grafo.print_matrix();
    std::cout << '\n';

    Objeto *nodo_borrado{ grafo.remove_node(3) };
    std::cout << "Nodo eliminado: " << nodo_borrado->get_informacion() << '\n';

    delete nodo_borrado;
    nodo_borrado = nullptr;

    std::cout << "Grado nodo 2: " << grafo.get_degree(1) << '\n';
    std::cout << "Grado nodo 3: " << grafo.get_degree(2) << '\n';
    std::cout << "Grado nodo 5: " << grafo.get_degree(4) << '\n';

    std::cout << '\n';
    grafo.print_matrix();
    std::cout << '\n';

    delete grafo.remove_node(4);
    delete grafo.remove_node(2);
    delete grafo.remove_node(1);

    std::cout << "Grado nodo 1: " << grafo.get_degree(0) << '\n';

    grafo.print_matrix();
    std::cout << '\n';

    delete grafo.remove_node(0);

    std::cout << "\n- Grafo 2 -----------------------------------\n";

    GrafoSimple<std::string> otro_grafo{ 10 };

    otro_grafo.set_node(0, "Empresa 0");
    otro_grafo.set_node(1, "Empresa 1");
    otro_grafo.set_node(2, "Empresa 2");
    otro_grafo.set_node(3, "Empresa 3");
    otro_grafo.set_node(4, "Empresa 4");
    otro_grafo.set_node(5, "Empresa 5");
    otro_grafo.set_node(6, "Empresa 6");
    otro_grafo.set_node(7, "Empresa 7");
    otro_grafo.set_node(8, "Empresa 8");
    otro_grafo.set_node(9, "Empresa 9");

    otro_grafo.update_edge(0, 1, true);
    otro_grafo.update_edge(0, 2, true);
    otro_grafo.update_edge(1, 4, true);
    otro_grafo.update_edge(1, 3, true);
    otro_grafo.update_edge(5, 3, true);
    otro_grafo.update_edge(5, 6, true);
    otro_grafo.update_edge(5, 7, true);
    otro_grafo.update_edge(5, 8, true);
    otro_grafo.update_edge(8, 7, true);
    otro_grafo.update_edge(8, 9, true);

    std::cout << '\n';
    otro_grafo.print_matrix();
    std::cout << '\n';

    Lista<std::string> *adyacentes{};
    for(int i{0}; i < otro_grafo.size(); ++i)
    {
        adyacentes = otro_grafo.get_adjacent_nodes(i);

        std::cout << "Nodo: " << i + 1 << ": ";
        adyacentes->output();

        delete adyacentes;
        std::cout << '\n';
    }

    std::cout << "\nDFS: ";
    otro_grafo.depth_first_search(0);
    std::cout << "\nBFS: ";
    otro_grafo.bradth_first_search(0);

    return 0;
}