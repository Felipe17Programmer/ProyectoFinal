#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define TECLA_ARRIBA 'i'  //declaraciones constantes para usar las teclas con codigo ascii
#define TECLA_ABAJO 'k'
#define ENTER 13

using namespace std;

class Funciones
{
    public:
        Funciones(){};
        ~Funciones(){};
        char getch2(){  //permite poder usar menu con el teclado
            char c=0;
            DWORD modo, contador;
            HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
            //DESACTIVAMOS ESCRITURA EN TERMINAL
            SetConsoleMode(ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
            ReadConsoleA(ih, &c,1,&contador,NULL);

            if(c==0){
                ReadConsoleA(ih,&c,1,&contador,NULL);
            }

            SetConsoleMode(ih,modo); //Devolvemos control normal
            return c;
        }

        void gotoxy(int x,int y){
              HANDLE hcon;
              hcon = GetStdHandle(STD_OUTPUT_HANDLE);
              COORD dwPos;
              dwPos.X = x;
              dwPos.Y= y;
              SetConsoleCursorPosition(hcon,dwPos);
        }
        int menu( char* titulo,  char *opciones[], int n){
            int opcionSeleccionada = 1;
            int tecla;
            bool repite=true;
            do{
                system("cls");
                gotoxy(5,3+opcionSeleccionada);  cout<<"==>";
                gotoxy(15,2); cout<<titulo;
                for(int i=0;i<n;i++){
                    gotoxy(10,4+i); cout<<i+1<<")"<<opciones[i];
                }
                do{
                    tecla=getch2(); //getch captura la tecla presionada por el ususario
                }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

                switch(tecla){
                    case TECLA_ARRIBA:
                        opcionSeleccionada--;
                        //opcion empieza en 1 si retrocede un espacio ocurre lo siguiente
                        if(opcionSeleccionada < 1){
                            opcionSeleccionada = n;
                        }
                        break;
                        //opcion que llega a 5 si sube un espacio ocurre lo siguiente
                    case TECLA_ABAJO:
                        opcionSeleccionada++;
                        if(opcionSeleccionada > n){
                            opcionSeleccionada = 1;
                        }
                        break;
                    case ENTER:
                        repite = false;
                        break;
                }
            }while(repite);
            return opcionSeleccionada;
        }

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

#endif // FUNCIONES_H
