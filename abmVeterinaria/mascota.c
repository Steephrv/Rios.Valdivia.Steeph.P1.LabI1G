#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascota.h"
#include "tipo.h"
#include "color.h"
#include "inputs.h"


char menu()
{
    char opcion;
    system("cls");
    printf("       ***ABM VETERINARIA*** \n\n");
    printf("A-ALTA MASCOTA\n");
    printf("B-MODIFICAR MASCOTA\n");
    printf("C-BAJA MASCOTA \n");
    printf("D-LISTAR MASCOTAS\n");
    printf("E-LISTAR TIPOS\n");
    printf("F-LISTAR COLORES\n");
    printf("G-LISTAR SERVICIOS\n");
    printf("H-ALTA TRABAJO\n");
    printf("I-LISTAR TRABAJO\n");
    printf("J-**** INFORMES ***\n");
    printf("K-SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = toupper(opcion);

    return opcion;
}


int inicializarMascotas( eMascota lista[],int tam)
{
    int todoOk =0;

    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eMascota lista[], int tam)
{
    int indice= -1;
    if(lista != NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

int altaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol, int* pId)
{
    int todoOk=0;
    int indice;
    eMascota auxMascota;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("          *** Alta Mascota ***\n\n");
        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("No hay lugar");
        }
        else
        {
            auxMascota.id = *pId;
            (*pId)++;

            printf("Ingrese nombre de la mascota: \n");
            fflush(stdin);
            gets(auxMascota.nombre);
            convertirMayusPrimeraLetra(auxMascota.nombre,20);

            mostrarTipos(tipos,tamTip);
            printf("Ingrese el ID del Tipo: \n");
            scanf("%d", &auxMascota.idTipo);

            while(!validarIdTipo(auxMascota.idTipo, tipos, tamTip))
            {
                printf("ERROR. Ingrese el id del tipo correcto: \n");
                scanf("%d", &auxMascota.idTipo);
            }

            mostrarColores(colores,tamCol);
            printf("Ingrese el ID del color: \n");
            scanf("%d", &auxMascota.idColor);
            while(!validarIdColor(auxMascota.idColor, colores, tamCol))
            {
                printf("ERROR, Ingrese el id del color correcto: \n");
                scanf("%d", &auxMascota.idColor);
            }

            tomarIntMxMn(&auxMascota.edad,"Ingrese la edad de su mascota: \n", "ERROR, Ingrese la edad de su mascota correcta: \n", 1,20);

           /* printf("Ingrese la edad de su mascota: \n");
            scanf("%d",&auxMascota.edad);
            while(auxMascota.edad < 1 || auxMascota.edad> 18)
            {
                printf("ERROR. Ingrese la edad de su mascota correcta: \n");
                scanf("%d",&auxMascota.edad);
            }

            printf("\nEsta vacunado? (s/n): \n");
            fflush(stdin);
            scanf("%c", &auxMascota.vacunado); */
            validarCaracter(&auxMascota.vacunado,"Esta vacunado ? s/n: \n", "Error, Ingrese s(si)o n(no): \n", 's', 'n');
           /* while(auxMascota.vacunado != 's' && auxMascota.vacunado != 'n')
            {
                printf("\nERROR. Ingrese (s) si esta vacunado o (n)si no lo esta: \n");
                fflush(stdin);
                scanf("%c", &auxMascota.vacunado);
            } */

            auxMascota.isEmpty = 0;

            lista[indice] = auxMascota;
            todoOk=1;
        }

    }
    return todoOk;
}

