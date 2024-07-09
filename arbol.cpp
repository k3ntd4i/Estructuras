#include <iostream>

template<typename T>
class ArbolBinario
{
    T elemento{};
    ArbolBinario<T> *hijo_izquierdo{ nullptr };
    ArbolBinario<T> *hijo_derecho{ nullptr };

public:
    ArbolBinario() = default;

    ArbolBinario(T elemento_inicial)
        : ArbolBinario{ elemento_inicial, nullptr, nullptr }
    {
    };

    ArbolBinario
    (
        T elemento_inicial,
        ArbolBinario<T> *sub_arbol_izquierdo,
        ArbolBinario<T> *sub_arbol_derecho
    )
        : elemento{ elemento_inicial }
        , hijo_izquierdo{ sub_arbol_izquierdo }
        , hijo_derecho{ sub_arbol_derecho }
    {
    };

    bool is_empty()
    {
        // por hacer
    }

    int size() // La cantidad de nodos totales
    {
        // por hacer
    }

    int height() // profundidad
    {
        // por hacer
    }

    ArbolBinario<T> get_left_child()
    {
        return this->hijo_izquierdo;
    }

    ArbolBinario<T> get_right_child()
    {
        return this->hijo_derecho;
    }

    T get_element()
    {
        return this->elemento;
    }

    // los setters deberian hacer una copia de los sub-arboles o se asignan
    // como una referencia a los sub-arboles originales?
    void set_left_child(ArbolBinario<T> sub_arbol_izquierdo)
    {
        this->hijo_izquierdo = sub_arbol_izquierdo;
    }

    void set_right_child(ArbolBinario<T> sub_arbol_derecho)
    {
        this->hijo_derecho = sub_arbol_derecho;
    }

    void set_element(T dato)
    {
        this->elemento = dato;
    }

    // tiene alguna utilidad retornar la raiz? se supone que la instancia del objeto es en si la raiz
    T root()
    {
        // por hacer
    }

    // este metodo reemplaza el arbol existente en la instancia por uno nuevo,
    // sin embargo hace que los sub-arboles originales se modifiquen, es decir, no se clonan los objetos
    void make_tree(T elemento_raiz, ArbolBinario<T> arbol_izquierdo, ArbolBinario<T> arbol_derecho)
    {
        // por hacer
    }

    ArbolBinario<T> remove_left_subtree()
    {
        // por hacer
    }

    ArbolBinario<T> remove_right_subtree()
    {
        // por hacer
    }

    void pre_order()
    {
        // por hacer
    }
    
    void in_order()
    {
        // por hacer
    }

    void post_order()
    {
        // por hacer
    }

    void level_order()
    {
        // por hacer
    }
};

int main()
{
    ArbolBinario<int> arbol{};

    return 0;
}