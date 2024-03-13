/*
Andrea Rivas Gomez, matricula: 372820
Ejercicio de colas
Fecha de creacion: 08/marzo/2024
Modificaciones: 12/marzo/2024.

*/

#include <stdio.h>
#include <stdlib.h>

// STRUCTS

typedef struct numeros // este struct no es necesario, pero asi lo aprendere.
{
    int numero;
} Numeros;

typedef struct nodo
{
    Numeros *dato;
    struct nodo *siguiente;
} Nodo;

typedef struct pila
{
    Nodo *frente;
    int longitud;
} Pila;

// DECLARACION Y PROTOTIPOS DE FUNCIONES
int msgs();
void menu();

Pila *crearPila();
void destruirPila(Pila *pila);
Nodo *crearNodo(Numeros digito);
void destruirNodo(Nodo *nodo);

void insertar(Pila *pilita, Numeros digito);
void eliminarPilita(Pila *pilita);
Pila topPila(Pila *pilita);
int longitudPila(Pila *pilita);
int vacia();

int main()
{
    menu();
    return 0;
}

int msgs()
{
    int opc;
    printf("----- MENU -----\n");
    printf("[1] Insertar\n");
    printf("[2] Eliminar\n");
    printf("[3] Mostrar top de la pila\n");
    printf("[4] Mostrar longitud de la pila\n");
    printf("[5] Pila vacia?\n");
    printf("[6] Salir\n");
    scanf("%d", &opc);
    return opc;
}

void menu()
{
    int op;
    Pila *pilita = crearPila();

    do
    {
        op = msgs();

        switch (op)
        {
        case 1:
        {
            Numeros num;
            printf("Insertar numero a la pila\n");
            printf("Ingresa un elemento a la pila (numero)\n");
            // Intenta leer un número
            if (scanf("%d", &(num.numero)) == 1)
            {
                // La lectura fue exitosa, llama a la función insertar
                insertar(pilita, num);
                printf("Numero insertado correctamente.\n");
            }
            else
            {
                // La entrada no es un número válido
                printf("Por favor ingresa un numero.\n");
                // Limpia el búfer de entrada para evitar bucles infinitos
                while (getchar() != '\n')
                    ;
            }
            system("PAUSE");
            system("CLS");
            break;
        }
        case 2:
        {
            printf("Eliminar\n");
            eliminarPilita(pilita); // eliminar el ultimo nodo agregado, el top.
            printf("El elemento ha sido eliminado\n");
            system("PAUSE");
            system("CLS");
            break;
        }
        case 3:
        {
            printf("Mostrar el top de la pila\n");
            topPila(pilita);
            system("PAUSE");
            system("CLS");
            break;
        }
        case 4:
        {
            printf("Longitud de la pila\n");
            longitudPila(pilita);
            system("PAUSE");
            system("CLS");
            break;
        }
        case 5:
        {
            printf("La pila esta vacia?\n");
            vacia(pilita);
            system("PAUSE");
            system("CLS");
            break;
        }
            destruirPila(pilita);
        }
    } while (op != 6);
}

// FUNCIONES
Pila *crearPila()
{
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    pila->frente = NULL;
    pila->longitud = 0;
    return pila;
}

void destruirPila(Pila *pila)
{
    while (pila->frente != NULL)
    {
        eliminarPilita(pila);
    }
    free(pila);
}

Nodo *crearNodo(Numeros digito)
{
    Nodo *elemento = (Nodo *)malloc(sizeof(Nodo));
    elemento->dato = (Numeros *)malloc(sizeof(Numeros)); // Asigna memoria para el dato del nodo
    elemento->dato->numero = digito.numero;              // Copia el número al dato del nodo
    elemento->siguiente = NULL;
    return elemento;
}

void destruirNodo(Nodo *nodo)
{
    nodo->siguiente = NULL;
    free(nodo);
}

void insertar(Pila *pilita, Numeros digito)
{
    Nodo *elemento = crearNodo(digito);
    elemento->siguiente = pilita->frente;
    pilita->frente = elemento;
    pilita->longitud++;
    // primero se apunta a las direcciones y despues en la direccion
    // se coloca los datos, que estan almacenados en elemento/nodo.
}

void eliminarPilita(Pila *pilita)
{
    if (pilita->frente != NULL)
    {
        Nodo *eliminar = pilita->frente;
        // despues de crear nuestro nodo eliminar, hacemos que el
        // frente de la pila ahora apunte al siguiente.
        pilita->frente = pilita->frente->siguiente;
        pilita->longitud--;
        // destruimos el nodo
        destruirNodo(eliminar);
    }
    else
    {
        printf("No tienes nada en tu pila\n");
    }
}

Pila topPila(Pila *pilita)
{
    if (pilita->frente == NULL)
    {
        printf("No tienes nada en tu pila\n");
        return *pilita;
    }
    printf("El top de tu pila es: %d\n", pilita->frente->dato->numero);
    return *pilita;
}

int longitudPila(Pila *pilita)
{
    printf("La longitud de tu pila es:%d\n", pilita->longitud);
    return pilita->longitud;
}

int vacia(Pila *pilita)
{
    if (pilita->longitud != 0)
    {
        printf("Tu pila no esta vacia y tiene %d\n", pilita->longitud);
    }
    else
    {
        printf("Tu pila esta vacia\n");
        return pilita->longitud == 0;
    }
}