#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id; //(comienza en 20000)
    char descripcion[25]; //(máximo 25 caracteres)
    int precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED

int cargarDescripcionServicio(eServicio servicios[], int tamServ,int idServicio , char descripcion[]);
int mostrarServicios(eServicio servicios[], int tamServ);
int validarIdServicio(int id ,eServicio servicios[], int tamServ);
