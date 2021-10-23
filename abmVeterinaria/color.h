#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];

}eColor;
#endif // COLOR_H_INCLUDED

int cargarDescripcionColor(eColor colores[], int tamCol,int idColor , char nombreColor[]);
int mostrarColores(eColor colores[], int tamCol);
int validarIdColor(int id ,eColor colores[], int tamCol);
