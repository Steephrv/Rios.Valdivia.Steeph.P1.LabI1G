#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascota.h"
#include "tipo.h"
#include "color.h"


char menu()
{
    char opcion;
    system("cls");
    printf("       ***ABM VETERINARIA*** \n\n");
    printf("A-ALTA MASCOTA\n");
    printf("B-MODIFICAR MASCOTA\n");
    printf("C-BAJA MASCOTA \n");
    printf("D-LISTAR MASCOTAS\n");
    printf("E-LISTAR TIPOS\n");
    printf("F-LISTAR COLORES\n");
    printf("G-LISTAR SERVICIOS\n");
    printf("H-ALTA TRABAJO\n");
    printf("I-LISTAR TRABAJO\n");

    printf("J-SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);



    return opcion;
}


int inicializarMascotas( eMascota lista[],int tam)
{
    int todoOk =0;

    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eMascota lista[], int tam)
{
    int indice= -1;
    if(lista != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

int altaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol, int* pId)
{
    int todoOk=0;
    int indice;
    eMascota auxMascota;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("          *** Alta Mascota ***\n\n");
        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("No hay lugar");
        }
        else
        {
            auxMascota.id = *pId;
            (*pId)++;
            printf("Ingrese nombre de la mascota: \n");
            fflush(stdin);
            gets(auxMascota.nombre);

            mostrarTipos(tipos,tamTip);
            printf("Ingrese el ID del Tipo: \n");
            scanf("%d", &auxMascota.idTipo);

            while(!validarIdTipo(auxMascota.idTipo, tipos, tamTip))
            {
                printf("ERROR. Ingrese el id del tipo correcto: \n");
                scanf("%d", &auxMascota.idTipo);
            }

            mostrarColores(colores,tamCol);
            printf("Ingrese el ID del color: \n");
            scanf("%d", &auxMascota.idColor);
            while(!validarIdColor(auxMascota.idColor, colores, tamCol))
            {
                printf("ERROR, Ingrese el id del color correcto: \n");
                scanf("%d", &auxMascota.idColor);
            }

            printf("Ingrese la edad de su mascota: \n");
            scanf("%d",&auxMascota.edad);

            printf("\nEsta vacunado? (s/n): \n");
            fflush(stdin);
            scanf("%c", &auxMascota.vacunado);
            while(auxMascota.vacunado != 's' && auxMascota.vacunado != 'n')
            {
                printf("\nERROR. Ingrese (s) si esta vacunado o (n)si no lo esta: \n");
                fflush(stdin);
                scanf("%c", &auxMascota.vacunado);
            }

            auxMascota.isEmpty = 0;

            lista[indice] = auxMascota;
            todoOk=1;
        }

    }
    return todoOk;
}

int buscarMascotaId(eMascota lista[], int tam, int id)
{
    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].id == id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void mostrarMascota(eMascota unaMascota , eTipo tipos[],int tamTip, eColor colores[], int tamCol)
{
    char descripTipo[21];
    char descripColor[21];

    if(cargarDescripcionTipo(tipos, tamTip , unaMascota.idTipo, descripTipo)==1 &&
       cargarDescripcionColor(colores,tamCol,unaMascota.idColor,descripColor)==1)
       {
          printf(" %d     %-10s     %-12s        %-10s     %2d      %2c\n",
           unaMascota.id,unaMascota.nombre, descripTipo , descripColor,unaMascota.edad, unaMascota.vacunado);
       }
}


int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[],int tamTip , eColor colores[], int tamCol)
{
    int todoOk=0;;
    int flag=1;
    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 )
    {
        //system("cls");
        printf("                    **** Lista de Mascotas **** \n");
        printf("---------------------------------------------------------------------------\n");
        printf("   ID      NOMBRE          TIPO              COLOR         EDAD    VACUNADO   \n");
        printf("---------------------------------------------------------------------------\n");

        for(int i=0; i< tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMascota(lista[i], tipos, tamTip ,colores, tamCol);
                flag=0;
            }

        }
        if(flag)
        {
           printf("No hay mascotas para mostrar.\n");
        }
        todoOk=1;
    }
    return todoOk;
}


