#include <stdio.h>
#include <stdlib.h>
// para completo y lleno.
#include <stdbool.h>

// ESTRUCTURAS
typedef struct Nodo
{
    int dato;
    struct Nodo *izquierdoPtr;
    struct Nodo *derechaPtr;
} Nodo;

// FUNCIONES
struct Nodo *crearNodo(int dato)
{
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->izquierdoPtr = NULL;
    nodo->derechaPtr = NULL;

    return nodo;
};
/*
Para insertar del lado derecho, no haya nada. Si no hay nada ahi se insertara, si hay algo
debo de avanzar y como avanzare, trabajare con un subarbol del lado derecho por tanto
Primero el dato es mayor, que el dato que esta en el arbol? Si es positivo, se ira al lado
derecho, ahora debemos saber si tienen hijos, si es diferente de NULL, se crea el
nodo y si es NULL, se convierte esto a raiz y se vuelve a hacer lo mismo.
*/

void insertar(struct Nodo *arbol, int dato)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(dato);
    }
    else
    {
        if (dato < arbol->dato)
        { // Si el dato es menor que el dato del nodo actual se pasa a la izquierda
            if (arbol->izquierdoPtr == NULL)
            {
                arbol->izquierdoPtr = crearNodo(dato);
            }
            else
            {
                insertar(arbol->izquierdoPtr, dato);
            }
        }
        else
        { // Si el dato es mayor que el dato del nodo actual se pasa a la derecha
            if (arbol->derechaPtr == NULL)
            {
                arbol->derechaPtr = crearNodo(dato);
            }
            else
            {
                insertar(arbol->derechaPtr, dato);
            }
        }
    }
}

void postorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        postorden(arbol->izquierdoPtr);
        postorden(arbol->derechaPtr);
        printf("%d\n", arbol->dato);
    }
}

// Funcion para imprimir el arbol en preOrden
void preOrden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        printf("%d\n", arbol->dato);
        preOrden(arbol->izquierdoPtr);
        preOrden(arbol->derechaPtr);
    }
}

void inorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        inorden(arbol->izquierdoPtr);
        printf("%d\n", arbol->dato);
        inorden(arbol->derechaPtr);
    }
}

int contarHojas(struct Nodo *arbol)
{
    // siempre poner validacion primero.
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        if (arbol->izquierdoPtr == NULL && arbol->derechaPtr == NULL)
        {
            return 1; // sirve como contador, se agrega 1. En caso de que no haya subramas.
            // if (arbol->derechaPtr == NULL)
            // {
            //     return 1;
            // }
        }
        else
        {
            return contarHojas(arbol->izquierdoPtr) + contarHojas(arbol->derechaPtr); // se utiliza recursividad en la subrama izquierda y derecha y se suman.
        }
    }
}

int alturaArbol(struct Nodo *arbol)
{
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {                                                     // realiza el recorrido, aqui entre las subramas izquierda y derecha.
        int alturaIzq = alturaArbol(arbol->izquierdoPtr); // se suman sus alturas al recorrerse
        int alturaDer = alturaArbol(arbol->derechaPtr);

        if (alturaIzq > alturaDer) // se utiliza esta comparacion para evitar que se sumen dos nodos de diferentes subramas si estan en el mismo nivel.
        {
            return alturaIzq + 1; // se suma el 1 al contador de alturaIzq, con recursividad ira aumentando si se tiene los datos.
        }
        else
        {
            return alturaDer + 1;
        }
    }
}

/*
Un árbol binario está lleno si todos sus nodos tienen cero o dos hijos. En otras palabras, no hay nodos con solo un hijo.
*/
bool esLleno(struct Nodo *arbol)
{
    if (arbol == NULL)
    {
        return true;
    }
    if ((arbol->izquierdoPtr == NULL && arbol->derechaPtr == NULL) ||
        (arbol->izquierdoPtr != NULL && arbol->derechaPtr != NULL))
    {
        return esLleno(arbol->izquierdoPtr) && esLleno(arbol->derechaPtr);
    }
    else
    {
        return false;
    }
}

/*
Un árbol binario está completo si todos sus niveles, excepto posiblemente el último, están completamente llenos, y todos los nodos del último nivel
están lo más a la izquierda posible.
*/

int main()
{
    int dato[8] = {8, 3, 1, 20, 5, 10, 7, 4};
    int n = 8;
    int i;
    struct Nodo *arbol = crearNodo(dato[0]);
    for (i = 1; i < n; i++)
    {
        insertar(arbol, dato[i]);
    }
    printf("Inorden\n");
    inorden(arbol);
    printf("Preorden\n");
    preOrden(arbol);
    printf("Postorden\n");
    postorden(arbol);
    printf("Hojas del arbol: %d\n", contarHojas(arbol));
    printf("La altura del arbol es de: %d\n", alturaArbol(arbol));
    // ultimas dos, no muy segura.
    if (esLleno(arbol))
    {
        printf("El árbol está lleno.\n");
    }
    else
    {
        printf("El árbol no está lleno.\n");
    }
    // completo era mucho rollo, no enteder.
    return 0;
}