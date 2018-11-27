#ifndef EMPLEADO_H
#define EMPLEADO_H


class Empleado
{
    protected:
        char opca;
        int clave = 0, auxclave=0;
        char nombre[10];
        char apellidoP[10];
        char apellidoM[10];
        int edad;
        int dni;
        int telefono;
        float sueldo;

        char auxnombre[10];
        char auxapellidoP[10];
        char auxapellidoM[10];
        int auxedad;
        int auxdni;
        int auxtelefono;
        float auxsueldo;
};

#endif // EMPLEADO_H
