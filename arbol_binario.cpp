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

        actualizar_datos(sub_arbol_izquierdo, sub_arbol_derecho);
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

    ArbolBinario<T> *get_parent()
    {
        return this->raiz;
    }

    ArbolBinario<T> *get_left_child()
    {
        return this->hijo_izquierdo;
    }

    ArbolBinario<T> *get_right_child()
    {
        return this->hijo_derecho;
    }

    T get_element()
    {
        return this->elemento;
    }

    void set_left_child(ArbolBinario<T> *sub_arbol_izquierdo)
    {
        if (sub_arbol_izquierdo != nullptr)
        {
            set_child(sub_arbol_izquierdo, true);
        }

        this->hijo_izquierdo = sub_arbol_izquierdo;
    }

    void set_right_child(ArbolBinario<T> *sub_arbol_derecho)
    {
        if (sub_arbol_derecho != nullptr)
        {
            set_child(sub_arbol_derecho, false);
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
        const T &elemento_inicial,
        ArbolBinario<T> *sub_arbol_izquierdo,
        ArbolBinario<T> *sub_arbol_derecho
    )
    {
        this->elemento = elemento_inicial;

        if (this->hijo_izquierdo != nullptr)
        {
            this->hijo_izquierdo->raiz = nullptr;
        }
        if (this->hijo_derecho != nullptr)
        {
            this->hijo_derecho->raiz = nullptr;
        }

        this->hijo_izquierdo = sub_arbol_izquierdo;
        this->hijo_derecho = sub_arbol_derecho;

        int cantidad_nodos_anterior{ this->cantidad_nodos };
        int altura_anterior{ this->altura };

        this->cantidad_nodos = 1;
        this->altura = 1;

        actualizar_datos(sub_arbol_izquierdo, sub_arbol_derecho);

        if (this->raiz != nullptr)
        {
            actualizar_datos_padre(cantidad_nodos_anterior, altura_anterior);
        }
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
    void actualizar_datos
    (
        ArbolBinario<T> *sub_arbol_izquierdo,
        ArbolBinario<T> *sub_arbol_derecho
    )
    {
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

    void actualizar_datos_padre(int cantidad_nodos_anterior, int altura_anterior)
    {
        ArbolBinario<T> *nodo_padre{ this->raiz };
        int diferencia_nodos{ this->cantidad_nodos - cantidad_nodos_anterior };

        int altura_derecha{ 0 };
        int altura_izquierda{ 0 };

        if (nodo_padre->hijo_izquierdo != nullptr)
        {
            altura_izquierda = nodo_padre->hijo_izquierdo->altura;
        }

        if (nodo_padre->hijo_derecho != nullptr)
        {
            altura_derecha = nodo_padre->hijo_derecho->altura;
        }

        int altura_maxima{ std::max(altura_izquierda, altura_derecha) };

        int diferencia_altura{ 0 };

        if ((altura_maxima + 1) != nodo_padre->altura)
        {
            diferencia_altura = altura_maxima - altura_anterior;
        }

        do
        {
            nodo_padre->cantidad_nodos += diferencia_nodos;
            nodo_padre->altura += diferencia_altura;
            nodo_padre = nodo_padre->raiz;
        } while (nodo_padre != nullptr);
    }

    void set_child(ArbolBinario<T> *sub_arbol, bool izquierdo)
    {
        ArbolBinario<T> *this_hijo{};
        ArbolBinario<T> *hermano_this_hijo{};

        if (izquierdo)
        { 
            this_hijo = this->hijo_izquierdo;
            hermano_this_hijo = this->hijo_derecho;
        }
        else
        {
            this_hijo = this->hijo_derecho;
            hermano_this_hijo = this->hijo_izquierdo;
        }

        sub_arbol->raiz = this;
        int cantidad_nodos_anterior{ this->cantidad_nodos };

        if (this_hijo != nullptr)
        {
            this->cantidad_nodos -= this_hijo->cantidad_nodos;
        }

        this->cantidad_nodos += sub_arbol->cantidad_nodos;

        int altura_anterior{ this->altura };

        if (hermano_this_hijo != nullptr)
        {
            this->altura = std::max(hermano_this_hijo->altura, sub_arbol->altura) + 1;
        }
        else
        {
            this->altura = sub_arbol->altura + 1;
        }

        if (this->raiz != nullptr)
        {
            actualizar_datos_padre(cantidad_nodos_anterior, altura_anterior);
        }
    }

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
    std::cout << "- Inicializacion ---------------------- \n\n";

    ArbolBinario<char> arbol1{'A'};
    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    ArbolBinario<char> arbol2{'B'};
    std::cout << "[+] Altura " << arbol2.get_element() << ": " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol2.get_element() << ": " << arbol2.size() << "\n\n";

    ArbolBinario<char> arbol3{'C'};
    std::cout << "[+] Altura " << arbol3.get_element() << ": " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol3.get_element() << ": " << arbol3.size() << "\n\n";

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

    std::cout << "- Arbol total ---------------------- \n\n";

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    std::cout << "[+] Altura " << arbol2.get_element() << ": " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol2.get_element() << ": " << arbol2.size() << "\n\n";

    std::cout << "[+] Altura " << arbol3.get_element() << ": " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol3.get_element() << ": " << arbol3.size() << "\n\n";

    ArbolBinario<char> arbol11{'K'};
    arbol8.set_right_child(&arbol11);

    std::cout << "- Arbol modificado ---------------------- \n\n";

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    std::cout << "[+] Altura " << arbol2.get_element() << ": " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol2.get_element() << ": " << arbol2.size() << "\n\n";

    std::cout << "[+] Altura " << arbol3.get_element() << ": " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol3.get_element() << ": " << arbol3.size() << "\n\n";

    std::cout << "[+] Altura " << arbol6.get_element() << ": " << arbol6.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol6.get_element() << ": " << arbol6.size() << "\n\n";

    std::cout << "[+] Altura " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol7.get_element() << ": " << arbol7.size() << "\n\n";

    std::cout << "[+] Altura " << arbol8.get_element() << ": " << arbol8.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol8.get_element() << ": " << arbol8.size() << "\n\n";

    std::cout << "[+] Altura " << arbol9.get_element() << ": " << arbol9.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol9.get_element() << ": " << arbol9.size() << "\n\n";

    std::cout << "[+] Altura " << arbol10.get_element() << ": " << arbol10.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol10.get_element() << ": " << arbol10.size() << "\n\n";

    std::cout << "[+] Altura " << arbol11.get_element() << ": " << arbol11.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol11.get_element() << ": " << arbol11.size() << "\n\n";


    std::cout << "- Test make_tree ---------------------- \n\n";

    std::cout << "[+] Altura antes " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    std::cout << "[+] Cantidad nodos antes " << arbol7.get_element() << ": " << arbol7.size() << '\n';
    std::cout << "[+] Nodo padre de G: " << arbol7.get_parent()->get_element() << "\n\n";
    arbol7.make_tree('X', nullptr, nullptr);
    std::cout << "[+] Altura despues " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    std::cout << "[+] Cantidad nodos despues " << arbol7.get_element() << ": " << arbol7.size() << '\n';
    std::cout << "[+] Nodo padre de X: " << arbol7.get_parent()->get_element() << "\n\n";

    std::cout << "- Arbol make tree ---------------------- \n\n";

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    std::cout << "[+] Altura " << arbol2.get_element() << ": " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol2.get_element() << ": " << arbol2.size() << "\n\n";

    std::cout << "[+] Altura " << arbol3.get_element() << ": " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol3.get_element() << ": " << arbol3.size() << "\n\n";

    std::cout << "[+] Altura " << arbol6.get_element() << ": " << arbol6.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol6.get_element() << ": " << arbol6.size() << "\n\n";

    std::cout << "[+] Altura " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol7.get_element() << ": " << arbol7.size() << "\n\n";

    std::cout << "[+] Altura " << arbol8.get_element() << ": " << arbol8.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol8.get_element() << ": " << arbol8.size() << "\n\n";

    std::cout << "[+] Altura " << arbol9.get_element() << ": " << arbol9.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol9.get_element() << ": " << arbol9.size() << "\n\n";

    std::cout << "[+] Altura " << arbol10.get_element() << ": " << arbol10.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol10.get_element() << ": " << arbol10.size() << "\n\n";

    std::cout << "[+] Altura " << arbol11.get_element() << ": " << arbol11.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol11.get_element() << ": " << arbol11.size() << "\n\n";

    return 0;
}