#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int cargarDescripcionServicio(eServicio servicios[], int tamServ,int idServicio , char descripcion[])
{
    int todoOk = 0;
    int flag = 1;

    if(servicios != NULL && tamServ> 0  && descripcion != NULL)
    {
        for(int i = 0; i< tamServ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(descripcion, servicios[i].descripcion);
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

int mostrarServicios(eServicio servicios[], int tamServ)
{
    int todoOk = 0;
    if(servicios != NULL && tamServ > 0)
    {
        system("cls");
        printf("      **** LISTA DE SERVICIOS **** \n");
        printf("--------------------------------------\n");
        printf("  ID        SERVICIOS          PRECIO\n");
        printf("--------------------------------------\n");
        for( int i = 0; i<tamServ ; i++)
        {
            printf(" %d        %-15s   %4d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

int validarIdServicio(int id ,eServicio servicios[], int tamServ)
{
    int todoOk = 0;
    if(servicios != NULL && tamServ>0)
    {
        for(int i =0; i < tamServ ; i++)
        {
            if(servicios[i].id == id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
