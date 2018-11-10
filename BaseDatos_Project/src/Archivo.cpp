#include "Archivo.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

Archivo::Archivo(){
    texto = " ";
    numero1 = 0;
    numero2 = 0;
}

Archivo::Archivo(char* _texto){
    texto = _texto;
}

Archivo::Archivo(int _numero1){
    numero1 = _numero1;
}

Archivo::Archivo(float _numero2){
    numero2 = _numero2;
}

void Archivo::setTexto(char* _texto){
    this->texto = _texto;
}

void Archivo::setInteger(int _numero1){
    this->numero1 = _numero1;
}

void Archivo::setFloat(float _numero2){
    this->numero2 = _numero2;
}

void Archivo::escribirT(){
    ofstream archivo;
    archivo.open("Registro.txt",ios::app); //abrir archivo en modo añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    archivo<<texto<<endl;
    archivo.close();

}

void Archivo::escribirI(){
    ofstream archivo;
    archivo.open("Registro.txt",ios::app); //abrir archivo en modo añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo" ;
        exit(1);
    }

    archivo<<numero1<<endl;
    archivo.close();
}

void Archivo::escribirF(){
    ofstream archivo;
    archivo.open("Registro.txt",ios::app); //abrir archivo en modo añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    archivo<<numero2<<endl;
    archivo.close();
}

void Archivo::leerT(){
    ifstream archivo; //if es de input o de lectura
    string text;
    archivo.open("Registro.txt",ios::in); //abrir archivo en modo añadir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //mientras no sea final del archivo
        getline(archivo,text); //copiar todo lo del archivo a la variable text
        cout<<text<<endl;
    }
    archivo.close();
}
