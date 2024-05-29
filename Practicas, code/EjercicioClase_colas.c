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
int front(Cola *colita);
void printColita(Cola *colita);
void isEmpty(Cola *colita);
int size(Cola *colita);
void clear(Cola *colita);

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
        colita->ultimo = NULL;
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

    // liberamos memoria del nodo eliminado
    free(nodoBorrar);
    // se devuelve el valor eliminado ya que es util para el usuario al saber que
    // valor ha sido borrado.
    return valor;
}

// Funcion para ver el primer elemento de la cola sin eliminarlo:
int front(Cola *colita)
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

void isEmpty(Cola *colita)
{
    // si el primero de la cola es null, entonces la cola esta vacia.
    if (colita->primero == NULL)
    {
        printf("LA COLA ESTA VACIA\n");
    }
    else
    {
        printf("LA COLA NO ESTA VACIA\n");
    }
}

int size(Cola *colita)
{
    // creamos un nodo que apuntara al primero de la cola.
    Nodo *actual = colita->primero;
    int contador = 0;
    // mientras actual no sea null (verifica tambien que la cola no este vacia).
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void clear(Cola *colita)
{
    // creamos un nodo que apuntara al primero de la cola.
    Nodo *actual = colita->primero;
    // mientras actual no sea null (verifica tambien que la cola no este vacia).
    while (actual != NULL)
    {
        // creamos un nodo que apuntara al siguiente del nodo actual.
        Nodo *nodoBorrar = actual;
        actual = actual->siguiente;
        // liberamos memoria del nodo eliminado
        free(nodoBorrar);
    }
    // hacemos que el primero y el ultimo apunten a null.
    colita->primero = NULL;
    colita->ultimo = NULL;
    printf("LA COLA HA SIDO VACIADA\n");
}

int msgs()
{
    system("CLS");
    int op;
    printf("----- MENU ----- \n");
    printf("[1] AGREGAR ELEMENTOS A LA COLA\n");
    printf("[2] ELIMINAR ELEMENTOS DE LA COLA\n");
    printf("[3] VER EL PRIMER ELEMENTO DE LA COLA\n");
    printf("[4] VER TODOS LOS ELEMENTOS DE LA COLA\n");
    printf("[5] VERIFICAR SI LA COLA ESTA VACIA\n");
    printf("[6] VER EL TAMANO DE LA COLA\n");
    printf("[7] VACIAR LA COLA\n");
    printf("[8] SALIR\n");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    Cola colaa = {NULL, NULL}; // hacemos que tanto el primero como el ultimo apunten a null.
    do
    {
        op = msgs();
        switch (op)
        {
        case 1:
        {
            // Agregamos elemento a la cola
            int num;
            printf("Cuantos elementos deseas agregar a la cola: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                int num2;
                printf("Ingresa el elemento %d: ", i + 1);
                scanf("%d", &num2);
                enqueue(&colaa, num2);
            }
            system("PAUSE");
            break;
        }
        case 2:
        {
            // eliminar el primer elemento de la cola.
            printf("ELEMENTO DE LA COLA ELIMINADA:\n %d\n", dequeue(&colaa));
            system("PAUSE");
            break;
        }
        case 3:
        {
            // ver el primer elemento de la cola
            printf("VER EL PRIMER ELEMENTO DE LA COLA SIN BORRARLO:\n %d\n", front(&colaa));
            system("PAUSE");
            break;
        }
        case 4:
        {
            // ver todos los elementos de la cola.
            printf("COLA COMPLETA:\n");
            printColita(&colaa);
            system("PAUSE");
            break;
        }
        case 5:
        {
            // verificar si la cola esta vacia.
            isEmpty(&colaa);
            system("PAUSE");
            break;
        }
        case 6:
        {
            // ver el tamano de la cola.
            printf("TAMANO DE LA COLA: %d\n", size(&colaa));
            system("PAUSE");
            break;
        }
        case 7:
        {
            // vaciar la cola.
            clear(&colaa);
            system("PAUSE");
            break;
        }
        case 8:
        {
            printf("SALIENDO DEL PROGRAMA\n");
            break;
        }
        }
    } while (op != 8);
}

// USARLO.
int main()
{
    menu();
    return 0;
    // Cola colaa = {NULL, NULL}; // hacemos que tanto el primero como el ultimo apunten a null.
    // // Agregamos elemento a la cola
    // enqueue(&colaa, 1);
    // enqueue(&colaa, 2);
    // enqueue(&colaa, 6);
    // enqueue(&colaa, 7);

    // printf("COLA COMPLETA:\n");
    // printColita(&colaa);
    // // eliminar el primer elemento de la cola.
    // // ver el primer elemento de la cola
    // printf("ELEMENTO DE LA COLA ELIMINADA:\n %d\n", dequeue(&colaa));
    // printf("NUEVO ELEMENTO SIENDO EL PRIMERO DE LA COLA: \n %d\n", front(&colaa));
    // printf("COLA COMPLETA SIN EL ELEMENTO ELIMINADO: \n");
    // printColita(&colaa);
    // printf("TAMANO DE LA COLA: %d\n", size(&colaa));
    // isEmpty(&colaa);
    // clear(&colaa);
    // isEmpty(&colaa);
}