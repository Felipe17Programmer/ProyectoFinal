#ifndef REGISTRO_H
#define REGISTRO_H

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

class Registro:public Menu
{
    public:
        Registro(){}
        ~Registro(){}
        void empieza(){
            ofstream escritura;
            ifstream consulta;

            do{
            escritura.open("Registro.txt", ios::out | ios::app);
            consulta.open("Registro.txt", ios::in);

            if (escritura.is_open() && consulta.is_open()){

                    bool repetido=false;

                    cout<<"\n";
                    cout<<"\tClave -> ";comprobar(auxclave);

                    consulta>>clave;
                    while (!consulta.eof()){
                        consulta>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                        if (auxclave==clave){
                            cout<<"\t\tYa existe la clave...\n";
                            repetido=true;
                            break;
                        }
                        consulta>>clave;
                    }

                    if (repetido==false){
                        cout<<"\tNombre -> ";comprobar(nombre);cout<<"\n";
                        cout<<"\tApellido paterno -> "; comprobar(apellidoP);cout<<"\n";
                        cout<<"\tApellido materno -> "; comprobar(apellidoM);cout<<"\n";
                        cout<<"\tEdad -> "; comprobar(edad);cout<<"\n";
                        cout<<"\tDNI -> "; comprobar(dni);cout<<"\n";
                        cout<<"\tTelefono -> "; comprobar(telefono);cout<<"\n";
                        cout<<"\tSueldo -> "; comprobar(sueldo);cout<<"\n";

                        //ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
                        escritura<<auxclave<<" "<<nombre<<" "<<apellidoP<<" "<<apellidoM<<" "<<edad<<" "<<dni<<" "<<telefono<<" "<<sueldo<<endl;
                        cout<<"\n\tRegistro agregado!!!\n";
                    }

                    cout<<"\n\tDeseas ingresar otro empleado? (S/N): ";
                    cin>>opca;

            }else{
                cout<<"El archivo no se pudo abrir \n";
            }

            escritura.close();
            consulta.close();

            }while (opca=='S' or opca=='s');

        }

};

#endif // REGISTRO_H
