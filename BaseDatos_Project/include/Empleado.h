#ifndef EMPLEADO_H
#define EMPLEADO_H



class Empleado
{
    public:
        Empleado();
        Empleado(char* _nombre,int _edad,int _dni,float _sueldo);
        char* getNombre();
        int getEdad();
        int getDni();
        float getSueldo();


    protected:
        char* nombre;
        int edad;
        int dni;
        float sueldo;

};

#endif // EMPLEADO_H
