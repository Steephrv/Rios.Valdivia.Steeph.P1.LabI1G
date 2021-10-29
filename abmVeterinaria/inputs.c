#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"
#include "inputs.h"

int validacionFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if(
        (dia > 0 && dia < 32) &&
        (mes > 0 && mes < 13) &&
        (anio > 0 && anio < 2022)
       )
    {
        todoOk = 1;
    }

    return todoOk;
}

int convertirMayusPrimeraLetra(char vector[], int tam)
{
    int todoOk = 0;
    int i =0;
    strlwr(vector);
    vector[0] = toupper(vector[0]);

    while(vector[i] != '\0')
    {
        if(vector[i] == ' ')
        {
            vector[i+1]= toupper(vector[i+1]);
            todoOk = 1;
        }
        i++;
    }
    return todoOk;
}

int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos)
{
    int todoOk=0;
    char respuesta;

    if(mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c",&respuesta);

        while(respuesta != opcionUno && respuesta != opcionDos )
        {
                printf("%s", mensajeError);
                fflush(stdin);
                scanf("%c",&respuesta);

        }

        *charAValidar = respuesta;
        todoOk=1;
    }
    return todoOk;
}

int tomarIntMxMn(int* number, char* message, char* errorMessage, int minNumber, int maxNumber)
{
	int error = -1;
	int auxInt;

	if(message != NULL && errorMessage != NULL )
	{
		printf("%s", message);
		scanf("%d", &auxInt);

		while(auxInt < minNumber || auxInt > maxNumber)
		{
			printf("%s", errorMessage);
			scanf("%d", &auxInt);
		}

		*number = auxInt;

		error = 0;
	}

    return error;
}
