#ifndef ARCHIVO_H
#define ARCHIVO_H


class Archivo
{
    public:
        Archivo(){};
        ~Archivo(){};
        virtual void registro()=0;
        virtual void busco()=0;
        virtual void elimino()=0;
        virtual void leo()=0;
        virtual void modifico()=0;

};

#endif // ARCHIVO_H
