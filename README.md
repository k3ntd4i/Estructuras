# Notas

Ignorar lo que esta dentro de las funciones principales `int main()`, allí se encuentran las pruebas que se le hacen a las implementaciones mientras se construyen. Una vez terminadas se procede a borrar el contenido de la función `main()`.

## Detalles de implementación

### `Pila`, `Cola` y `ColaDoble`

En las implementaciones de `Pila`, `Cola` y `ColaDoble` no se utiliza `this->` para acceder a la instancia base de `Lista` debido a la sencillez del código y la casi inexistencia de otras variables diferentes de _"lista"_. En otras palabras, el uso de `this->` es redundante en este caso, ya que su principal propósito es distinguir entre variables locales y variables de instancia.

### `ArbolBinario`

En el método `level_order` de la clase `ArbolBinario` se utiliza un array estilo `C` en vez de un `std::array` debido a que, incluir un `std::array` implicaría usar una estructura de datos de la librería estándar y no una implementación propia.

En los métodos de la clase `ArbolBinario`, los argumentos que implican otros árboles deben pasarse por referencia. Ej: `arbol.metodo(&otro_arbol);`. Esto se debe a que los parámetros son punteros y esperan una dirección de memoria. No tendría sentido trabajar con copias de los árboles, por lo tanto, se debe acceder a los árboles originales.

## Repositorio

En el directorio `include` se encuentran las implementaciones de las estructuras con la extension `.hpp`, es decir, a modo encabezado (`#include <encabezado>`). En este caso, al ser un encabezado propio, para poder incluir los archivos se deben usar comillas dobles y escribir la ruta relativa (la ubicación del archivo `.hpp` respecto al archivo `.cpp` en el que se está incluyendo): Ej: `#include "include/encabezado.hpp"`.

- De la implementación de `Lista` (_list_), sale la implementación de `Pila` (_stack_), `Cola` (_queue_) y `ColaDoble` (_deque_).
- De la implementación de `ArbolBinario`, sale la implementación de `ArbolBusquedaBinaria` (_BST_).

## Definiciones

### Árbol

El concepto de "Árbol Binario" se tomara como una estructura que reúne nodos con el rango de $`[0,2]`$ hijos, sin orden ni verificaciones. De este salen los otros tipos de arboles en los que si se consideran diferentes reglas, como el Árbol de Búsqueda Binaria (ABB o _BST_), Adelson-Velskii y Landis (AVL), entre otros.

En esta estructura se define el concepto de _nodo_ como un espacio de memoria asignado por el compilador al instanciar un objeto `ArbolBinario`. Este puede contener datos o no, lo que implica poder construir un árbol de nodos vacíos (en todo los nodos está el valor por defecto del tipo de dato `T` definido en la instancia). No puede existir un _árbol vacío_ (sin nodos), ya que para que algo sea considerado un árbol, debe tener por lo menos un nodo. Cuando un árbol tiene un solo nodo, ese único nodo es _hoja_ y _raíz_ al mismo tiempo, es decir, lo que sucede al instanciar por defecto: `ArbolBinario<T> arbol{}`.

### Árbol de Búsqueda Binaria

Esta estructura gestiona por si misma instancias de la clase `ArbolBinario`, teniendo en cuenta las siguientes reglas:

_Dada una raíz, se tiene que:_

- _Las claves almacenadas en el subárbol izquierdo de la raíz son menores que la clave de la raíz._
- _Las claves almacenadas en el subárbol derecho de la raíz son mayores que la clave de la raíz._
- _Todos los subárboles cumplen estas propiedades._

Un árbol de Búsqueda Binaria puede estar vació (sin nodos), puesto que, para ser considerado _no vació_, el usuario debe insertar un elemento explícitamente

La altura del árbol se cuenta desde $`1`$, pero será $`0`$ si el árbol está vació.

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
