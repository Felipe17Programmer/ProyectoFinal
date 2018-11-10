#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(char* _nombre,int _edad,int _dni,float _sueldo,char* titulo,char* *opciones,int n):Empleado(_nombre,_edad,_dni,_sueldo){
    this->n = n;
    this->titulo = titulo;
    this->opciones = opciones;
}

void Menu::menuIngresar(){
    bool repite = true;
    int opcion;
    Archivo text1(" ");
    Archivo num1(0);
    Archivo num2(0);

    do{
        system("cls");
        opcion = menu(titulo,opciones,n);

        //Alternativas

        system("cls");
        switch(opcion){
        case 1:
            system("cls");
            cout<<"NOMBRES Y APELLIDOS: ";
            cin.getline(nombre,80,'\n');
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

void Menu::menuBuscar(){
    bool repite=true;
    int opcion;
    Archivo text1(" ");
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
                cin.getline(nombre,80,'\n');
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
