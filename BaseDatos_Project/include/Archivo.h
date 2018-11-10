#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Archivo
{
    public:
        Archivo();
        Archivo(char* _texto);
        Archivo(int _numero1);
        Archivo(float _numero2);
        void setTexto(char* _texto);
        void setInteger(int _numero1);
        void setFloat(float _numero2);
        void escribirT();
        void escribirI();
        void escribirF();
        void leerT();

    protected:
        char* texto;
        int numero1;
        float numero2;
};

#endif // ARCHIVO_H
