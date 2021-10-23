#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(eTipo tipos[], int tamTip,int idTipo , char descripcion[])
{
    int todoOk = 0;
    int flag = 1;

    if(tipos != NULL && tamTip> 0  && descripcion != NULL)
    {
        for(int i = 0; i< tamTip; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
                flag =0 ;
                break;
            }
        }
        todoOk = 1;
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int mostrarTipos(eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    if(tipos != NULL && tamTip > 0)
    {
        system("cls");
        printf("    **** LISTA DE TIPOS **** \n");
        printf("-----------------------------\n");
        printf("  ID        DESCRIPCION\n");
        printf("-----------------------------\n");
        for( int i = 0; i < tamTip ; i++)
        {
            printf(" %d        %-15s \n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

int validarIdTipo(int id ,eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    if(tipos != NULL && tamTip > 0)
    {
        for(int i =0; i < tamTip ; i++)
        {
            if(tipos[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
