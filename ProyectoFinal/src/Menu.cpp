#include "Menu.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib> //para usar system(cls)
#include<windows.h>
#include "Archivo.h"
#include "Empleado.h"
#include <string>
using namespace std;

Menu::Menu(string _nombre,int _edad,int _dni,float _sueldo,string titulo,char* *opciones,int n):Empleado(_nombre,_edad,_dni,_sueldo){
			this->n=n;
			this->titulo=titulo;
			this->opciones=opciones;
}
void Menu:: menu_ingresar(){
			bool repite=true;
			int opcion;
			Archivo text1("");
			Archivo num1(0);
			Archivo num2(0);
			do{
				system("cls");
				opcion = menu(titulo, opciones, n);

				//Alternativas

				system("cls");
				switch(opcion){
					case 1:
						system("cls");
						cout<<"NOMBRES Y APELLIDOS: ";
						getline(cin,nombre);
						text1.setTexto(nombre);
						text1.escribirT();
						system("pause>nul"); //nul para no mostrar presione una tecla para continuar
						break;
					case 2:
						system("cls");
						cout<<"EDAD: ";
						cin>>edad;
						num1.setInteger(edad);
						num1.escribirI();
						system("pause>nul");
						break;
					case 3:
						system("cls");
						cout<<"DNI: ";
						cin>>dni;
						num1.setInteger(dni);
						num1.escribirI();
						system("pause>nul");
						break;
					case 4:
						system("cls");
						cout<<"SUELDO: ";
						cin>>sueldo;
						num2.setFloat(sueldo);
						num2.escribirF();
						system("pause>nul");
						break;
					case 5:
						repite=false;
						break;
				}

			}while(repite);
}

void Menu::menu_buscar(){
			bool repite=true;
			int opcion;
			Archivo text1("");
			Archivo num1(0);
			Archivo num2(0);
			do{
				system("cls");
				opcion = menu(titulo, opciones, n);

				//Alternativas

				system("cls");
				switch(opcion){
					case 1:
						system("cls");
						cout<<"NOMBRES Y APELLIDOS: ";
						getline(cin,nombre);
						text1.setTexto(nombre);
						text1.leerT();
						system("pause>nul"); //nul para no mostrar presione una tecla para continuar
						break;

					case 2:
						repite=false;
						break;
				}

			}while(repite);
}

Menu::~Menu()
{

}

