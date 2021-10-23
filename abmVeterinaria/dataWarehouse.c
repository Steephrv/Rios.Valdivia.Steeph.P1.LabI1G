#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "mascota.h"


char nombres[10][20] = {"Juan","Pedro","Sofia","Miguel",
                        "Valentina", "Camila ","Andrea",
                        "Luis","Diego" ,"Analia "};


int idColores[10] = {5001, 5002, 5003, 5001, 5002, 5003, 5004, 5002, 5004, 5000};


int idTipos[10] = {1004, 1002, 1000, 1001, 1004, 1003, 1000, 1002, 1000, 1001};
int edades[10] = {18,50,20,24,25,30,19,18,21,25};

char vacunados[10]= {'s','n','n','s','s','n','n','s','s','n'};

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
			lista[i].edad=edades[i];
			lista[i].vacunado=vacunados[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
