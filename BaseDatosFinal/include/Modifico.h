#ifndef MODIFICO_H
#define MODIFICO_H

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

class Modifico:public Menu
{
    public:
        Modifico(){}
        ~Modifico(){}
        void empieza(){
                ofstream aux;
                ifstream lectura;

                bool encontrado=false;

                aux.open("auxiliar.txt", ios::out);
                lectura.open("Registro.txt", ios::in);

                if (aux.is_open() && lectura.is_open()){

                    cout<<"\n";
                    cout<<"\tClave a buscar y modificar registro -> ";comprobar(auxclave);

                        lectura>>clave;
                        while (!lectura.eof()){
                            lectura>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                            if (auxclave==clave){
                                encontrado=true;
                                cout<<"\n";
                                cout<<"\tClave:  "<<clave<<endl;
                                cout<<"\tNombre:  "<<nombre<<endl;
                                cout<<"\tApellido Paterno:  "<<apellidoP<<endl;
                                cout<<"\tApellido Materno:  "<<apellidoM<<endl;
                                cout<<"\tEdad:  "<<edad<<endl;
                                cout<<"\tDNI:  "<<dni<<endl;
                                cout<<"\tTelefono:  "<<telefono<<endl;
                                cout<<"\tSueldo:  "<<sueldo<<endl;
                                cout<<"\t________________________________\n\n";
                                cout<<"\tNombre a modificar con clave "<<auxclave<<" --> ";comprobar(auxnombre);cout<<"\n";
                                cout<<"\tApellido paterno a modificar con clave "<<auxclave<<" --> "; comprobar(auxapellidoP);cout<<"\n";
                                cout<<"\tApellido materno a modificar con clave "<<auxclave<<" --> "; comprobar(auxapellidoM);cout<<"\n";
                                cout<<"\tEdad a modificar con clave "<<auxclave<<" --> "; comprobar(auxedad);cout<<"\n";
                                cout<<"\tTelefono a modificar con clave "<<auxclave<<" --> "; comprobar(auxtelefono);cout<<"\n";
                                cout<<"\tSueldo a modificar con clave "<<auxclave<<" --> "; comprobar(auxsueldo);cout<<"\n";

                                aux<<clave<<" "<<auxnombre<<" "<<auxapellidoP<<" "<<auxapellidoM<<" "<<auxedad<<" "<<dni<<" "<<auxtelefono<<" "<<auxsueldo<<endl;
                                cout<<"\n\n\t\t\tRegistro modificado con exito!!!\n\t\t\a";
                                }else{
                                aux<<clave<<" "<<nombre<<" "<<apellidoP<<" "<<apellidoM<<" "<<edad<<" "<<dni<<" "<<telefono<<" "<<sueldo<<endl;
                                }
                            lectura>>clave;
                        }
                }else{
                    cout<<"\n\tEl archivo no se pudo abrir \n";
                }

                if (encontrado==false){
                            cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
                        }

                aux.close();
                lectura.close();
                remove ("Registro.txt");
                rename("auxiliar.txt", "Registro.txt");
                getch();
        }

};

#endif // MODIFICO_H
