#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "mascota.h"
#include "servicio.h"
#include "inputs.h"

int inicializarTrabajos( eTrabajo trabajos[],int tamTrab)
{
    int todoOk =0;

    if(trabajos != NULL && tamTrab > 0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab)
{
    int indice= -1;
    if(trabajos != NULL && tamTrab > 0)
    {
       for(int i=0; i<tamTrab; i++)
        {
            if(trabajos[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int altaTrabajos(eTrabajo trabajos[], int tamTrab, eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol,eServicio servicios[],int tamServ, int* pIdTrabajo)
{
    int todoOk=0;
    int indice;
    eTrabajo auxTrabajo;

    if(trabajos != NULL && tamTrab > 0 && pIdTrabajo && lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol >0 && servicios != NULL && tamServ >0)
    {
        system("cls");
        printf("          *** Alta Trabajo ***\n\n");
        indice = buscarLibreTrabajo(trabajos,tamTrab);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema");
        }
        else
        {
            auxTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;

            mostrarServicios(servicios,tamServ);
            printf("Ingrese ID servicio: \n");
            scanf("%d",&auxTrabajo.idServicio);
            while(!validarIdServicio (auxTrabajo.idServicio, servicios ,tamServ))
            {
                printf("\nID servicio invalido,  Ingrese id servicio correcto: \n");
                scanf("%d",&auxTrabajo.idServicio);
            }

            mostrarMascotas( lista , tam , tipos, tamTip,colores, tamCol);
            printf("Ingrese ID mascota: \n");
            scanf("%d",&auxTrabajo.idMascota);
            while(buscarMascotaId(lista ,tam, auxTrabajo.idMascota) == -1)
            {
                printf("\nID mascota invalida,  Ingrese id mascota correcta: \n");
                scanf("%d",&auxTrabajo.idMascota);
            }

            printf("Ingrese fecha (dd/mm/aaaa): \n");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            while(!validacionFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio))
                {
                    printf("Error. Ingrese una fecha valida (dd/mm/aaaa): ");
                    scanf("%d/%d/%d", &auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
                }

            auxTrabajo.isEmpty = 0;

            trabajos[indice] = auxTrabajo;
            todoOk=1;
        }

    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eMascota lista[], int tam, eServicio servicios[], int tamServ , eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    char descripServ[25];
    char descripMarca[20];
    char descripColor[20];

    if(cargarDescripcionServicio(servicios, tamServ , unTrabajo.idServicio, descripServ) ==1 &&
       cargarTipoMascota(lista, tam, tipos, tamTip, unTrabajo.idMascota, descripMarca) ==1  &&
       cargarColorMascota(lista, tam, colores, tamCol, unTrabajo.idMascota,descripColor)==1 )
       {
           printf(" %d       %-15s  %-15s   %-15s   %2d/%2d/%d \n",
           unTrabajo.id, descripServ , descripMarca,descripColor, unTrabajo.fecha.dia , unTrabajo.fecha.mes, unTrabajo.fecha.anio);
       }
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTrab,eMascota lista[], int tam, eServicio servicios[], int tamServ , eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk=0;;
    int flag=1;
    if(trabajos != NULL && tamTrab > 0 && lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && servicios != NULL && tamServ > 0)
    {
        system("cls");
        printf("                    **** Lista de Trabajos **** \n");
        printf("---------------------------------------------------------------------------\n");
        printf(" ID       SERVICIO         TIPO              COLOR                Fecha \n");
        printf("---------------------------------------------------------------------------\n");

        for(int i=0; i< tam ; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i],lista,tam ,servicios, tamServ,tipos, tamTip, colores, tamCol);
                flag=0;
            }
        }
        if(flag)
        {
           printf("No hay trabajos para mostrar.\n");
        }
        todoOk=1;
    }
    return todoOk;
}
