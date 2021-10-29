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
    char continuar = 's';
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
           printf("Problema al inicializar trabajos");
       }


       hardcodearMascotas(lista,TAM,10,&nextIdMascota);
       hardcodearTrabajos(trabajos,TAM_TRAB,10,&nextIdTrabajo);

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
                do
                {
                    system("cls");
                    switch(subMenuInformes())
                    {
                        case 1:
                            if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar  el la lista, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarMascotasColor(lista, TAM, tipos, TAM_TIP, colores, TAM_COL))
                                {
                                    printf("\nNo se pudo mostrar las mascotas por color elegido!!\n");
                                }
                            }

                            break;

                        case 2:

                            if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar  el promedio, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarPromedioMascVacunadas(lista, TAM,tipos, TAM_TIP, colores, TAM_COL))
                                {
                                    printf("\nNo se pudo mostrar el promedio!!\n");
                                }
                            }

                            break;

                        case 3:
                            if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar  la menor mascota, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarMascMenorEdad(lista, TAM))
                                {
                                    printf("\nNo se pudo mostrar la/s mascota/s con menor edad!!\n");
                                }
                            }
                            break;

                        case 4:
                              if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar todos las mascotas por tipo, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarTodasMascTipos(lista,TAM,tipos,TAM_TIP,colores, TAM_COL))
                                {
                                    printf("\nNo se pudo mostrar todas las mascotas por tipo!!\n");
                                }
                            }
                            break;

                        case 5:
                            if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar todos las cantidades por tipo y color, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarCantidadMascTipoColor(lista,TAM, tipos, TAM_TIP, colores, TAM_COL))
                                {
                                    printf("\nNo se pudo mostrar todas las cantidas por tipo y color!!\n");
                                }
                            }
                            break;

                        case 6:
                                  if(queHizo == 0)
                            {
                                printf("\nNo se puede mostrar el color o colores mas ingresado, sin antes haber dado de alta alguna mascota!!\n");
                            }
                            else
                            {
                               if(!informarColorMascMasIngresada(lista,TAM,colores,TAM_COL))
                                {
                                    printf("\nNo se pudo mostrar el color o colores mas ingresado!!\n");
                                }
                            }

                            break;

               /*         case 7:

                            break;

                          case 8:

                            break;

                        case 9:

                            break;

                        case 10:

                            break; */

                            case 11:
                                 printf("Ha seleccionado salir\n");
                                 continuar='n';
                                 break;

                            default:
                            printf("Opcion invalida!!!\n");
                    }
                    system("pause");

                }while (continuar == 's');
                break;

            case 'K':
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