int menuModificarMascota()
{
    int opcion;

    printf(" Que desea modificar?: \n\n");
    printf("1-Tipo \n");
    printf("2-Vacunado \n");
    printf("3-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    eMascota auxMascota;


    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("        *** Modificar Mascota ***\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam, id);

        if(indice == -1)
        {
            printf("El id de la mascota: %d no esta registrado en el sistema.\n", id);
        }

        else
        {
            mostrarMascota(lista[indice],tipos,tamTip, colores, tamCol);
            printf("Confirma modificacion? S/N: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            while ( confirma != 's' && confirma != 'n')
                {
                    printf("ERROR...Confirma modificacion? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }

            if(confirma == 's')
            {
                do
                {
                    switch(menuModificarMascota())
                    {
                        case 1:

                            mostrarTipos(tipos, tamTip);
                            printf("*** MODIFICAR ID TIPO *** \n");
                            printf("Ingrese nuevo ID tipo: \n");
                            scanf("%d", &auxMascota.idTipo);
                            lista[indice].idTipo = auxMascota.idTipo;

                            break;
                        case 2:

                            printf("Ingrese nuevo (s/n) de vacunacion: \n");
                            scanf("%c", &auxMascota.vacunado);
                            lista[indice].vacunado = auxMascota.vacunado;
                            break;

                        case 3:
                            printf("Ha seleccionado salir\n");
                            confirma='n';
                            break;

                        default:
                            printf("Opcion invalida!!!\n");

                    }
                    system("pause");
                }while(confirma == 's');

                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}


int bajaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[],int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("                               *** Baja Mascota ***\n\n");
        mostrarMascotas (lista , tam,tipos ,tamTip , colores, tamCol);
        printf("\nIngrese id: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam, id);

        if(indice == -1)
        {
            printf("El id mascota: %d no esta registrado en el sistema.\n", id);
        }
        else
        {
            mostrarMascota(lista[indice],tipos,tamTip, colores, tamCol);
            printf(" Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            while ( confirma != 's' && confirma != 'n')
                {
                    printf("ERROR...Confirma baja? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}

int ordenarMascotasTipoNombre(eMascota lista[], int tam , int orden)
{
    int todoOk=0;
    eMascota auxMascota;

    if(lista != NULL && tam > 0 && orden >= 0 && orden <= 1)
    {
        for(int i = 0; i<tam-1; i++)
        {
            for(int j = i + 1; j<tam; j++)
            {
                if(((lista[i].idTipo == lista[j].idTipo  && strcmp(lista[i].nombre, lista[j].nombre)> 0 &&  orden ) || (lista[i].idTipo == lista[j].idTipo  && strcmp(lista[i].nombre, lista[j].nombre)< 0 &&  !orden))
                   || ((lista[i].idTipo != lista[j].idTipo && lista[i].idTipo > lista[j].idTipo  && orden ) || (lista[i].idTipo != lista[j].idTipo && lista[i].idTipo < lista[j].idTipo  && !orden)))
                {
                    auxMascota = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMascota;
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int menuOrdenMascotas()
{
    int opcion;

    printf(" \nQue opcion desea?: \n\n");
    printf("1-Mostrar lista mascotas ordenados ascendente (tipo-nombre) \n");
    printf("2-Mostrar lista mascotas ordenados descendente (tipo-nombre) \n");
    printf("3-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informarMascotas(eMascota lista[],int tam,eTipo tipos[],int tamTip, eColor colores[] ,int tamCol)
{
    int todoOk = 0;
    char confirm;

    if(lista != NULL && tam > 0)
    {
        do
        {
            switch(menuOrdenMascotas())
            {
                case 1:
                    ordenarMascotasTipoNombre(lista,tam,ASC);
                    mostrarMascotas(lista,tam ,tipos,tamTip,colores,tamCol);
                    printf("\nOrdenamiento exitoso!!\n");

                    break;

                case 2:
                    ordenarMascotasTipoNombre(lista,tam,DESC);
                    mostrarMascotas(lista,tam ,tipos,tamTip,colores,tamCol);
                    printf("\nOrdenamiento exitoso!!\n");
                    break;

                case 3:
                    printf("Ha seleccionado salir\n");
                    confirm = 'n';
                    break;

                default:
                    printf("Opcion invalida!!!\n");

            }
            system("pause");
        }while(confirm == 's');
        todoOk=1;
    }
    return todoOk;
}

int cargarTipoMascota( eMascota lista[], int tam, eTipo tipos[], int tamTip, int idMascota, char tipo[])
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && tipo != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMascota)
            {
                cargarDescripcionTipo(tipos, tamTip, lista[i].idTipo, descripcion);
                strcpy(tipo, descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no hay tipo con el id que le pasaron
        }
    }
    return todoOk;
}

int cargarColorMascota( eMascota lista[], int tam, eColor colores[], int tamCol, int idMascota, char color[] )
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && color != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMascota)
            {
                cargarDescripcionColor(colores, tamCol, lista[i].idColor, descripcion);
                strcpy(color, descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}





