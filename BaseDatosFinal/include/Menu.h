#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <limits>

#include "Archivo.h"
#include "Funciones.h"
#include "Empleado.h"

#define TECLA_ARRIBA 'i'  //declaraciones constantes para usar las teclas con codigo ascii
#define TECLA_ABAJO 'k'
#define ENTER 13

using namespace std;

template<typename T,typename I,typename F>
class Menu:public Funciones,public Archivo,private Empleado
{
        public:;
        Menu();
        Menu(char* titulo,char* *opciones,int n);
        ~Menu();
        void registro();
        void busco();
        void elimino();
        void leo();
        void modifico();

    private:
        char* titulo;
        char* *opciones;
        int n;

        T opca;
        T nombre[10];
        T apellidoP[10];
        T apellidoM[10];
        I clave = 0;
        I auxclave=0;
        I edad;
        I dni;
        I telefono;
        F sueldo;

        T auxnombre[10];
        T auxapellidoP[10];
        T auxapellidoM[10];
        I auxedad;
        I auxdni;
        I auxtelefono;
        F auxsueldo;

        void comprobar(I &x){
           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN NUMEROS!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }

        void comprobar(F &x){
           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN NUMEROS!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }

        void comprobar(T x[]){

           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN CARACTERES!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }
};

#endif // MENU_H
