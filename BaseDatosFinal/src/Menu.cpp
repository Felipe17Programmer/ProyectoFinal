#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <limits>

using namespace std;

template<typename T,typename I,typename F>
Menu<T,I,F>::Menu(){
}

template<typename T,typename I,typename F>
Menu<T,I,F>::Menu(char* titulo,char* *opciones,int n){
    this->n = n;
    this->titulo = titulo;
    this->opciones = opciones;
}

template<typename T,typename I,typename F>
Menu<T,I,F>::~Menu(){
}

template<typename T,typename I,typename F>
void Menu<T,I,F>::registro(){
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

template<typename T,typename I,typename F>
void Menu<T,I,F>::busco(){
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

template<typename T,typename I,typename F>
void Menu<T,I,F>::elimino(){
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

template<typename T,typename I,typename F>
void Menu<T,I,F>::leo(){
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

template<typename T,typename I,typename F>
void Menu<T,I,F>::modifico(){
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

template class Menu<char,int,float>;
