#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib> //para usar system(cls)
#include<windows.h>
#include "Archivo.h"
#include "Empleado.h"
#include <string>

class Menu:public Archivo,public Empleado
{
	protected:
		string titulo;
		char* *opciones;
		int n;
	public:
		Menu(string _nombre,int _edad,int _dni,float _sueldo,string titulo,char* *opciones,int n):Empleado(_nombre,_edad,_dni,_sueldo);
		~Menu();
		void menu_ingresar();
		void menu_buscar();

};

#endif // MENU_H
