#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <limits>

using namespace std;


Menu::Menu(){
}

Menu::Menu(char* titulo,char* *opciones,int n){
    this->n = n;
    this->titulo = titulo;
    this->opciones = opciones;
}

Menu::~Menu(){
}

