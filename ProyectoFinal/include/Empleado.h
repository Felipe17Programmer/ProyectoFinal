#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib> //para usar system(cls)
#include<windows.h>
#include <string>

class Empleado
{
	protected:
		string nombre;
		int  edad;
		int dni;
		float sueldo;

	public:
		Empleado();
		~Empleado();
		Empleado(string _nombre,int _edad,int _dni,float _sueldo);
		string getNombre();
		int getEdad();
		int getDni();
		float getSueldo();
};

#endif // EMPLEADO_H
