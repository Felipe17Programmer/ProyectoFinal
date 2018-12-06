#ifndef ELIMINO_H
#define ELIMINO_H

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

class Elimino:public Menu
{
    public:
        Elimino(){}
        ~Elimino(){}
        void empieza(){
                ofstream aux;
                ifstream lectura;

                bool encontrado=false;
                char opca;
                aux.open("auxiliar.txt", ios::out);
                lectura.open("Registro.txt", ios::in);

                if (aux.is_open() && lectura.is_open()){

                    cout<<"\n";
                    cout<<"\tClave a buscar y eliminar registro -> ";comprobar(auxclave);
                        //De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
                        //hasta llegar al final del archivo gracias a la función .eof()
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
                                    cout<<"\t________________________________\n";
                                    cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                                    cin>>opca;

                                    if (opca=='S' or opca=='s'){
                                        cout<<"\n\n\t\t\tRegistro eliminado con exito!!!\n\n\t\t\a";
                                    }else{
                                        aux<<clave<<" "<<nombre<<" "<<apellidoP<<" "<<apellidoM<<" "<<edad<<" "<<dni<<" "<<telefono<<" "<<sueldo<<endl;
                                    }

                                }else{
                                    aux<<clave<<" "<<nombre<<" "<<apellidoP<<" "<<apellidoM<<" "<<edad<<" "<<dni<<" "<<telefono<<" "<<sueldo<<endl;
                                }
                            lectura>>clave;
                        }
                }
                else{
                    cout<<"\n\tEl archivo no se pudo abrir \n";
                }

                if(encontrado==false){
                            cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
                }

                aux.close();
                lectura.close();
                remove ("Registro.txt");
                rename("auxiliar.txt", "Registro.txt");
                getch();
        }

};

#endif // ELIMINO_H
