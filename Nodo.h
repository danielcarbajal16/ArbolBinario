#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>
#include "Directorio.h"

using namespace std;

class Nodo {
    private:
        Directorio dato;
        Nodo* izq;
        Nodo* der;
    public:
        Nodo();
        void setDato(Directorio);
        Directorio getDato();
        void setIzq(Nodo*& izqd);
        Nodo*& getIzq();
        void setDer(Nodo*& dere);
        Nodo*& getDer();
};

#endif // NODO_H_INCLUDED
