#ifndef LEE_H
#define LEE_H

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

class Lee:public Menu
{
    public:
        Lee(){}
        Lee(char* titulo,char* *opciones,int n){
            this->n = n;
            this->titulo = titulo;
            this->opciones = opciones;
        }
        ~Lee(){}
        void empieza(){
                system("cls");
                ifstream lectura;
                bool repite = true;
                int opcion=0;
                system("cls");

                char* *arreglo1;
                char* *arreglo;
                int tamanio = 0;
                do{
                    system("cls");
                    opcion = menu(titulo,opciones,n);

                    system("cls");
                    switch(opcion){
                    case 1:
                        system("cls");
                        lectura.open("Registro.txt", ios::out | ios::in);
                        if (lectura.is_open()){

                               lectura>>clave;
                               while (!lectura.eof()){
                                    lectura>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                                    cout<<"\n";
                                    cout<<"\tClave:  "<<clave<<endl;
                                    cout<<"\tNombre:  "<<nombre<<endl;
                                    cout<<"\tApellido Paterno:  "<<apellidoP<<endl;
                                    cout<<"\tApellido Materno:  "<<apellidoM<<endl;
                                    cout<<"\tEdad:  "<<edad<<endl;
                                    cout<<"\tDNI:  "<<dni<<endl;
                                    cout<<"\tTelefono:  "<<telefono<<endl;
                                    cout<<"\tSueldo:  "<<sueldo<<endl;
                                    lectura>>clave;
                                    cout<<"\t________________________________\n";
                               }

                            }else{
                                cout<<"El archivo no se pudo abrir \n";
                            }
                            lectura.close();
                            system("pause>nul");
                            break;
                    case 2:
                        system("cls");

                        lectura.open("Registro.txt", ios::out | ios::in);
                        if (lectura.is_open()){

                               lectura>>clave;
                               while (!lectura.eof()){

                                    lectura>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                                    cout<<"\n";
                                    cout<<"\tClave:  "<<clave<<" --> Nombre:  "<<nombre<<endl;
                                    lectura>>clave;
                               }

                            }else{
                                cout<<"El archivo no se pudo abrir \n";
                            }
                            lectura.close();

                            system("pause>nul");
                            break;

                    case 3:
                        system("cls");
                        lectura.open("Registro.txt", ios::out | ios::in);
                        if (lectura.is_open()){

                               lectura>>clave;
                               while (!lectura.eof()){
                                    lectura>>nombre>>apellidoP>>apellidoM>>edad>>dni>>telefono>>sueldo;
                                    cout<<"\n";
                                    cout<<"\tClave:  "<<clave<<endl;
                                    cout<<"\tNombre:  "<<nombre<<endl;

                                    lectura>>clave;
                               }

                            }else{
                                cout<<"El archivo no se pudo abrir \n";
                            }
                            lectura.close();
                            system("pause>nul");
                            break;

                    case 4:
                        repite=false;
                        break;
                    }
                }while(repite);
        }

};

#endif // LEE_H
