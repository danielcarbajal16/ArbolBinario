#include "Arbol_binario.h"

///Metodos recursivos
void arbol_binario::insertar(Nodo*& pos, Directorio& dato) {
    if(pos == nullptr) {
        pos = new Nodo;
        if(pos == nullptr) {
            cout << "Memoria no disponible...\n" << endl;
            }
        pos->setDato(dato);
        if (raiz == nullptr) {
            raiz = pos;
        }
        return;
        }
    string nombre1 = dato.getNombre();
    string nombre2 = pos->getDato().getNombre();
    if(nombre1.compare(nombre2) < 0) {
        cout << "\nInserta de lado izquierdo." << endl;
        insertar(pos->getIzq(), dato);
        }
    else {
        cout << "\nInserta de lado derecho." << endl;
        insertar(pos->getDer(), dato);
        }
}

Nodo*& arbol_binario::buscar(Nodo*& pos, string nombre, string ape) {
    if(pos == nullptr) {
        return pos;
        }
    string name = pos->getDato().getNombre();
    string lastname = pos->getDato().getApellido();
    if (name.compare(nombre) == 0 && lastname.compare(ape) == 0) {
        return pos;
    }
    if(nombre.compare(pos->getDato().getNombre()) < 0) {
        return buscar(pos->getIzq(), nombre,ape);
        }
    else {
        return buscar(pos->getDer(),nombre,ape);
        }
}

void arbol_binario::preorden(Nodo* pos) {
    if (pos == nullptr) {
        return;
    }

    cout << pos->getDato().getNombre() << " " << pos->getDato().getApellido() << "\n";
    preorden(pos->getIzq());
    preorden(pos->getDer());
}

void arbol_binario::inorden(Nodo* pos) {
    if (pos == nullptr) {
        return;
    }

    inorden(pos->getIzq());
    cout << pos->getDato().getNombre() << " " << pos->getDato().getApellido() << endl;
    inorden(pos->getDer());
}

void arbol_binario::postorden(Nodo* pos) {
    if (pos == nullptr) {
        return;
    }
    postorden(pos->getIzq());
    postorden(pos->getDer());
    cout << pos->getDato().getNombre() << " " << pos->getDato().getApellido() << endl;
}

Nodo*& arbol_binario::menor(Nodo*& pos) {
    if(pos == nullptr || pos->getIzq() == nullptr) {
        return pos;
        }

    return menor(pos->getIzq());
}

Nodo*& arbol_binario::mayor(Nodo*& pos) {
    if(pos == nullptr || pos->getDer() == nullptr) {
        return pos;
        }

    return mayor(pos->getDer());
}


arbol_binario::arbol_binario() {///Constructor
    raiz = nullptr;
}

bool arbol_binario::vacio() {
    return raiz == nullptr;
}

void arbol_binario::insertar(Directorio& info) {
    insertar(raiz,info);
}

Nodo*& arbol_binario::buscar(string nom, string ape) {
    return buscar(raiz,nom,ape);
}

bool arbol_binario::es_hoja(Nodo* pos) {
    return pos != nullptr && pos->getIzq() == pos->getDer();
}

void arbol_binario::preorden() {
    preorden(raiz);
}

void arbol_binario::inorden() {
    inorden(raiz);
}

void arbol_binario::postorden() {
    postorden(raiz);
}

void arbol_binario::borrarDato(Nodo*& pos) {
    if (pos == nullptr) {
        cout << "\nEse elemento no existe...\n" << endl;
    }
    else {
        if (es_hoja(pos)) {
            delete pos;
            pos = nullptr;
            cout << "\nEl elemento ha sido borrado correctamente...\n" << endl;
        }
        else {
            Nodo*& sustituto(pos->getIzq() != nullptr ? mayor(pos->getIzq()) : menor(pos->getDer()));
            Nodo* aux = new Nodo;
            aux->setDato(pos->getDato());
            pos->setDato(sustituto->getDato());
            sustituto->setDato(aux->getDato());
            delete aux;
            borrarDato(sustituto);
        }
    }
}