int buscarMascotaId(eMascota lista[], int tam, int id)
{
    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0 && lista[i].id == id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void mostrarMascota(eMascota unaMascota , eTipo tipos[],int tamTip, eColor colores[], int tamCol)
{
    char descripTipo[21];
    char descripColor[21];

    if(cargarDescripcionTipo(tipos, tamTip , unaMascota.idTipo, descripTipo)==1 &&
       cargarDescripcionColor(colores,tamCol,unaMascota.idColor,descripColor)==1)
       {
          printf(" %d     %-10s     %-12s        %-10s     %2d      %2c\n",
           unaMascota.id,unaMascota.nombre, descripTipo , descripColor,unaMascota.edad, unaMascota.vacunado);
       }
}


int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[],int tamTip , eColor colores[], int tamCol)
{
    int todoOk=0;;
    int flag=1;
    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0 )
    {
        //system("cls");
        printf("                    **** Lista de Mascotas **** \n");
        printf("---------------------------------------------------------------------------\n");
        printf("   ID      NOMBRE          TIPO              COLOR         EDAD    VACUNADO   \n");
        printf("---------------------------------------------------------------------------\n");

        for(int i=0; i< tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMascota(lista[i], tipos, tamTip ,colores, tamCol);
                flag=0;
            }

        }
        if(flag)
        {
           printf("No hay mascotas para mostrar.\n");
        }
        todoOk=1;
    }
    return todoOk;
}


