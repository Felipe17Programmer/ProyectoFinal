#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <limits>

#include "Funciones.h"
#include "Empleado.h"

#define TECLA_ARRIBA 'i'  //declaraciones constantes para usar las teclas con codigo ascii
#define TECLA_ABAJO 'k'
#define ENTER 13

using namespace std;

class Menu:public Funciones,public Empleado
{
    protected:
        char* titulo;
        char* *opciones;
        int n;

        char opca;

    public:
        Menu();
        Menu(char* titulo,char* *opciones,int n);
        ~Menu();

        virtual void empieza()=0;


};

#endif // MENU_H
