#include <iostream>
#include "PuntoC.h"

PuntoC::PuntoC(char* xh, char* yh){
    x = xh;
    y = yh;
}

PuntoC::PuntoC(){
    x = "";
    y = "";
}

void PuntoC::print(){
    std::cout << x << " --> " << y<< std::endl;
}


char* PuntoC::getX(){
    return x;
}

char* PuntoC::getY(){
    return y;
}

void PuntoC::setX(char* x){
    this->x = x;
}

void PuntoC::setY(char* y){
    this->y = y;
}

