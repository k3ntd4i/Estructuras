#include <iostream>

template<typename T>
class ArbolBinario
{
    T elemento{};
    ArbolBinario<T> *hijo_izquierdo{ nullptr };
    ArbolBinario<T> *hijo_derecho{ nullptr };

    int cantidad_nodos{ 0 };
    int altura{ 0 };

    ArbolBinario<T> *raiz{ nullptr };

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
        , raiz{ nullptr }
    {
        this->cantidad_nodos = 1;
        this->altura = 1;

        int altura_maxima{ 0 };

        if (sub_arbol_izquierdo != nullptr)
        {
            altura_maxima = sub_arbol_izquierdo->altura;
            this->cantidad_nodos += sub_arbol_izquierdo->cantidad_nodos;
        }

        if (sub_arbol_derecho != nullptr)
        {
            altura_maxima = std::max(altura_maxima, sub_arbol_derecho->altura);
            this->cantidad_nodos += sub_arbol_derecho->cantidad_nodos;
        }

        this->altura += altura_maxima;
    };

    bool is_empty()
    {
        return (cantidad_nodos == 0) ? true : false;
    }

    int size()
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

    void set_left_child(ArbolBinario<T> *sub_arbol_izquierdo)
    {
        int cantidad_nodos_anterior{ this->cantidad_nodos };

        if (sub_arbol_izquierdo != nullptr)
        {
            sub_arbol_izquierdo->raiz = this;

            if (this->hijo_izquierdo != nullptr)
            {
                this->cantidad_nodos -= this->hijo_izquierdo->cantidad_nodos;
            }

            this->cantidad_nodos += sub_arbol_izquierdo->cantidad_nodos;

            if (this->hijo_derecho != nullptr)
            {
                this->altura = std::max(this->hijo_derecho->altura, sub_arbol_izquierdo->altura) + 1;
            }
            else
            {
                this->altura = sub_arbol_izquierdo->altura + 1;
            }

            ArbolBinario<T> *nodo_padre{ this->raiz };
            int diferencia{ this->cantidad_nodos - cantidad_nodos_anterior };
            while (nodo_padre != nullptr)
            {
                nodo_padre->cantidad_nodos += diferencia;
                nodo_padre = nodo_padre->raiz;
            }
        }

        this->hijo_izquierdo = sub_arbol_izquierdo;
    }

    void set_right_child(ArbolBinario<T> *sub_arbol_derecho)
    {
        int cantidad_nodos_anterior{ this->cantidad_nodos };

        if (sub_arbol_derecho != nullptr)
        {
            sub_arbol_derecho->raiz = this;

            if (this->hijo_derecho != nullptr)
            {
                this->cantidad_nodos -= this->hijo_derecho->cantidad_nodos;
            }

            this->cantidad_nodos += sub_arbol_derecho->cantidad_nodos;

            if (this->hijo_izquierdo != nullptr)
            {
                this->altura = std::max(this->hijo_izquierdo->altura, sub_arbol_derecho->altura) + 1;
            }
            else
            {
                this->altura = sub_arbol_derecho->altura + 1;
            }

            ArbolBinario<T> *nodo_padre{ this->raiz };
            int diferencia{ this->cantidad_nodos - cantidad_nodos_anterior };
            while (nodo_padre != nullptr)
            {
                nodo_padre->cantidad_nodos += diferencia;
                nodo_padre = nodo_padre->raiz;
            }
        }

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
        ArbolBinario<T> *sub_arbol_izquierdo,
        ArbolBinario<T> *sub_arbol_derecho
    )
    {
        this->elemento = elemento_raiz;
        this->hijo_izquierdo = sub_arbol_izquierdo;
        this->hijo_derecho = sub_arbol_derecho;

        this->cantidad_nodos = 1;
        this->altura = 1;

        int altura_maxima{ 0 };

        if (sub_arbol_izquierdo != nullptr)
        {
            altura_maxima = sub_arbol_izquierdo->altura;
            this->cantidad_nodos += sub_arbol_izquierdo->cantidad_nodos;
        }

        if (sub_arbol_derecho != nullptr)
        {
            altura_maxima = std::max(altura_maxima, sub_arbol_derecho->altura);
            this->cantidad_nodos += sub_arbol_derecho->cantidad_nodos;
        }

        this->altura += altura_maxima;
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
    ArbolBinario<T> pre_order_recursivo(ArbolBinario<T> *arbol)
    {
        // por hacer
    }
    
    ArbolBinario<T> in_order_recursivo(ArbolBinario<T> *arbol)
    {
        // por hacer
    }

    ArbolBinario<T> post_order_recursivo(ArbolBinario<T> *arbol)
    {
        // por hacer
    }

    ArbolBinario<T> level_order_recursivo(ArbolBinario<T> *arbol)
    {
        // por hacer
    }
};

int main()
{
    ArbolBinario<char> arbol1{'A'};
    std::cout << "[+] Altura: " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol1.size() << "\n\n";

    ArbolBinario<char> arbol2{'B'};
    std::cout << "[+] Altura: " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol2.size() << "\n\n";

    ArbolBinario<char> arbol3{'C'};
    std::cout << "[+] Altura: " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol3.size() << "\n\n";

    ArbolBinario<char> arbol4{'D'};
    ArbolBinario<char> arbol5{'E'};
    ArbolBinario<char> arbol6{'F'};
    ArbolBinario<char> arbol7{'G'};
    ArbolBinario<char> arbol8{'H'};
    ArbolBinario<char> arbol9{'I'};
    ArbolBinario<char> arbol10{'J'};

    arbol1.set_left_child(&arbol2);

    arbol2.set_left_child(&arbol4);
    arbol2.set_right_child(&arbol5);

    arbol1.set_right_child(&arbol3);
    arbol3.set_left_child(&arbol6);

    arbol6.set_left_child(&arbol7);
    arbol7.set_left_child(&arbol8);
    arbol8.set_left_child(&arbol9);
    arbol9.set_left_child(&arbol10);

    std::cout << "[+] Altura: " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol1.size() << "\n\n";

    std::cout << "[+] Altura: " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol2.size() << "\n\n";

    std::cout << "[+] Altura: " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos: " << arbol3.size() << "\n\n";

    return 0;
}