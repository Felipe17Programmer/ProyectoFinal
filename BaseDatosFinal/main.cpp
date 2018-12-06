#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Menu.h"
#include "Empleado.h"
#include "Registro.h"
#include "Busca.h"
#include "Elimino.h"
#include "Lee.h"
#include "Modifico.h"

#define TECLA_ARRIBA 'i'  //declaraciones constantes para usar las teclas con codigo ascii
#define TECLA_ABAJO 'k'
#define ENTER 13

using namespace std;

char getch2();  //permite poder usar menu con el teclado
void gotoxy(int x,int y);
int menu( char* titulo,  char *opciones[], int n);
void menu_principal();

int main()
{
    system ("color 0A");
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
	char* titulo1="MENU PRINCIPAL";
	char *opciones1[]={"Registrar","Eliminar","Leer","Buscar","Modificar","Salir"};
	int tamanio=sizeof(opciones1)/sizeof(opciones1[0]);

	//Menu m;

    char *opciones2[] = {"Todos","Lineal","Nombre y Clave","Regresar"};
	int tamanio2=sizeof(opciones2)/sizeof(opciones2[0]);

	Lee l("LEER",opciones2,tamanio2);
    Registro r;
    Busca b;
    Elimino e;
    Modifico m;
    Menu *men;

	do{
		opcion = menu(titulo1,opciones1,tamanio);
		//Alternativas
		switch(opcion){
			case 1:
			    system("cls");
			    men = &r;
                men->empieza();
                break;
			case 2:
			    system("cls");
			    men = &e;
				men->empieza();
				break;
			case 3:
			    men = &l;
                men->empieza();
				break;
			case 4:
			    system("cls");
			    men = &b;
                men->empieza();
				break;
			case 5:
			    system("cls");
			    men = &m;
                men->empieza();
				break;
            case 6:
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


