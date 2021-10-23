#include "tipo.h"
#include "color.h"
#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;  //Validar
    int idColor; //Validar
    int edad;
    char vacunado; // "s", "n"
    int isEmpty;   //( “m” manual, “a” automática)
}eMascota;

#endif // MASCOTA_H_INCLUDED

#define ASC 1 //defino para ordenamiento ASCENDENTE
#define DESC 0 // defino para ordenamiento DESCENDENTE

/** \brief Imprime un menu de opciones para el usuario
 *
 * \return char Retorna la opcion elegida por el usuario
 *
 */
char menu();


/** \brief Funcion que inicializa los indices del array mascota en 1
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del array de mascotas
 * \return int retorna 1 si esta todoOk y 0 si fallo
 *
 */
int inicializarMascotas( eMascota lista[],int tam);

/** \brief Funcion que busca un indice libre en el array de mascotas
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del array de mascotas
 * \return int retorna -1 si fallo o retorna el indice si esta todoOk
 *
 */
int buscarLibre(eMascota lista[], int tam);

/** \brief Funcion que sirve para dar de alta una mascota
 *
 * \param lista[] eMascota Array de mascota
 * \param tam int Tamaño del array de mascotas
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int Tamaños del array de tipos
 * \param colores[] eColor Array de colores
 * \param tamCol int Tamaño del Array de colores
 * \param pId int*  puntero al ID de mascotas , el cual recibe un valor y lo devuelve modificado si se pudo dar de alta correctamente
 * \return int  Retorna 1 si esta todoOk y 0 si hubo algun error
 *
 */
int altaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol, int* pId);


/** \brief Funcion que verifica si el ID Ingresado por el usuario corresponde a un ID existente.
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del array de mascotas
 * \param id int ingresado por el usuari
 * \return int Retorna -1 si no se encontro el ID y retorna el indice del ID si se encontro.
 *
 */
int buscarMascotaId(eMascota lista[], int tam, int id);

/** \brief Funcion que sirve para mostrar los datos de una mascota
 *
 * \param unaMascota eMascota Un valor del Array mascota
 * \param tipos[] eTipo Array de tipo
 * \param tamTip int Tamaño del array de tipo
 * \param colores[] eColor  Array de color
 * \param tamCol int Tamaño del array de color
 * \return void NO retorna nada
 *
 */
void mostrarMascota(eMascota unaMascota , eTipo tipos[],int tamTip, eColor colores[], int tamCol);


/** \brief Funcion que sirve para mostrar los datos de todas las mascotas
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del array de mascotas
 * \param tipos[] eTipo Array de tipo
 * \param tamTip int Tamaño del array de tipo
 * \param colores[] eColor Array de colores
 * \param tamCol int Tamaño del array de colores
 * \return int Retorna 1 si esta todoOk y 0 si hubo algun error
 *
 */
int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[],int tamTip , eColor colores[], int tamCol);

/** \brief  Imprime un menu de opciones para el usuario.
 *
 * \return int Retorna la opcion elegida por el usuario
 *
 */
int menuModificarMascota();


/** \brief Funcion para modificar una mascota.
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del Array de mascotas
 * \param tipos[] eTipo Array de tipo
 * \param tamTip int Tamaño del array de tipo
 * \param colores[] eColor Array de colores
 * \param tamCol int Tamaño del array de colores
 * \return int Retorna 1 si esta todoOK o 0 si hubo algun error
 *
 */
int modificarMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol);


/** \brief Funcion para dar de baja una mascota.
 *
 * \param lista[] eMascota Array de mascota
 * \param tam int Tamaño del array de mascotas
 * \param tipos[] eTipo Array de tipo
 * \param tamTip int Tamaño del Array de tipo
 * \param colores[] eColor Array de colores
 * \param tamCol int Tamaño del array de colores
 * \return int Retorna 1 si esta todoOK o 0 si hubo algun error
 *
 */
int bajaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[],int tamCol);

/** \brief Funcion que sirve para ordenar las mascotas por Tipo y nombre. Si los tipos son diferente los ordena por tipo y si son iguales los ordena por nombre. Luego de ordenarlo reemplaza los ID por los nombres correspondientes y los ordena alfabeticamente.
 *
 * \param lista[] eMascota Array de mascota
 * \param tam int tamaño del array de mascota
 * \param orden int parametro de criterio para ordenarlo ascendente o descendentemente
 * \return int  Retorna 1 si esta todoOK o 0 si hubo algun error.
 *
 */
int ordenarMascotasTipoNombre(eMascota lista[], int tam , int orden);


/** \brief Imprime un menu de opciones para el usuario
 *
 * \return int retorna la opcion elegida
 *
 */
int menuOrdenMascotas();


/** \brief Funcion que muestra las mascotas segundo el orden o criterio elegido
 *
 * \param lista[] eMascota Array de Mascotas
 * \param tam int Tamaño del array de mascotas
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int Tamaños del array de tipos
 * \param colores[] eColor Array de colores
 * \param tamCol int tamaño del array de colores
 * \return int Retorna 1 si esta todoOk o 0 si hubo algun error
 *
 */
int informarMascotas(eMascota lista[],int tam,eTipo tipos[],int tamTip, eColor colores[] ,int tamCol);

/** \brief Funcion que carga el tipo de mascota para luego copie la descripcion mediante el id ingresado
 *
 * \param lista[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param idMascota int
 * \param marca[] char
 * \return int Retorna 1 si salio todoOk, 0 si hubo algun error o -1 si no encuentra el tipo con el id que le pasaron
 *
 */
int cargarTipoMascota( eMascota lista[], int tam, eTipo tipos[], int tamTip, int idMascota, char tipo[]);

/** \brief Funcion que carga el color de mascota para luego copie la descripcion mediante el id ingresado
 *
 * \param lista[] eMascota Array de mascotas
 * \param tam int Tamaño del array de mascotas
 * \param colores[] eColor Array de colores
 * \param tamCol int Tamaño del array de colores
 * \param idMascota int parametro del IDmascota
 * \param color[] char parametro de descripcion
 * \return int Retorna 1 si salio todoOk, 0 si hubo algun error o -1 si no encuentra el color con el id que le pasaron
 *
 */
int cargarColorMascota( eMascota lista[], int tam, eColor colores[], int tamCol, int idMascota, char color[] );
