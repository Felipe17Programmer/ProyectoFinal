#include "Archivo.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib> //para usar system(cls)
#include<windows.h>
#include <string>
using namespace std;

Archivo::Archivo(string _texto){
			texto = _texto;
}

Archivo::Archivo(int _numero1){
			numero1 = _numero1;
}

Archivo::Archivo(float _numero2){
			numero2 = _numero2;
}

Archivo::Archivo()
{
			texto="";
			numero1=0;
			numero2=0;
}

Archivo::~Archivo()
{
}

void Archivo::setTexto(string _texto){
			this->texto=_texto;
}

void Archivo::setInteger(int _numero1){
			this->numero1=_numero1;
}

void Archivo::setFloat(float _numero2){
			this->numero2=_numero2;
}

void escribirT(){
			ofstream archivo;
			archivo.open("Fichero.txt" ,ios::app); //abrimos el archivo en modo añadir texto

			if(archivo.fail()){
				cout<<"No se pudo abrir el archivo";
				exit(1);
			}
			archivo<<texto<<endl;
			archivo.close(); //cerrramos el archivo
}

void Archivo::escribirI(){
			ofstream archivo;
			archivo.open("Fichero.txt" ,ios::app); //abrimos el archivo en modo añadir texto

			if(archivo.fail()){
				cout<<"No se pudo abrir el archivo";
				exit(1);
			}
			archivo<<numero1<<endl;
			archivo.close(); //cerrramos el archivo
}

void Archivo::escribirF(){
			ofstream archivo;
			archivo.open("Fichero.txt" ,ios::app); //abrimos el archivo en modo añadir texto

			if(archivo.fail()){
				cout<<"No se pudo abrir el archivo";
				exit(1);
			}
			archivo<<numero2<<endl;
			archivo.close(); //cerrramos el archivo
}

void Archivo::leerT(){
			ifstream archivo;  //if es de input o de lectura
			string text;
			archivo.open("Fichero.txt",ios::in); //abrimos el archivo en modo lectura

			if(archivo.fail()){
				cout<<"No se pudo abrir el archivo";
				exit(1);
			}

			while(!archivo.eof()){ //mientras no sea el final del arcivo
				getline(archivo,text); //copiar todo del archivo en variable string
				cout<<text<<endl;
			}
			archivo.close(); //cerramos el programa
}
