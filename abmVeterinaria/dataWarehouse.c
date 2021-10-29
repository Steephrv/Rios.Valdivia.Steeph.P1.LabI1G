#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "mascota.h"
#include "trabajo.h"
#include "fecha.h"


char nombres[10][20] = {"Juan","Pedro","Sofia","Miguel",
                        "Valentina","Camila","Andrea",
                        "Luis","Diego","Analia"};


int idColores[10] = {5001, 5002, 5003, 5001, 5002, 5003, 5004, 5002, 5004, 5000};


int idTipos[10] = {1004, 1002, 1000, 1001, 1004, 1003, 1000, 1002, 1000, 1001};
int edades[10] = {15,15,6,4,11,10,2,2,3,1};

char vacunados[10]= {'n','n','n','s','s','n','n','s','s','n'};

int hardcodearMascotas(eMascota lista[], int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].nombre , nombres[i]);
			lista[i].idColor= idColores[i];
			lista[i].idTipo=idTipos[i];
			lista[i].edad=edades[i];
			lista[i].vacunado=vacunados[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}

int idMascotas[10]={50000,50001,50002,50003,50004,50005,50006,50007,50008,50009};

int idServicios[10]={20001,20002,20001,20000,20001,20002,20001,20002,20000,20000};

eFecha fechas[10]={{27,12,1991},
                   {26,06,1996},
                   {22,02,2000},
                   {10,01,2001},
                   {07,01,1995},
                   {13,01,1970},
                   {16,10,1964},
                   {27,03,1984},
                   {19,12,1976},
                   {20,8,2007}
                   };

int hardcodearTrabajos(eTrabajo trabajos[], int tamTrab, int cantidad, int* id)
{
    int contador=-1;

	if(trabajos!=NULL && tamTrab>0 && cantidad>=0 && cantidad <= tamTrab && id != NULL)
	{
		contador=0;
		for(int i=0; i<cantidad; i++)
		{
			trabajos[i].id = *id;
			(*id)++;
            trabajos[i].idMascota = idMascotas[i];
			trabajos[i].idServicio = idServicios[i];
			trabajos[i].fecha = fechas[i];
			trabajos[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}




