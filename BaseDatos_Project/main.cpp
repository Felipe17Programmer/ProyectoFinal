#include <iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<cstdlib> //para usar system(cls)
#include<windows.h>

#define TECLA_ARRIBA 'i'  //declaraciones constantes para usar las teclas con codigo ascii
#define TECLA_ABAJO 'k'
#define ENTER 13
#include "Empleado.h"
#include "Archivo.h"
#include "Menu.h"

using namespace std;

void gotoxy(int x,int y);
int menu( char* titulo,  char *opciones[], int n);
void menu_principal();
char getch2();  //permite poder usar menu con el teclado

int main()
{
	ofstream archivo;
	//tipo de dato - nombre archivo

	//archivo.open(nombreArchivo.c_str(),ios::out); //abriendo el archivo , ios::out si existe lo crea o reemplaza
	archivo.open("Fichero.txt",ios::app); //abriendo el archivo , ios::out si existe lo crea o reemplaza

	if(archivo.fail()){
		archivo.open("Fichero.txt",ios::out);
		exit(1); //strdlib.h para salir del programa rapido
	}

	archivo.close(); //para cerrar el archivo.-

	menu_principal();
    return 0;
}

char getch2(){
	char c=0;
	DWORD modo, contador;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

	//DESACTIVAMOS ESCRITURA EN TERMINAL
	SetConsoleMode(ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	ReadConsoleA(ih, &c,1,&contador,NULL);

	if(c==0){
		ReadConsoleA(ih,&c,1,&contador,NULL);
	}

	SetConsoleMode(ih,modo); //Devolvemos control normal

	return c;
}

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

void menu_principal(){

	bool repite=true;
	int opcion;

	//Titulo y opciones del menu
	char* titulo="MENU PRINCIPAL";
	char *opciones[]={"Ingresar","Buscar","Modificar","Eliminar","Salir"};
	int n = 5; //numero de opciones

	char *arr1[] = {"Nombres y Apellidos","Edad","DNI","Sueldo","Regresar"};
	int tamanio=sizeof(arr1)/sizeof(arr1[0]);
	Menu m1("",0,0,0,"DATOS",arr1,tamanio);

	char *arr2[] = {"Nombres y Apellidos","Regresar"};
	int tamanio2=sizeof(arr2)/sizeof(arr2[0]);
	Menu m2("",0,0,0,"BUSCAR",arr2,tamanio2);

	do{
		opcion = menu(titulo,opciones,n); //funcion debe retornar un entero

		//Alternativas
		switch(opcion){
			case 1:
				m1.menuIngresar();
				break;
			case 2:
				m2.menuBuscar();
				break;
			case 3:
				cout<<"MODIFICAR";
				//menu_modificar();
				break;
			case 4:
				cout<<"ELIMINAR";
				//menu_eliminar();
				break;
			case 5:
				repite=false;
				break;
		}
	}while(repite);
}

int menu( char* titulo,  char *opciones[], int n){
	int opcionSeleccionada = 1;
	int tecla;
	bool repite=true;
	do{
		system("cls");

		gotoxy(5,3+opcionSeleccionada);  cout<<"==>";  //gotoxy pertenece a conio.h e imprime en coordenadas
		//imprimir titulo
		gotoxy(15,2); cout<<titulo;
		//imprimir opciones
		for(int i=0;i<n;i++){
			gotoxy(10,4+i); cout<<i+1<<")"<<opciones[i];
		}

		do{
			tecla=getch2(); //getch captura la tecla presionada por el ususario
		}while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch(tecla){
			case TECLA_ARRIBA:
				opcionSeleccionada--;

				//opcion empieza en 1 si retrocede un espacio ocurre lo siguiente
				if(opcionSeleccionada < 1){
					opcionSeleccionada = n;
				}
				break;
				//opcion que llega a 5 si sube un espacio ocurre lo siguiente
			case TECLA_ABAJO:
				opcionSeleccionada++;
				if(opcionSeleccionada > n){
					opcionSeleccionada = 1;
				}
				break;
			case ENTER:
				repite = false;
				break;
		}

	}while(repite);

	return opcionSeleccionada;
}

