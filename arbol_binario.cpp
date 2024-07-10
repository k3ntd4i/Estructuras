#include <iostream>

template<typename T>
class ArbolBinario
{
    T elemento{};
    ArbolBinario<T> *hijo_izquierdo{ nullptr };
    ArbolBinario<T> *hijo_derecho{ nullptr };

    int cantidad_nodos{ 0 };
    int altura{ 1 };

public:
    ArbolBinario() = default;

    ArbolBinario(const T &elemento_inicial)
        : ArbolBinario{ elemento_inicial, nullptr, nullptr }
    {
    };

    ArbolBinario
    (
        const T &elemento_inicial,
        ArbolBinario<T> *sub_arbol_izquierdo,
        ArbolBinario<T> *sub_arbol_derecho
    )
        : elemento{ elemento_inicial }
        , hijo_izquierdo{ sub_arbol_izquierdo }
        , hijo_derecho{ sub_arbol_derecho }
        , cantidad_nodos{ 1 }
    {
        if (this->hijo_izquierdo != nullptr || this->hijo_derecho != nullptr)
        {
            this->altura = 2;
        }
    };

    bool is_empty()
    {
        return (cantidad_nodos == 0) ? true : false;
    }

    int size() // La cantidad de nodos totales
    {
        return this->cantidad_nodos;
    }

    int height() // profundidad: cantidad de niveles (contando desde 1)
    {
        return this->altura;
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

    // los setters y el metodo "make_tree" no tomaran por copia los argumentos que se le pasen,
    // es decir, si se modifican los sub-arboles, tambien modificaran los arboles originales
    void set_left_child(ArbolBinario<T> &sub_arbol_izquierdo)
    {
        this->hijo_izquierdo = sub_arbol_izquierdo;
    }

    void set_right_child(ArbolBinario<T> &sub_arbol_derecho)
    {
        this->hijo_derecho = sub_arbol_derecho;
    }

    void set_element(const T &dato)
    {
        this->elemento = dato;
    }

    // este metodo reemplaza el arbol existente en la instancia por uno nuevo
    void make_tree
    (
        const T &elemento_raiz,
        ArbolBinario<T> &arbol_izquierdo,
        ArbolBinario<T> &arbol_derecho
    )
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

private:
    ArbolBinario<T> pre_order_recursivo(const ArbolBinario<T> &arbol)
    {
        // por hacer
    }
    
    ArbolBinario<T> in_order_recursivo(const ArbolBinario<T> &arbol)
    {
        // por hacer
    }

    ArbolBinario<T> post_order_recursivo(const ArbolBinario<T> &arbol)
    {
        // por hacer
    }

    ArbolBinario<T> level_order_recursivo(const ArbolBinario<T> &arbol)
    {
        // por hacer
    }
};

int main()
{
    ArbolBinario<int> arbol{};

    return 0;
}