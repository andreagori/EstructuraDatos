/*
ANDREA RIVAS GOMEZ, Matricula: 372820
Practica 1: Listas Enlazadas. No cuenta, prueba de conocimientos previos
Fecha de creacion: 05 febrero 2024
Ultima modificacion: 05 febrero 2024
Instrucciones:
programar las operaciones básicas de una lista enlazada, es decir, crear la lista,
insertar un elemento al inicio de la lista, al final de la lista, en una posición específica,
borrar un elemento de la lista, etc.

POSDATA: NO SE SI ESTA BIEN EL CODIGO, NO LO COMPRENDI MUY BIEN. ME APOYE DE INTERNET PARA HACERLO. PORQUE NO RECORDABA
COMO SE HACIA, EN ESPECIAL CON LOS APUNTADORES Y PUNTEROS. ESPERO PODER ESCUCHAR ESTE TEMA EN CLASES, 
ESTOY SEGURA QUE ME AYUDARA A ENTENDERLO MEJOR CON SU APOYO. GRACIAS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    char Matricula[6];
    char Nombre[20];
    char ApellidoP[20];
    char ApellidoM[20];
    // APUNTADOR, DE AUTOREFERENCIA.
    struct nodo *siguiente;
} Nodo;

// DECLARACION DE FUNCIONES. (Revisar esto)
Nodo **crearLista(Nodo **lista);
void insertarInicio(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[]);
void insertarFinal(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[]);
void insertarPosicion(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[], int posicion);
void borrarNodo(Nodo **lista, int posicion);


int main()
{
    int op;
    do
    {
        printf("BIENVENIDOS AL PROGRAMA\n");
        printf("MENU DE OPCIONES\n");
        printf("[1] Crear lista\n");
        printf("[2] Insertar nodo al inicio\n");
        printf("[3] Insertar nodo al final\n");
        printf("[4] Insertar nodo en una posicion especifica\n");
        printf("[5] Borrar nodo\n");
        printf("[6] Salir\n");
        printf("ELIGE UNA OPCION: \n");
        scanf("%d", &op);

        switch (op)
        {
            // DECLARACION DE VARIABLES A USAR
            Nodo *lista;
            char matricula[6];
            char nombre[20];
            char apellidoP[20];
            char apellidoM[20];
        case 1:
        {
            printf("Crear lista\n");
            crearLista(&lista);
            printf("%p\n", lista);
            printf("LA LISTA HA SIDO CREADA\n");
            break;
        }
        case 2:
        {
            printf("Insertar nodo al inicio\n");
            printf("Ingresa la matricula: ");
            scanf("%s", matricula);
            printf("Ingresa el nombre: ");
            scanf("%s", nombre);
            printf("Ingresa el apellido paterno: ");
            scanf("%s", apellidoP);
            printf("Ingresa el apellido materno: ");
            scanf("%s", apellidoM);
            insertarInicio(&lista, matricula, nombre, apellidoP, apellidoM);
            printf("Nodo insertado al inicio\n");
            printf("%p\n", lista);
            break;
        }
        case 3:
        {
            printf("Insertar nodo al final\n");
            printf("Ingresa la matricula: ");
            scanf("%s", matricula);
            printf("Ingresa el nombre: ");
            scanf("%s", nombre);
            printf("Ingresa el apellido paterno: ");
            scanf("%s", apellidoP);
            printf("Ingresa el apellido materno: ");
            scanf("%s", apellidoM);
            insertarFinal(&lista, matricula, nombre, apellidoP, apellidoM);
            break;
        }
        case 4:
        {
            printf("Insertar nodo en una posicion especifica\n");
            printf("Insertar nodo al final\n");
            printf("Ingresa la matricula: ");
            scanf("%s", matricula);
            printf("Ingresa el nombre: ");
            scanf("%s", nombre);
            printf("Ingresa el apellido paterno: ");
            scanf("%s", apellidoP);
            printf("Ingresa el apellido materno: ");
            scanf("%s", apellidoM);
            int posicion;
            printf("Ingresa la posicion: ");
            scanf("%d", &posicion);
            insertarPosicion(&lista, matricula, nombre, apellidoP, apellidoM, posicion);
            break;
        }
        case 5:
        {
            printf("Borrar nodo\n");
            break;
        }
        case 6:
        {
            printf("Salir\n");
            break;
        }
        default:
        {
            printf("Opcion no valida\n");
            system("PAUSE");
            break;
        }
            return 0;
        }
    } while (op != 6);
}

// FUNCION PARA CREAR UNA LISTA
Nodo **crearLista(Nodo **lista) // CON EL DOBLE PUNTERO, ME ASEGURO DE QUE LA LISTA SE PUEDA MODIFICAR FUERA DE LA FUNCION.
{
    *lista = NULL;
    return lista;
}

// FUNCION PARA INSERTAR UN NODO AL INICIO DE LA LISTA. (Revisar esto).
void insertarInicio(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[])
{
    Nodo *alInicio = (Nodo *)malloc(sizeof(Nodo));
    if (alInicio == NULL)
    {
        printf("No hay memoria disponible\n");
        return;
    }
    strcpy(alInicio->Matricula, matricula);
    strcpy(alInicio->Nombre, nombre);
    strcpy(alInicio->ApellidoP, apellidoP);
    strcpy(alInicio->ApellidoM, apellidoM);
    alInicio->siguiente = *lista;
    *lista = alInicio;
}

// FUNCION PARA INSERTAR UN NODO AL FINAL DE LA LISTA (Revisar esto).
void insertarFinal(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[])
{
    Nodo *alFinal = (Nodo *)malloc(sizeof(Nodo));
    if (alFinal == NULL)
    {
        printf("No hay memoria disponible\n");
        return;
    }
    strcpy(alFinal->Matricula, matricula);
    strcpy(alFinal->Nombre, nombre);
    strcpy(alFinal->ApellidoP, apellidoP);
    strcpy(alFinal->ApellidoM, apellidoM);
    // AL FINAL DE LA LISTA, EL SIGUIENTE NODO ES NULL.
    alFinal->siguiente = NULL;
    if (*lista == NULL)
    {
        *lista = alFinal;
    }
    else
    {
        // RECORRER LA LISTA HASTA LLEGAR AL FINAL. (Revisar esto). no comprendi bien.
        Nodo *aux = *lista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = alFinal;
    }
}

// FUNCION PARA INSERTAR UN NODO EN UNA POSICION ESPECIFICA (Revisar esto).
void insertarPosicion(Nodo **lista, char matricula[], char nombre[], char apellidoP[], char apellidoM[], int posicion)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL)
    {
        printf("No hay memoria disponible\n");
        return;
    }
    strcpy(nuevo->Matricula, matricula);
    strcpy(nuevo->Nombre, nombre);
    strcpy(nuevo->ApellidoP, apellidoP);
    strcpy(nuevo->ApellidoM, apellidoM);
    nuevo->siguiente = NULL;
    if (posicion == 1)
    {
        nuevo->siguiente = *lista;
        *lista = nuevo;
    }
    else
    {
        Nodo *aux = *lista;
        int i = 1;
        while ((i < (posicion - 1)) && (aux->siguiente != NULL))
        {
            aux = aux->siguiente;
            i++;
        }
        if (i != (posicion - 1))
        {
            printf("La posicion no existe\n");
            return;
        }
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
    }
}

// FUNCION PARA BORRAR UN NODO DE LA LISTA (Revisar esto).
void borrarNodo(Nodo **lista, int posicion)
{
    if (*lista == NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Nodo *aux = *lista;
    if (posicion == 1)
    {
        *lista = aux->siguiente;
        free(aux);
    }
    else
    {
        int i = 1;
        // RECORRER LA LISTA HASTA LLEGAR A LA POSICION ANTERIOR A LA QUE SE DESEA BORRAR.
        while ((i < (posicion - 1)) && (aux->siguiente != NULL))
        {
            aux = aux->siguiente;
            i++;
        }
        if (i != (posicion - 1))
        {
            printf("La posicion no existe\n");
            return;
        }
        // BORRAR EL NODO DE LA LISTA.
        Nodo *borrar = aux->siguiente;
        aux->siguiente = borrar->siguiente;
        free(borrar);
    }
}