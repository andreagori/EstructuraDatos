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
Para insertar del lado derecho, no halla nada. Si no hay nada ahi se insertara, si hay algo
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

int contarNodos(struct Nodo *arbol)
{
    if (arbol == NULL)
    {
        return 0;
    }

    return contarNodos(arbol->izquierdoPtr) + contarNodos(arbol->derechaPtr) + 1;
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
Un arbol completo es el cual donde esta mas apoyado en el arbol izquierdo.
Un árbol binario está completo si todos sus niveles, excepto posiblemente el último, están completamente llenos, y todos los nodos del último nivel
están lo más a la izquierda posible.
*/
bool completo(struct Nodo *arbol)
{
    if (arbol == NULL)
    {
        return true;
    }
    // Usare las otras funciones que hice para saber si el arbol esta completo.
    int altura = alturaArbol(arbol);
    int nodos = contarNodos(arbol);

    // Formula que te ayuda a revisar si el arbol esta completo de acuerdo a su altura y nodos totales.
    return nodos == (1 << altura) - 1; // (2^h - 1) El desplazamiento de bits se utiliza para calcular 2^h., dos elevado a la altura del arbol menos 1.
};

// Un arbol balanceado es aquel que tiene la misma cantidad de nodos en su subarbol izquierdo y derecho.
bool arbolBalanceado(struct Nodo *arbol)
{
    // si la diferencia es mayor a 1, no esta balanceado. Y tambien si es menor a -1.
    if (arbol == NULL)
    {
        return true;
    }
    int alturaIzq = alturaArbol(arbol->izquierdoPtr);
    int alturaDer = alturaArbol(arbol->derechaPtr);

    int diferencia = (alturaDer - alturaIzq);
    if (diferencia > 1 || diferencia < -1)
    {
        return false;
    }
    else
    {
        return true;
    }
    // return arbolBalanceado(arbol->izquierdoPtr) && arbolBalanceado(arbol->derechaPtr);
}

struct Nodo *EncontrarMinimo(struct Nodo *nodo)
{
    struct Nodo *actual = nodo;
    while (actual->izquierdoPtr != NULL)
    {
        actual = actual->izquierdoPtr;
    }
    return actual;
}

struct Nodo *BorrarNodo(struct Nodo *nodo, int valor)
{
    if (nodo == NULL)
    {
        return nodo;
    }
    if (valor < nodo->dato)
    {
        nodo->izquierdoPtr = BorrarNodo(nodo->izquierdoPtr, valor);
    }
    else
    {
        if (valor > nodo->dato)
        {
            nodo->derechaPtr = BorrarNodo(nodo->derechaPtr, valor);
        }
        else
        {
            // caso 1: Un solo hijo o ningun hijo.
            if (nodo->izquierdoPtr == NULL)
            {
                struct Nodo *temp = (struct Nodo *)malloc(sizeof(struct Nodo));
                temp = nodo->derechaPtr;
                free(nodo);
                return temp;
            }
            else
            {
                if (nodo->derechaPtr == NULL)
                {
                    struct Nodo *temp = (struct Nodo *)malloc(sizeof(struct Nodo));
                    temp = nodo->izquierdoPtr;
                    free(nodo);
                    return temp;
                }
            }
            // caso 2: Dos hijos.
            struct Nodo *temp = EncontrarMinimo(nodo->derechaPtr);
            nodo->dato = temp->dato;
            nodo->derechaPtr = BorrarNodo(nodo->derechaPtr, temp->dato);
            
        }
    }
    return nodo;
}

int main()
{
    // Se esta insertando en orden BST. (arbol binario de busqueda), el orden de datos importa.
    /*
     todos los elementos en su subárbol izquierdo son menores que el nodo, y todos los
     elementos en su subárbol derecho son mayores que el nodo.
    */
    // int dato[8] = {8, 3, 1, 20, 5, 10, 7, 4};4, 2, 7 | 1, 2, 3, 4, 5
    int dato_completo[8] = {8, 3, 1, 20, 5, 10, 7, 4};
    int n = 8; // cambiar el n.
    int i;
    struct Nodo *arbol = crearNodo(dato_completo[0]);
    for (i = 1; i < n; i++)
    {
        insertar(arbol, dato_completo[i]);
    }
    printf("Inorden\n");
    inorden(arbol);
    printf("Preorden\n");
    preOrden(arbol);
    printf("Postorden\n");
    postorden(arbol);
    printf("Hojas del arbol: %d\n", contarHojas(arbol));
    printf("La altura del arbol es de: %d\n", alturaArbol(arbol));
    // Si el arbol esta lleno o no.
    if (esLleno(arbol))
    {
        printf("El arbol esta lleno.\n");
    }
    else
    {
        printf("El arbol no esta lleno.\n");
    }
    // revisar el completo.
    if (completo(arbol))
    {
        printf("El arbol esta completo.\n");
    }
    else
    {
        printf("El arbol no esta completo.\n");
    }
    // Revisar si el arbol esta balanceado.
    if (arbolBalanceado(arbol))
    {
        printf("El arbol esta balanceado.\n");
    }
    else
    {
        printf("El arbol no esta balanceado.\n");
    }
    // Borrar un nodo.
    arbol = BorrarNodo(arbol, 20);
    printf("Inorden\n");
    inorden(arbol);

    free(arbol);
    return 0;
}