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
