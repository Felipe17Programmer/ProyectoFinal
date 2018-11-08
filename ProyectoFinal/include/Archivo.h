#ifndef ARCHIVO_H
#define ARCHIVO_H
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib> //para usar system(cls)
#include<windows.h>
#include <string>

class Archivo
{
	protected:
		string texto;
		int numero1;
		float numero2;

	public:
		Archivo(string _texto);
		Archivo(int _numero1);
		Archivo(float _numero2);
		Archivo();
        ~Archivo();
		void setTexto(string _texto);
		void setInteger(int _numero1);
		void setFloat(float _numero2);
		void escribirT();
		void escribirI();
		void escribirF();
		void leerT();
};

#endif // ARCHIVO_H
