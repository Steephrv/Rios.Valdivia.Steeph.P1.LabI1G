#include "mascota.h"
#include "fecha.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id; //(autoincremental)
    int idMascota; // Validar
    int idServicio; // Validar
    eFecha fecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

/** \brief Funcion que inicializa todos los indices del array trabajos en 1.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \return int Retorna 1 si esta todoOK o 0 si hubo algun error
 *
 */
int inicializarTrabajos( eTrabajo trabajos[],int tamTrab);


/** \brief Funcion que busca un indice libre en el array de trabajos.
 *
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTrab int Tamaño del array de trabajos.
 * \return int Retorna -1 si hubo algun error o el indice si esta todoOK.
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab);


/** \brief Funcion para dar de alta un trabajo.
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTrab int tamaño del array de trabajos
 * \param lista[] eMascota array de mascotas
 * \param tam int tamaño del array de mascotas
 * \param tipos[] eTipo array de tipo
 * \param tamTip int Tamaño del array de tipos.
 * \param colores[] eColor array de colores
 * \param tamCol int tamaño del array de colores
 * \param servicios[] eServicio array de servicios
 * \param tamServ int tamaño del array de servicios
 * \param pIdTrabajo int* Puntero al ID de trabajos el cual recibe un valor y lo devuelve modificado si se pudo dar de alta correctamente el trabajo.
 * \return int Retorna 1 si esta todoOK o 0 si hubo algun error.
 *
 */
int altaTrabajos(eTrabajo trabajos[], int tamTrab, eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol,eServicio servicios[],int tamServ, int* pIdTrabajo);
void mostrarTrabajo(eTrabajo unTrabajo, eMascota lista[], int tam, eServicio servicios[], int tamServ , eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int mostrarTrabajos(eTrabajo trabajos[], int tamTrab,eMascota lista[], int tam, eServicio servicios[], int tamServ , eTipo tipos[], int tamTip, eColor colores[], int tamCol);
