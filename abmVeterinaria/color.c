#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int cargarDescripcionColor(eColor colores[], int tamCol,int idColor , char nombreColor[])
{
    int todoOk = 0;
    int flag = 1;

    if(colores != NULL && tamCol> 0  && nombreColor != NULL)
    {
        for(int i = 0; i< tamCol; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(nombreColor, colores[i].nombreColor);
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

int mostrarColores(eColor colores[], int tamCol)
{
    int todoOk = 0;
    if(colores != NULL && tamCol > 0)
    {
        system("cls");
        printf("    **** LISTA DE COLORES **** \n");
        printf("-----------------------------\n");
        printf("  ID        COLORES\n");
        printf("-----------------------------\n");
        for( int i = 0; i<tamCol ; i++)
        {
            printf(" %d        %-15s \n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

int validarIdColor(int id ,eColor colores[], int tamCol)
{
    int todoOk = 0;
    if(colores != NULL && tamCol>0)
    {
        for(int i =0; i < tamCol ; i++)
        {
            if(colores[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
