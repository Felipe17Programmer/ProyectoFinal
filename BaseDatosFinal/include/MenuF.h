#ifndef MENUF_H
#define MENUF_H

#include "Archivo.h"
#include "Funciones.h"
#include "Empleado.h"


class MenuF:public Archivo,public Funciones,private Empleado
{
    public:
        virtual void registro()=0;
        virtual void busco()=0;
        virtual void elimino()=0;
        virtual void leo()=0;
        virtual void modifico()=0;

    private:

        char opca;
        char nombre[10];
        char apellidoP[10];
        char apellidoM[10];
        int clave = 0;
        int auxclave=0;
        int edad;
        int dni;
        int telefono;
        float sueldo;

        char auxnombre[10];
        char auxapellidoP[10];
        char auxapellidoM[10];
        int auxedad;
        int auxdni;
        int auxtelefono;
        float auxsueldo;

        void comprobar(int &x){
           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN NUMEROS!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }

        void comprobar(float &x){
           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN NUMEROS!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }

        void comprobar(char x[]){

           while( true )
          {
            cout<<"\tIngresa: ";
            cin >> x;
            if( !cin.good() )
            {
              cout << "\tSOLO SE INGRESAN CARACTERES!!!\n"<<endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else
              break;
          }
        }
};

#endif // MENUF_H
