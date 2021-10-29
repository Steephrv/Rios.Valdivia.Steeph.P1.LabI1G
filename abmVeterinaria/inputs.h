#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief Funcion para validad fecha
 *
 * \param dia int parametro de dia
 * \param mes int parametro de mes
 * \param anio int parametro de anio
 * \return int retorna 1 si esta todoOk o 0 si hubo algun error.
 *
 */
int validacionFecha(int dia, int mes, int anio);

/** \brief funcion que permite convertir la primera letra de cada palabra en mayuscula
 *
 * \param vector[] char array de vector
 * \param tam int tama�o del array
 * \return int retorna 1 si esta todoOk o 0 si hubo algun error
 *
 */
int convertirMayusPrimeraLetra(char vector[], int tam);

int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);
int tomarIntMxMn(int* number, char* message, char* errorMessage, int minNumber, int maxNumber);
