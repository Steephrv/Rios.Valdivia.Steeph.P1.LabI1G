#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"






#define TAM 11
#define TAM_TIP 5
#define TAM_COL 5
#define TAM_SERV 3
#define TAM_TRAB 50








int main()

{
    char seguir = 's';
    int nextIdMascota = 50000;
    int nextIdTrabajo = 7000;
    int queHizo =0;


    eMascota lista[TAM];
    eTrabajo trabajos[TAM_TRAB];

     eTipo tipos[TAM_TIP]=
    {
        {1000,"Ave"},
        {1001,"Perro"},
        {1002,"Roedor"},
        {1003,"Gato"},
        {1004,"Pez"},
    };


    eColor colores[TAM_COL] =
    {
        {5000,"Negro"},
        {5001,"Blanco"},
        {5002,"Rojo"},
        {5003,"Gris"},
        {5004,"Azul"},
    };

    eServicio servicios[TAM_SERV] =
    {
        {20000, "Corte", 450},
        {20001, "Desparasitado", 800},
        {20002, "Castrado", 600},
    };


    if(!inicializarMascotas(lista, TAM))
       {
           printf("Problema al inicializar mascotas");
       }

    if(!inicializarTrabajos(trabajos, TAM_TRAB))
       {
           printf("Problema al inicializar almuerzos");
       }

       hardcodearMascotas(lista,TAM,10,&nextIdMascota);

       do
        {
            switch(menu())
            {
            case 'A':
                if(!altaMascota(lista,TAM,tipos ,TAM_TIP, colores , TAM_COL, &nextIdMascota))
                {
                    printf("\nNo se pudo realizar el alta.\n");
                }
                else
                {
                    printf("\nAlta exitosa!!\n");
                    queHizo=1;
                }
                break;

            case 'B':
                if(queHizo == 0)
                {
                    printf("\nNo se puede modificar, sin antes haber dado de alta alguna mascota!!\n");
                }
                else
                {
                    if(!modificarMascota(lista,TAM,tipos,TAM_TIP,colores,TAM_COL))
                    {
                        printf("\nNo se pudo realizar la modificacion.\n");
                    }
                    else
                    {
                        printf("\nModificacion exitosa!!\n");
                    }
                }
                break;

            case 'C':
                if(queHizo == 0)
                {
                    printf("\nNo se puede dar de baja, sin antes haber dado de alta alguna mascota!!\n");
                }
                else
                {
                    if(!bajaMascota(lista,TAM, tipos, TAM_TIP,colores,TAM_COL))
                    {
                        printf("\nNo se pudo realizar la baja.\n");
                    }
                    else
                    {
                        printf("Baja exitosa!!\n");
                    }
                }


                break;

            case 'D':
                if(queHizo == 0)
                {
                    printf("\nNo se puede listar mascotas, sin antes haber dado de alta alguna mascota!!\n");
                }
                else
                {
                    if(!informarMascotas(lista, TAM,tipos,TAM_TIP,colores,TAM_COL))
                    {
                         printf("\nNo se pudo ordenar la lista de autos.\n");
                    }
                }

                break;

            case 'E':
                if(!mostrarTipos(tipos,TAM_TIP))
                {
                    printf("No se puede listar los tipos!!\n");
                }
                break;

            case 'F':
                if(!mostrarColores(colores,TAM_COL))
                {
                    printf("No se puede listar los colores!!\n");
                }
                break;

            case 'G':
                if(!mostrarServicios(servicios,TAM_SERV))
                {
                    printf("No se puede listar los servicios!!\n");
                }
                break;

            case 'H':
                if(queHizo == 0)
                {
                    printf("\nNo se puede dar de alta trabajo, sin antes haber dado de alta alguna mascota!!\n");
                }
                else
                {
                    if(!altaTrabajos(trabajos,TAM_TRAB,lista ,TAM, tipos ,TAM_TIP, colores , TAM_COL, servicios, TAM_SERV ,&nextIdTrabajo))
                    {
                        printf("\nNo se pudo realizar el alta.\n");
                    }
                    else
                    {
                        printf("\nAlta exitosa!!\n");
                    }
                }

                break;

            case 'I':
                if(queHizo == 0)
                {
                    printf("\nNo se puede mostrar lista de trabajos, sin antes haber dado de alta alguna mascota!!\n");
                }
                else
                {
                   if(!mostrarTrabajos(trabajos,TAM_TRAB,lista,TAM,servicios,TAM_SERV,tipos,TAM_TIP,colores,TAM_COL))
                    {
                        printf("\nNo se pudo listar los trabajos!!\n");
                    }
                }
                break;

            case 'J':
                printf("Ha seleccionado salir\n");
                seguir='n';
                break;

            default:
                printf("Opcion invalidad!!!\n");
            }
            system("pause");

        }while(seguir == 's');

    return 0;
}



