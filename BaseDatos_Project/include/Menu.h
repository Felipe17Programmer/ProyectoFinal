#ifndef MENU_H
#define MENU_H
#include "Archivo.h"
#include "Empleado.h"
#include <iostream>
#include <windows.h>
#define TECLA_ARRIBA 'i'
#define TECLA_ABAJO 'k'
#define ENTER 13

using namespace std;

class Menu: public Archivo,public Empleado
{
    public:
        Menu(char* _nombre,int _edad,int _dni,float _sueldo,char* titulo,char* *opciones,int n);
        void menuIngresar();
        void menuBuscar();

    protected:
        char* titulo;
        char* *opciones;
        int n;
        char getch2(){
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
};

#endif // MENU_H
