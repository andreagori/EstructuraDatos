/*
ANDREA RIVAS GOMEZ, MATRICULA: 372820
ESTRUCTURA DE DATOS, LISTAS ENLAZADAS
EJERCICIO DE CLASE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. CREAR UN STRUCT CON LOS DATOS
typedef struct alumno
{
    char matricula[7];
    char apellidoP[50];
    char apellidoM[50];
    char nombre[50];
} alumno;

// 2. CREAR OTRO STRUCT, CON LA ESTRUCTURA DEL NODO
typedef struct Nodo
{
    alumno alumno;
    struct Nodo *siguiente;
} Nodo;

// 3. CREAR UN STRUCT DE LISTA.
typedef struct Lista
{
    Nodo *cabeza;
} Lista;

// DECLARACION DE FUNCIONES (PROTOTIPOS)
Nodo *crearNodo(alumno *alumno);
void liberarNodo(Nodo *nodo);
void nodoAlPrincipio(Lista *Lista, alumno *alum);
void nodoAlFinal(Lista *lista, alumno *alum);
Nodo *nodoPosicionN(Lista *lista, alumno *alum, int n);
void imprimirLista(Lista *lista);
void eliminarNodo(Lista *lista, int n);

int msgs()
{
    int op;
    printf("------ MENU ------\n");
    printf("[1] NODO AL PRINCIPIO\n");
    printf("[2] NODO AL FINAL\n");
    printf("[3] NODO EN POSICION N\n");
    printf("[4] MOSTRAR LISTA\n");
    printf("[5] ELIMINAR NODO\n");
    printf("[6] LIBERAR NODO\n");
    printf("[0] SALIR\n");
    scanf("%d", &op);
    return op;
}

void menu()
{
    // HACER LISTA VACIA, INICIARLA:
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->cabeza = NULL;

    alumno *alumnoDos = (alumno *)malloc(sizeof(alumno));
    strcpy(alumnoDos->matricula, "372821");
    strcpy(alumnoDos->apellidoP, "Rivas");
    strcpy(alumnoDos->apellidoM, "Gomez");
    strcpy(alumnoDos->nombre, "Teresa");

    alumno *alumnoTres = (alumno *)malloc(sizeof(alumno));
    strcpy(alumnoTres->matricula, "372822");
    strcpy(alumnoTres->apellidoP, "HARO");
    strcpy(alumnoTres->apellidoM, "CALVO");
    strcpy(alumnoTres->nombre, "FERNANDO");

    alumno *alumnoCuatro = (alumno *)malloc(sizeof(alumno));
    strcpy(alumnoCuatro->matricula, "372545");
    strcpy(alumnoCuatro->apellidoP, "SANDEZ");
    strcpy(alumnoCuatro->apellidoM, "ISLAS");
    strcpy(alumnoCuatro->nombre, "DANNA");
    int opcion;

    do
    {
        opcion = msgs();
        switch (opcion)
        {
        case 1:
        {
            // // AGREGAR NODO
            // crearNodo(alumnoUno);
            // printf("EL NODO FUE AGREGADO CORRECTAMENTE");
            // break;
            // NODO AL PRINCIPIO
            nodoAlPrincipio(lista, alumnoDos);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            break;
        }
        case 2:
        {
            // NODO AL FINAL
            nodoAlFinal(lista, alumnoTres);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            break;
        }
        case 3:
        {
            // NODO EN POSICION N
            int n;
            printf("INGRESA LA POSICION: ");
            scanf("%d", &n);
            nodoPosicionN(lista, alumnoCuatro, n);
            printf("EL NODO FUE AGREGADO CORRECTAMENTE\n");
            break;
        }
        case 4:
        {
            // MOSTRAR LISTA
            imprimirLista(lista);
            break;
        }
        case 5:
        {
            // ELIMINAR NODO
            int n;
            printf("INGRESA LA POSICION: ");
            scanf("%d", &n);
            eliminarNodo(lista, n);
            printf("EL NODO FUE ELIMINADO CORRECTAMENTE\n");
            break;
        }
        case 6:
        {
            // LIBERAR NODO
            liberarNodo(lista->cabeza);
            printf("EL NODO FUE LIBERADO CORRECTAMENTE\n");
            break;
        }
        }
    } while (opcion != 0);
    free(alumnoDos);
    free(alumnoTres);
    free(alumnoCuatro);
    free(lista);
}

// INT MAIN
int main()
{
    menu();
    return 0;
}

// 4. ANTES DE CREAR UN NODO, NECESITAS AGREGAR UNO NUEVO
Nodo *crearNodo(alumno *alumno)
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->alumno.matricula, alumno->matricula);
    strcpy(nodo->alumno.apellidoP, alumno->apellidoP);
    strcpy(nodo->alumno.apellidoM, alumno->apellidoM);
    strcpy(nodo->alumno.nombre, alumno->nombre);
    nodo->siguiente = NULL;
    return nodo;
}

// 5. FUNCION PARA LIBERAR NODO.
void liberarNodo(Nodo *nodo)
{
    free(nodo);
}

// 6. FUNCION INSERTAR NODO AL PRINCIPIO DE LA LISTA
void nodoAlPrincipio(Lista *Lista, alumno *alum)
{
    Nodo *nodo = crearNodo(alum);
    nodo->siguiente = Lista->cabeza;
    Lista->cabeza = nodo;
}

// 7. INSERTAR NODO AL FINAL DE LA LISTA
void nodoAlFinal(Lista *lista, alumno *alum)
{
    Nodo *nodo = crearNodo(alum);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *ptr = lista->cabeza;
        while (ptr->siguiente)
        {
            ptr = ptr->siguiente;
        }
        ptr->siguiente = nodo;
    }
}

// 8. INSERTAR UN NODO EN UNA POSICION ESPECIFICA
Nodo *nodoPosicionN(Lista *lista, alumno *alum, int n)
{
    Nodo *nodo = crearNodo(alum);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *ptr = lista->cabeza;
        int posicion = 0;
        while (posicion < n && ptr->siguiente)
        {
            ptr = ptr->siguiente;
            posicion++;
        }
        nodo->siguiente = ptr->siguiente;
        ptr->siguiente = nodo;
    }
    return nodo;
}

void imprimirLista(Lista *lista)
{
    Nodo *ptr = lista->cabeza;
    while (ptr)
    {
        printf("Matricula: %s\n", ptr->alumno.matricula);
        printf("Apellido Paterno: %s\n", ptr->alumno.apellidoP);
        printf("Apellido Materno: %s\n", ptr->alumno.apellidoM);
        printf("Nombre: %s\n", ptr->alumno.nombre);
        printf("--------------------\n");
        ptr = ptr->siguiente;
    }
}

void eliminarNodo(Lista *lista, int n)
{
    Nodo *ptr = lista->cabeza;
    Nodo *temp = NULL;
    if (n == 0)
    {
        temp = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        free(temp);
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->siguiente;
        }
        temp = ptr->siguiente;
        ptr->siguiente = ptr->siguiente->siguiente;
        free(temp);
    }
}