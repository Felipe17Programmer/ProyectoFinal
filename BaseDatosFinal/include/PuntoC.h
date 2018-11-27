#ifndef PUNTOC_H
#define PUNTOC_H

class PuntoC
{
    public:
        PuntoC();
        PuntoC(char*,char*);
        void print();
        char* getX();
        char* getY();
        void setX(char*);
        void setY(char*);

    private:
        char* x;
        char* y;
};

#endif // PUNTOC_H
