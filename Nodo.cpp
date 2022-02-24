#include "Nodo.h"

Nodo::Nodo() {
    izq = nullptr;
    der = nullptr;
}

void Nodo::setDato(Directorio info) {
    dato = info;
}

Directorio Nodo::getDato() {
    return dato;
}

void Nodo::setIzq(Nodo*& izqd) {
    izq = izqd;
}

Nodo*& Nodo::getIzq() {
    return izq;
}

void Nodo::setDer(Nodo*& dere) {
    der = dere;
}

Nodo*& Nodo::getDer() {
    return der;
}
