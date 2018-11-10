#include "Empleado.h"

Empleado::Empleado(){
    nombre="";
    edad=0;
    dni=0;
    sueldo=0;
}

Empleado::Empleado(char* _nombre,int _edad,int _dni,float _sueldo){
    nombre = _nombre;
    edad = _edad;
    dni = _dni;
    sueldo = _sueldo;
}

char* Empleado::getNombre(){
    return nombre;
}

int Empleado::getEdad(){
    return edad;
}

int Empleado::getDni(){
    return dni;
}

float Empleado::getSueldo(){
    return sueldo;
}
