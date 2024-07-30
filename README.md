# Notas

Ignorar lo que esta dentro de las funciones principales `int main()`, allí se encuentran las pruebas que se le hacen a las implementaciones mientras se construyen. Una vez terminadas se procede a borrar el contenido de la función `main()`.

## Detalles de implementación

### `ArbolBinario`

  En el método `level_order` de la clase `ArbolBinario` se utiliza un array estilo `C` en vez de un `std::array` debido a que, incluir un `std::array` implicaría usar una estructura de datos de la librería estándar y no una implementación propia.

  En los métodos de la clase `ArbolBinario`, los argumentos que implican otros árboles deben pasarse por referencia. Ej: `arbol.metodo(&otro_arbol);`. Esto se debe a que los parámetros son punteros y esperan una dirección de memoria. No tendría sentido trabajar con copias de los árboles, por lo tanto, se debe acceder a los árboles originales.

## Repositorio

En el directorio `include` se encuentran las implementaciones de las estructuras con la extension `.hpp`, es decir, a modo encabezado (`#include <encabezado>`). En este caso, al ser un encabezado propio, para poder incluir los archivos se deben usar comillas dobles y escribir la ruta relativa (la ubicación del archivo `.hpp` respecto al archivo `.cpp` en el que se está incluyendo): Ej: `#include "include/encabezado.hpp"`.

- En el archivo `estructuras_lineales.hpp` está la implementación de `Lista`, y de ahí sale la implementación de `Pila` (_stack_), `Cola` (_queue_) y `ColaDoble` (_deque_).

- En el archivo `arbol_binario.hpp` está la implementación general/base de árbol binario.

## Definiciones

### Árbol

El concepto de "Árbol Binario" se tomara como una estructura que reúne nodos con el rango de $`[0,2]`$ hijos, sin orden ni verificaciones. De este se podrán hacer los arboles en los que si se tienen en cuenta diferentes reglas y ordenes (por ahora solo tener en mente el _BST_).

En esta estructura se define el concepto de _nodo_ como un espacio de memoria asignado por el compilador al instanciar un objeto `ArbolBinario`. Este puede contener datos o no, lo que implica poder construir un árbol de nodos vacíos (en todo los nodos está el valor por defecto del tipo de dato `T` definido en la instancia). No puede existir un _árbol vacío_ (sin nodos), ya que para que algo sea considerado un árbol, debe tener por lo menos un nodo. Cuando un árbol tiene un solo nodo, ese único nodo es _hoja_ y _raíz_ al mismo tiempo, es decir, lo que sucede al instanciar por defecto: `ArbolBinario<T> arbol{}`.

Se hará la implementación de Árbol de Búsqueda Binaria o _BST_ por sus siglas en inglés (tomando como base el `ArbolBinario`) en el que según los valores que se inserten, estos estarán en determinado orden. Para dicho árbol, probablemente se hagan algoritmos que organicen los nodos y demás.

También es posible que se haga una implementación generalizada de un n-árbol (cualquier cantidad de hijos) para poder hacer cosas jerarquizadas.

## Tareas

### Características

- [x] Hacer que las estructuras se puedan utilizar desde `#include`

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