int menuModificarMascota()
{
    int opcion;

    printf(" Que desea modificar?: \n\n");
    printf("1-Tipo \n");
    printf("2-Vacunado \n");
    printf("3-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    eMascota auxMascota;


    if(lista != NULL && tam > 0 && tipos != NULL && tamTip >0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("        *** Modificar Mascota ***\n\n");
        mostrarMascotas (lista , tam,tipos ,tamTip , colores, tamCol);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam, id);

        if(indice == -1)
        {
            printf("El id de la mascota: %d no esta registrado en el sistema.\n", id);
        }

        else
        {
            mostrarMascota(lista[indice],tipos,tamTip, colores, tamCol);
            printf("Confirma modificacion? S/N: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            while ( confirma != 's' && confirma != 'n')
                {
                    printf("ERROR...Confirma modificacion? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }

            if(confirma == 's')
            {
                do
                {
                    switch(menuModificarMascota())
                    {
                        case 1:

                            mostrarTipos(tipos, tamTip);
                            printf("*** MODIFICAR ID TIPO *** \n");
                            printf("Ingrese nuevo ID tipo: \n");
                            scanf("%d", &auxMascota.idTipo);
                            lista[indice].idTipo = auxMascota.idTipo;

                            break;
                        case 2:

                            printf("Ingrese nuevo (s/n) de vacunacion: \n");
                            scanf("%c", &auxMascota.vacunado);
                            lista[indice].vacunado = auxMascota.vacunado;
                            break;

                        case 3:
                            printf("Ha seleccionado salir\n");
                            confirma='n';
                            break;

                        default:
                            printf("Opcion invalida!!!\n");

                    }
                    system("pause");
                }while(confirma == 's');

                todoOk=1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}


int bajaMascota(eMascota lista[], int tam, eTipo tipos[],int tamTip, eColor colores[],int tamCol)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0 && tipos != NULL && tamTip >0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("                               *** Baja Mascota ***\n\n");
        mostrarMascotas (lista , tam,tipos ,tamTip , colores, tamCol);
        printf("\nIngrese id: ");
        scanf("%d", &id);

        indice = buscarMascotaId(lista,tam, id);

        if(indice == -1)
        {
            printf("El id mascota: %d no esta registrado en el sistema.\n", id);
        }
        else
        {
            mostrarMascota(lista[indice],tipos,tamTip, colores, tamCol);
            printf(" Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            while ( confirma != 's' && confirma != 'n')
                {
                    printf("ERROR...Confirma baja? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                }
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }

    return todoOk;
}

int ordenarMascotasTipoNombre(eMascota lista[], int tam , eTipo tipos[], int tamTip, int orden)
{
    int todoOk=0;
    char descripTipoI[21];
    char descripTipoJ[21];
    eMascota auxMascota;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTip >0 && orden >= 0 && orden <= 1)
    {
        for(int i = 0; i<tam-1; i++)
        {
            for(int j = i + 1; j<tam; j++)
            {
                cargarDescripcionTipo(tipos, tamTip,lista[i].idTipo, descripTipoI);
                cargarDescripcionTipo(tipos, tamTip,lista[j].idTipo, descripTipoJ);
                if(((strcmp(descripTipoI, descripTipoJ) == 0  && strcmp(lista[i].nombre, lista[j].nombre)> 0 &&  orden ) || (strcmp(descripTipoI, descripTipoJ) == 0  && strcmp(lista[i].nombre, lista[j].nombre)< 0 &&  !orden))
                   || ((strcmp(descripTipoI, descripTipoJ) != 0 && strcmp(descripTipoI, descripTipoJ)> 0  && orden ) || (strcmp(descripTipoI, descripTipoJ) != 0 && strcmp(descripTipoI, descripTipoJ)< 0  && !orden)))
                {
                    auxMascota = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMascota;
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int menuOrdenMascotas()
{
    int opcion;

    printf(" \nQue opcion desea?: \n\n");
    printf("1-Mostrar lista mascotas ordenados ascendente (tipo-nombre) \n");
    printf("2-Mostrar lista mascotas ordenados descendente (tipo-nombre) \n");
    printf("3-SALIR\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informarMascotas(eMascota lista[],int tam,eTipo tipos[],int tamTip, eColor colores[] ,int tamCol)
{
    int todoOk = 0;
    char confirm;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        do
        {
            switch(menuOrdenMascotas())
            {
                case 1:
                    ordenarMascotasTipoNombre(lista,tam, tipos, tamTip,ASC);
                    mostrarMascotas(lista,tam ,tipos,tamTip,colores,tamCol);
                    printf("\nOrdenamiento exitoso!!\n");

                    break;

                case 2:
                    ordenarMascotasTipoNombre(lista,tam,tipos, tamTip,DESC);
                    mostrarMascotas(lista,tam ,tipos,tamTip,colores,tamCol);
                    printf("\nOrdenamiento exitoso!!\n");
                    break;

                case 3:
                    printf("Ha seleccionado salir\n");
                    confirm = 'n';
                    break;

                default:
                    printf("Opcion invalida!!!\n");

            }
            system("pause");
        }while(confirm == 's');
        todoOk=1;
    }
    return todoOk;
}

int cargarTipoMascota( eMascota lista[], int tam, eTipo tipos[], int tamTip, int idMascota, char tipo[])
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && tipos != NULL && tamTip > 0 && tipo != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMascota)
            {
                cargarDescripcionTipo(tipos, tamTip, lista[i].idTipo, descripcion);
                strcpy(tipo, descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no hay tipo con el id que le pasaron
        }
    }
    return todoOk;
}

int cargarColorMascota( eMascota lista[], int tam, eColor colores[], int tamCol, int idMascota, char color[] )
{
    int todoOk = 0;
    int flag = 1;
    char descripcion[20];
    if (lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && color != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == idMascota)
            {
                cargarDescripcionColor(colores, tamCol, lista[i].idColor, descripcion);
                strcpy(color, descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int cargarNombreMascota(eMascota lista[], int tam,int id , char nombre[])
{
    int todoOk = 0;
    int flag = 1;

    if(lista != NULL && tam > 0  && nombre != NULL)
    {
        todoOk = 1;
        for(int i = 0; i< tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(nombre, lista[i].nombre);
                flag =0 ;
                break;
            }
        }

        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int subMenuInformes()
{

	int option;

	printf("---------------------------------------------------------------------\n");
	printf("                         MENU DE INFORMES                    \n");
	printf("---------------------------------------------------------------------\n\n");

	printf("  1. INFORMAR MASCOTAS DEL MISMO COLOR.\n");
	printf("  2. INFORMAR PROMEDIO DE MASCOSTAS VACUNADAS SOBRE EL TOTAL DE MASCOTAS\n");
	printf("  3. INFORMAR MASCOTA/S CON MENOS EDAD\n");
	printf("  4. LISTA DE LAS MASCOTAS SEPARADAS POR TIPO.\n");
	printf("  5. INFORMAR CUANTAS MASCOTAS HAY POR TIPO Y COLOR.\n");
	printf("  6. INFORMAR COLOR DE MASCOTA MAS INGRESADA POR CLIENTES\n");
	printf("  7. Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.\n");
	printf("  8. Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
	printf("  9. Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.\n");
	printf(" 10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n\n");
	printf(" 11. SALIR\n");



	printf("Ingrese la opcion : ");
	fflush(stdin);
	scanf("%d", &option);

	return option;
}


int mostraMascotasIdColor(int idColor,eMascota lista[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol)
{
    int todoOk=0;
    int flag=1;
    char descripColor[20];
    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol)
    {
        printf("   ID      NOMBRE          TIPO               COLOR         EDAD    VACUNADO\n");
        printf("-------------------------------------------------------------------------------------\n");

        for(int i=0; i< tam ; i++)
        {
            if(!lista[i].isEmpty  && lista[i].idColor == idColor)
            {
                mostrarMascota(lista[i],tipos, tamTip,colores, tamCol);
                flag=0;
            }

        }
        if(flag)
        {
            cargarDescripcionColor(colores,tamCol, idColor, descripColor);
            printf("No hay mascotas de color : %s.\n", descripColor);
        }
        todoOk=1;
    }

    return todoOk;
}

int informarMascotasColor(eMascota lista[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol)
{
    int todoOk=0;;
    int idColor;
    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol)
    {
        system("cls");
        printf("                           **** MASCOTAS POR COLOR **** \n");
        printf("-----------------------------------------------------------------------------------\n");
        mostrarColores(colores, tamCol);

        printf("Ingrese ID color: \n");
        scanf("%d",&idColor);
        while(!validarIdColor(idColor, colores ,tamCol))
        {
            printf("\nID invalido,  Ingrese id color correcto: \n");
            scanf("%d",&idColor);
        }

        mostraMascotasIdColor(idColor, lista, tam,tipos, tamTip, colores, tamCol);
        todoOk=1;
    }

    return todoOk;
}


int informarPromedioMascVacunadas(eMascota lista[], int tam , eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk=0;
    int contadorTotal=0;
    int contadorVacunados=0;
    float promedioVacunadas =0;
    if(lista != NULL && tam>0)
    {
        mostrarMascotas(lista,tam,tipos,tamTip, colores,tamCol);
        for(int i=0; i< tam ; i++)
        {
            contadorTotal++;
            if(!lista[i].isEmpty  && lista[i].vacunado == 's')
            {
                contadorVacunados++;
            }

        }

        if(!contadorVacunados)
        {
            printf("No hay mascotas vacunadas.");
        }
        else
        {
            promedioVacunadas= (float)contadorVacunados/contadorTotal;
            printf("Promedio de mascotas vacunadas es: %.2f\n", promedioVacunadas);
        }
        todoOk=1;
    }

    return todoOk;
}


int informarMascMenorEdad(eMascota lista[], int tam)
{
    int todoOk=0;
    int menorEdad;
    int flag=1;

    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty)
            {
                if(flag || lista[i].edad < menorEdad)
                {
                    menorEdad = lista[i].edad;
                    flag = 0;
                }
            }
        }
        //---------------------------------------
        system("cls");
        printf(" ***Nombre/s mascota/s con menor edad***\n");
        printf("-----------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty  && lista[i].edad == menorEdad)
            {
                printf("*Nombre mascota: %s y su  edad es: %d anios.\n",lista[i].nombre, lista[i].edad);
            }
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMascotasIdTipo(int idTipo,eMascota lista[], int tam,eTipo tipos[], int tamTip, eColor colores[],int tamCol)
{
    int todoOk=0;
    int flag=1;
    char descripTipo[20];
    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol)
    {
        printf("   ID      NOMBRE          TIPO               COLOR         EDAD    VACUNADO\n");
        printf("--------------------------------------------------------------------------------\n");

        for(int i=0; i< tam ; i++)
        {
            if(!lista[i].isEmpty  && lista[i].idTipo == idTipo)
            {
                mostrarMascota(lista[i],tipos, tamTip,colores, tamCol);
                flag=0;
            }

        }
        if(flag)
        {
            cargarDescripcionTipo(tipos,tamTip, idTipo, descripTipo);
            printf("No hay mascotas de tipo : %s\n", descripTipo);
        }
        todoOk=1;
    }

    return todoOk;
}


int informarTodasMascTipos(eMascota lista[], int tam, eTipo tipos[],int tamTip , eColor colores[], int tamCol)
{
    int todoOk=0;;

    if(lista != NULL && tam>0 && tipos != NULL && tamTip)
    {
        system("cls");
        printf("                           **** Mascotas por Tipo **** \n");
        printf("-----------------------------------------------------------------------------------\n");

        for( int i = 0 ; i< tamTip ; i++)
        {
            printf("Tipo: %s\n", tipos[i].descripcion);
            mostrarMascotasIdTipo(tipos[i].id,lista,tam,tipos,tamTip, colores, tamCol);
            printf("\n---------------------------------------------------------------\n");
        }
        todoOk=1;
    }

    return todoOk;
}




int informarCantidadMascTipoColor(eMascota lista[], int tam, eTipo tipos[], int tamTip, eColor colores[],int tamCol)
{
    int todoOk=0;
    int contadorTip;
    int contadorCol;

    if(lista != NULL && tam>0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("                          **** Cantidad Mascotas por Tipo y Color **** \n");
        printf("-----------------------------------------------------------------------------------\n");

        for( int i = 0 ; i< tamTip ; i++)
        {
            printf("Tipos : %s\n", tipos[i].descripcion);
            contadorTip = 0;
            for(int j = 0; j<tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idTipo == tipos[i].id)
                {
                   contadorTip++;
                }
            }
            printf("Cantidad: %d\n\n", contadorTip);
            printf("\n---------------------------------------------------------------\n");
        }


        for( int i = 0 ; i< tamCol ; i++)
        {
            printf("Colores : %s\n", colores[i].nombreColor);
            contadorCol = 0;
            for(int j = 0; j<tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idColor == colores[i].id)
                {
                   contadorCol++;
                }
            }
            printf("Cantidad: %d\n\n", contadorCol);
            printf("\n---------------------------------------------------------------\n");
        }
        todoOk=1;
    }

    return todoOk;
}


int informarColorMascMasIngresada(eMascota lista[], int tam, eColor colores[],int tamCol)
{
    int todoOk=0;
    int contador[] = {0,0,0,0,0};
    int ColorMasIngresado;

    if(lista != NULL && tam>0 && colores != NULL && tamCol)
    {
        system("cls");
        printf("                          **** Colores de mascota mas ingresada **** \n");
        printf("-----------------------------------------------------------------------------------\n");

        for( int i = 0 ; i< tamCol ; i++)
        {
            for(int j = 0; j<tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idColor == colores[i].id)
                {
                   contador[i]++;
                }
            }
        }

        for(int i =0; i<tamCol; i++)
        {
            if(i==0 || contador[i] > ColorMasIngresado)
            {
                ColorMasIngresado = contador[i];
            }
        }

        for(int i =0; i<tamCol; i++)
        {
            if(contador[i] == ColorMasIngresado)
            {
                printf("El color de mascota mas ingresado es: %s\n", colores[i].nombreColor);
            }
        }

        todoOk=1;
    }

    return todoOk;
}



