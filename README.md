# Notas

Ignorar lo que esta dentro del `int main()`, allí se encuentran las pruebas que se le hacen a las implementaciones mientras se construyen. Una vez terminadas se procede a dejar en limpio la función `main()`.

## Estructuras lineales

En `lista_simplemente_enlazada_arreglo_dinamico.cpp` está la implementación de `Lista`, y de ahí sale la implementación de `Pila` (_stack_), `Cola` (_queue_) y `ColaDoble` (_deque_)

## Estructuras no lineales

En el método `level_order` de la clase `ArbolBinario` se utiliza un array estilo `C` en vez de un `std::array` debido a que, incluir un `std::array` implicaría estar usando una estructura de datos de la librería estándar y no una implementación propia.

## Definiciones

### Árbol

El concepto de "Árbol Binario" se tomara como una estructura que reúne nodos con el rango de $`[0,2]`$ hijos, sin orden ni verificaciones. De este se podrán hacer los arboles en los que si se tienen en cuenta diferentes reglas y ordenes (por ahora solo tener en mente el _BST_).

En esta estructura se define el concepto de _nodo_ como un espacio de memoria asignado por el compilador al instanciar un objeto `ArbolBinario`. Este puede contener datos o no, lo que implica poder construir un árbol de nodos vacíos (en todo los nodos está el valor por defecto del tipo de dato `T` definido en la instancia). No puede existir un _árbol vacío_ (sin nodos), ya que para que algo sea considerado un árbol, debe tener por lo menos un nodo. Cuando un árbol tiene un solo nodo, ese único nodo es _hoja_ y _raíz_ al mismo tiempo, es decir, lo que sucede al instanciar por defecto: `ArbolBinario<T> arbol{}`

Se hará la implementación de Árbol de Búsqueda Binaria o _BST_ por sus siglas en inglés (tomando como base el `ArbolBinario`) en el que según los valores que se inserten, estos estarán en determinado orden. Para dicho árbol, probablemente se hagan algoritmos que organicen los nodos y demás.

También es posible que se haga una implementación generalizada de un n-árbol (cualquier cantidad de hijos) para poder hacer cosas jerarquizadas.

## Tareas

### Características

- [ ] Hacer que las estructuras se puedan utilizar desde `#include`

### Implementaciones

- [x] Lista
  - [x] Pila
  - [x] Cola
  - [x] Cola Doble
  - [ ] Arreglo dinámico
- [x] Árbol Binario
  - [ ] BST
  - [ ] AVL
  - [ ] Red-Black
  - [ ] Heap
- [ ] n-Árbol
- [ ] Grafo
- [ ] Tabla Hash
