#include "Empleado.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include <string>
#include<cstdlib> //para usar system(cls)
#include<windows.h>

using namespace std;

Empleado::Empleado()
{
			nombre="";
			edad=0;
			dni=0;
			sueldo=0;
}

Empleado::~Empleado(string _nombre,int _edad,int _dni,float _sueldo)
{
			nombre = _nombre;
			edad = _edad;
			dni = _dni;
			sueldo = _sueldo;
}
string Empleado::getNombre(){
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
