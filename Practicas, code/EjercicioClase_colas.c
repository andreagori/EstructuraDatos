/*
Estructura de datos, ejercicio creando colas.
*/

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Estructura

typedef struct Nodo
{
    int data;
    struct Nodo *siguiente;
} Nodo;

typedef struct Cola
{
    // aqui llamamos a nodo, ya que lo que hace diferente a esta de una pila es que
    // se crea un puntero con el primer nodo y el ultimo al seguir FIFO (first in, first out).
    Nodo *primero;
    Nodo *ultimo;
} Cola;

// declaracion de funciones -------------------------------------
void enqueue(Cola *colita, int numeros);
int dequeue(Cola *colita);
int peek(Cola *colita);
void printColita(Cola *colita);

// FUNCIONES ----------------------------------------------------
// crear nodo en cola.
void enqueue(Cola *colita, int numeros)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL)
    {
        return;
    }
    nuevoNodo->data = numeros;
    nuevoNodo->siguiente = NULL; // el nodo siguiente estara vacio.

    // AGREGAR UN NODO A LA COLA CONDICION.
    if (colita->ultimo == NULL) // si la cola esta vacia.
    {
        // este se debe de poner asi, ya que las dos posiciones se tiene que asignar.
        colita->primero = nuevoNodo;
        colita->ultimo = nuevoNodo;
    }
    else
    {
        // si la cola tiene elementos, unicamente es agrega al final de la cola
        colita->ultimo->siguiente = nuevoNodo;
        colita->ultimo = nuevoNodo;
    }
}

// funcion eliminar elemento de la cola. Aqui unicamente se puede eliminar el primero, FIFO.
int dequeue(Cola *colita)
{
    // revisar si la cola esta vacia
    if (colita->primero == NULL)
    {
        printf("NO TIENES NINGUN ELEMENTO EN LA COLA");
        return -1; // error.
    }
    // eliminar primero de la cola.
    // 1. Creamos un nodo a eliminar que apunta al primero de la cola
    Nodo *nodoBorrar = colita->primero;
    // 2. Declaramos una variable dentro de la funcion que almacenara el dato del elemento de
    // la cola.
    int valor = nodoBorrar->data;
    // 3. Hacemos que el primero apunte al siguiente del primero, convirtiendo a este en primero.
    colita->primero = nodoBorrar->siguiente;

    // CONDICION SI LA COLA QUEDO VACIA DESPUES DE ELIMINAR ELEMENTO.
    if (colita->primero == NULL)
    {
        // significa que no hay nada ya.
        colita->ultimo = NULL;
    }
    // liberamos memoria del nodo eliminado
    free(nodoBorrar);
    // se devuelve el valor eliminado ya que es util para el usuario al saber que
    // valor ha sido borrado.
    return valor;
}

// Funcion para ver el primer elemento de la cola sin eliminarlo:
int peek(Cola *colita)
{
    // revisar si la cola esta vacia
    if (colita->primero == NULL)
    {
        return -1;
    }

    return colita->primero->data;
}

void printColita(Cola *colita)
{
    // creamos un nodo que apuntara al primero de la cola.
    Nodo *actual = colita->primero;
    // mientras actual no sea null (verifica tambien que la pila no este vacia).
    while (actual != NULL)
    {
        printf("%d ", actual->data);
        actual = actual->siguiente;
    }
    printf("\n");
}

// USARLO.
int main()
{
    Cola colaa = {NULL, NULL}; // hacemos que tanto el primero como el ultimo apunten a null.

    // Agregamos elemento a la cola
    enqueue(&colaa, 1);
    enqueue(&colaa, 2);
    enqueue(&colaa, 6);
    enqueue(&colaa, 7);

    printf("COLA COMPLETA:\n");
    printColita(&colaa);
    // eliminar el primer elemento de la cola.
    // ver el primer elemento de la cola
    printf("ELEMENTO DE LA COLA ELIMINADA:\n %d\n", dequeue(&colaa));
    printf("NUEVO ELEMENTO SIENDO EL PRIMERO DE LA COLA: \n %d\n", peek(&colaa));
    printf("COLA COMPLETA SIN EL ELEMENTO ELIMINADO: \n");
    printColita(&colaa);

    return 0;
}