#include <iostream>
#include <algorithm>

template<typename T>
class ArbolBinario
{
    T elemento{};
    ArbolBinario<T> *hijo_izquierdo{ nullptr };
    ArbolBinario<T> *hijo_derecho{ nullptr };

    int cantidad_nodos{ 1 };
    int altura{ 1 };

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
        , cantidad_nodos{ 1 }
        , altura{ 1 }
        , raiz{ nullptr }
    {
        actualizar_datos(sub_arbol_izquierdo, sub_arbol_derecho);
    };

    bool is_leaf()
    {
        return (cantidad_nodos == 1) ? true : false;
    }

    int size()
    {
        return this->cantidad_nodos;
    }

    int height() // profundidad maxima: cantidad de niveles total (contando desde 1)
    {
        return this->altura;
    }

    int depth() // el nivel del nodo respecto a la raiz (contando desde 1)
    {
        int profundidad{ 1 };
        ArbolBinario<T> *nodo_padre{ this->raiz };

        while (nodo_padre != nullptr)
        {
            profundidad++;
            nodo_padre = nodo_padre->raiz;
        }

        return profundidad;
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
            this->hijo_izquierdo = sub_arbol_izquierdo;
        }
        else
        {
            remove_subtree(true);
        }
    }

    void set_right_child(ArbolBinario<T> *sub_arbol_derecho)
    {
        if (sub_arbol_derecho != nullptr)
        {
            set_child(sub_arbol_derecho, false);
            this->hijo_derecho = sub_arbol_derecho;
        }
        else
        {
            remove_subtree(false);
        }
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

    ArbolBinario<T> *remove_left_subtree()
    {
        ArbolBinario<T> *arbol_retorno{ this->hijo_izquierdo };
        remove_subtree(true);

        return arbol_retorno;
    }

    ArbolBinario<T> *remove_right_subtree()
    {
        ArbolBinario<T> *arbol_retorno{ this->hijo_derecho };
        remove_subtree(false);

        return arbol_retorno;
    }

private:
    int n_nodos{};
    int iterador{};

public:
    void pre_order()
    {
        std::cout << "[";

        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;
        pre_order_recursivo(this);

        std::cout << "]";
    }
    
    void in_order()
    {
        std::cout << "[";

        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;
        in_order_recursivo(this);

        std::cout << "]";
    }

    void post_order()
    {
        std::cout << "[";

        this->n_nodos = this->cantidad_nodos;
        this->iterador = 0;
        post_order_recursivo(this);

        std::cout << "]";
    }

    void level_order()
    {
        std::cout << "[";

        ArbolBinario<T> *lista_nodos[this->cantidad_nodos] {};
        lista_nodos[0] = this;

        this->iterador = 0;
        int indice_inserción{ 1 };
        for (int i{0}; i < this->cantidad_nodos; i++)
        {
            if (lista_nodos[i]->hijo_izquierdo != nullptr)
            {
                lista_nodos[indice_inserción] = lista_nodos[i]->hijo_izquierdo;
                indice_inserción++;
            }

            if (lista_nodos[i]->hijo_derecho != nullptr)
            {
                lista_nodos[indice_inserción] = lista_nodos[i]->hijo_derecho;
                indice_inserción++;
            }

            std::cout << lista_nodos[i]->elemento;
            this->iterador ++;

            if (this->iterador < this->cantidad_nodos)
            {
                std::cout << ", ";
            }
        }

        std::cout << "]";
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

            if (nodo_padre->hijo_izquierdo != nullptr)
            {
                altura_izquierda = nodo_padre->hijo_izquierdo->altura;
            }

            if (nodo_padre->hijo_derecho != nullptr)
            {
                altura_derecha = nodo_padre->hijo_derecho->altura;
            }

            altura_maxima = std::max(altura_izquierda, altura_derecha);

            if ((altura_maxima + 1) != nodo_padre->altura)
            {
                nodo_padre->altura += diferencia_altura;
            }

            nodo_padre = nodo_padre->raiz;
        } while (nodo_padre != nullptr);
    }

    void remove_subtree(bool izquierdo)
    {
        int cantidad_nodos_anterior{ this->cantidad_nodos };
        int altura_anterior{ this->altura };

        ArbolBinario<T> *this_hijo{};
        ArbolBinario<T> *hermano_this_hijo{};

        if (izquierdo)
        { 
            this_hijo = this->hijo_izquierdo;
            hermano_this_hijo = this->hijo_derecho;

            this->hijo_izquierdo = nullptr;
        }
        else
        {
            this_hijo = this->hijo_derecho;
            hermano_this_hijo = this->hijo_izquierdo;

            this->hijo_derecho = nullptr;
        }

        if (this_hijo != nullptr)
        {
            this->cantidad_nodos -= this_hijo->cantidad_nodos;
            this_hijo->raiz = nullptr;
        }

        if (hermano_this_hijo != nullptr)
        {
            this->altura = hermano_this_hijo->altura + 1;
        }
        else
        {
            this->altura = 1;
        }

        if (this->raiz != nullptr)
        {
            actualizar_datos_padre(cantidad_nodos_anterior, altura_anterior);
        }
    }

    void set_child(ArbolBinario<T> *sub_arbol, bool izquierdo)
    {
        if (sub_arbol->raiz != nullptr)
        {
            if (sub_arbol->raiz->hijo_izquierdo == sub_arbol)
            {
                sub_arbol->raiz->remove_subtree(true);
            }
            else if (sub_arbol->raiz->hijo_derecho == sub_arbol)
            {
                sub_arbol->raiz->remove_subtree(false);
            }
        }

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
            this_hijo->raiz = nullptr;
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

    void pre_order_recursivo(ArbolBinario<T> *arbol)
    {
        if (arbol != nullptr)
        {
            std::cout << arbol->elemento;
            this->iterador ++;

            if (this->iterador < this->n_nodos)
            {
                std::cout << ", ";
            }

            pre_order_recursivo(arbol->hijo_izquierdo);
            pre_order_recursivo(arbol->hijo_derecho);
        }
    }
    
    void in_order_recursivo(ArbolBinario<T> *arbol)
    {
        if (arbol != nullptr)
        {
            in_order_recursivo(arbol->hijo_izquierdo);

            std::cout << arbol->elemento;
            this->iterador ++;

            if (this->iterador < this->n_nodos)
            {
                std::cout << ", ";
            }

            in_order_recursivo(arbol->hijo_derecho);
        }
    }

    void post_order_recursivo(ArbolBinario<T> *arbol)
    {
        if (arbol != nullptr)
        {
            post_order_recursivo(arbol->hijo_izquierdo);
            post_order_recursivo(arbol->hijo_derecho);

            std::cout << arbol->elemento;
            this->iterador ++;

            if (this->iterador < this->n_nodos)
            {
                std::cout << ", ";
            }
        }
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

    std::cout << "1) Level-order: ";
    arbol1.level_order(); std::cout << "\n\n";
    std::cout << "[+] Nivel relativo: " << arbol1.depth() << "\n\n";

    ArbolBinario<char> arbol4{'D'};
    ArbolBinario<char> arbol5{'E'};
    ArbolBinario<char> arbol6{'F'};
    ArbolBinario<char> arbol7{'G'};
    ArbolBinario<char> arbol8{'H'};
    ArbolBinario<char> arbol9{'I'};
    ArbolBinario<char> arbol10{'J'};

    arbol1.set_left_child(&arbol2);

    std::cout << "[+] Padre " << arbol2.get_element() << ": " << arbol2.get_parent()->get_element() << '\n';
    std::cout << "[+] Nivel relativo: " << arbol2.depth() << "\n\n";

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

    std::cout << "- Modificando lado izquierdo de A ---------------------- \n\n";

    ArbolBinario<char> arbol12{'L'};
    ArbolBinario<char> arbol13{'M'};
    ArbolBinario<char> arbol14{'N'};
    ArbolBinario<char> arbol15{'O'};
    ArbolBinario<char> arbol16{'P'};
    ArbolBinario<char> arbol17{'Q'};
    arbol4.set_left_child(&arbol12);
    arbol12.set_right_child(&arbol13);
    arbol13.set_right_child(&arbol14);
    arbol14.set_right_child(&arbol15);
    arbol15.set_right_child(&arbol16);

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    arbol16.set_right_child(&arbol17);

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    // std::cout << "- Test make_tree ---------------------- \n\n";

    // std::cout << "[+] Altura antes " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    // std::cout << "[+] Cantidad nodos antes " << arbol7.get_element() << ": " << arbol7.size() << '\n';
    // std::cout << "[+] Nodo padre de G: " << arbol7.get_parent()->get_element() << "\n\n";
    // arbol7.make_tree('X', nullptr, nullptr);
    // std::cout << "[+] Altura despues " << arbol7.get_element() << ": " << arbol7.height() << '\n';
    // std::cout << "[+] Cantidad nodos despues " << arbol7.get_element() << ": " << arbol7.size() << '\n';
    // std::cout << "[+] Nodo padre de X: " << arbol7.get_parent()->get_element() << "\n\n";

    std::cout << "- Arbol cambiado ---------------------- \n\n";

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

    std::cout << "1) Level-order: ";
    arbol1.level_order(); std::cout << "\n\n";

    std::cout << "[+] Padre " << arbol5.get_element() << ": " << arbol5.get_parent()->get_element() << '\n';
    std::cout << "[+] Nivel relativo: " << arbol5.depth() << "\n\n";

    std::cout << "- Creando un grafo falso ---------------------- \n\n";

    arbol12.set_left_child(&arbol11);

    std::cout << "[+] Altura " << arbol12.get_element() << ": " << arbol12.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol12.get_element() << ": " << arbol12.size() << "\n\n";

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

    std::cout << "[+] Hijo derecho " << arbol8.get_element() << ": " << arbol8.get_right_child() << '\n';
    std::cout << "[+] Hijo izquerdo " << arbol8.get_element() << ": " << arbol8.get_left_child()->get_element() << '\n';
    std::cout << "[+] Padre " << arbol8.get_element() << ": " << arbol8.get_parent() << "\n\n";

    std::cout << "[+] Hijo derecho " << arbol12.get_element() << ": " << arbol12.get_right_child()->get_element() << '\n';
    std::cout << "[+] Hijo izquerdo " << arbol12.get_element() << ": " << arbol12.get_left_child()->get_element() << '\n';
    std::cout << "[+] Padre " << arbol11.get_element() << ": " << arbol11.get_parent()->get_element() << "\n\n";

    std::cout << "1) Level-order: ";
    arbol1.level_order(); std::cout << "\n\n";

    std::cout << "[+] Nivel relativo " << arbol17.get_element() << ": " << arbol17.depth() << "\n\n";

    std::cout << "- Volviendo al arbol original ---------------------- \n\n";

    ArbolBinario<char> *retorno1{ arbol4.remove_left_subtree() };
    ArbolBinario<char> *retorno2{ arbol6.remove_left_subtree() };

    std::cout << "[+] Arbol retorno 1: " << retorno1->get_element() << '\n';
    std::cout << "[+] Arbol retorno 2: " << retorno2->get_element() << "\n\n";

    std::cout << "[+] Altura " << arbol1.get_element() << ": " << arbol1.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol1.get_element() << ": " << arbol1.size() << "\n\n";

    std::cout << "[+] Altura " << arbol2.get_element() << ": " << arbol2.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol2.get_element() << ": " << arbol2.size() << "\n\n";

    std::cout << "[+] Altura " << arbol3.get_element() << ": " << arbol3.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol3.get_element() << ": " << arbol3.size() << "\n\n";

    std::cout << "[+] Altura " << arbol4.get_element() << ": " << arbol4.height() << '\n';
    std::cout << "[+] Hijo derecho " << arbol4.get_element() << ": " << arbol4.get_right_child() << '\n';
    std::cout << "[+] Hijo izquerdo " << arbol4.get_element() << ": " << arbol4.get_left_child() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol4.get_element() << ": " << arbol4.size() << "\n\n";

    std::cout << "[+] Altura " << arbol5.get_element() << ": " << arbol5.height() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol5.get_element() << ": " << arbol5.size() << "\n\n";

    std::cout << "[+] Altura " << arbol6.get_element() << ": " << arbol6.height() << '\n';
    std::cout << "[+] Hijo derecho " << arbol6.get_element() << ": " << arbol6.get_right_child() << '\n';
    std::cout << "[+] Hijo izquerdo " << arbol6.get_element() << ": " << arbol6.get_left_child() << '\n';
    std::cout << "[+] Cantidad nodos " << arbol6.get_element() << ": " << arbol6.size() << "\n\n";

    std::cout << "1) Pre-order: ";
    arbol1.pre_order(); std::cout << '\n';

    std::cout << "2) In-order: ";
    arbol1.in_order(); std::cout << '\n';

    std::cout << "3) Post-order: ";
    arbol1.post_order(); std::cout << '\n';

    std::cout << "4) Level-order: ";
    arbol1.level_order(); std::cout << '\n';

    std::cout << "\n- Ejemplos guia 2 ---------------------- \n\n";

    arbol8.remove_left_subtree();
    
    arbol5.set_left_child(&arbol8);

    arbol9.remove_left_subtree();

    arbol6.set_right_child(&arbol9);

    arbol3.set_right_child(&arbol7);

    std::cout << "1) Pre-order: ";
    arbol1.pre_order(); std::cout << '\n';

    std::cout << "2) In-order: ";
    arbol1.in_order(); std::cout << '\n';

    std::cout << "3) Post-order: ";
    arbol1.post_order(); std::cout << '\n';

    std::cout << "4) Level-order: ";
    arbol1.level_order(); std::cout << '\n';

    return 0;
}