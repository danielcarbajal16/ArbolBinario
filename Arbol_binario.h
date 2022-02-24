#ifndef ARBOL_BINARIO_H_INCLUDED
#define ARBOL_BINARIO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <string>
#include "Nodo.h"

using namespace std;

class arbol_binario {
    private:
        Nodo* raiz;
        void insertar(Nodo*&, Directorio&);
        Nodo*& buscar(Nodo*&, string, string);
        void preorden(Nodo*);
        void inorden(Nodo*);
        void postorden(Nodo*);
        Nodo*& mayor(Nodo*&);
        Nodo*& menor(Nodo*&);
    public:
        arbol_binario();
        bool vacio();
        void insertar(Directorio& info);
        Nodo*& buscar(string, string);
        bool es_hoja(Nodo*);
        void preorden();
        void inorden();
        void postorden();
        void borrarDato(Nodo*&);
};

#endif // ARBOL_BINARIO_H_INCLUDED
