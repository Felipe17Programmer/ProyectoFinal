#ifndef BUSCA_H
#define BUSCA_H

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

class Busca:public Menu
{
    public:
        Busca(){}
        ~Busca(){}
        void empieza(){
                ifstream lectura;
                lectura.open("Registro.txt", ios::out | ios::in);

                bool encontrado=false;

                if (lectura.is_open()){
                    cout<<"\n\tClave a buscar -> ";comprobar(auxclave);
                    lectura>>clave;
                    while(!lectura.eof()){
                        lectura>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                    //comparar cada registro para ver si es encontrado

                    if(auxclave==clave){
                        cout<<"\n";
                        cout<<"\tClave:  "<<clave<<endl;
                        cout<<"\tNombre:  "<<nombre<<endl;
                        cout<<"\tApellido Paterno:  "<<apellidoP<<endl;
                        cout<<"\tApellido Materno:  "<<apellidoM<<endl;
                        cout<<"\tEdad:  "<<edad<<endl;
                        cout<<"\tDNI:  "<<dni<<endl;
                        cout<<"\tTelefono:  "<<telefono<<endl;
                        cout<<"\tSueldo:  "<<sueldo<<endl;
                        cout<<"\t________________________________\n";
                        encontrado=true;
                        break;
                    }
                    //lectura adelantada
                    lectura>>clave;
                    }//fin del while
                    if (encontrado==false){
                        cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
                    }
                }else{
                    cout<<"\n\tNo se pudo abrir el archivo";
                }
                lectura.close();
                getch();
        }

};

#endif // BUSCA_H
