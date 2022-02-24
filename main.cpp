#include <iostream>
#include "Arbol_binario.h"
#include "Nodo.h"
#include "Directorio.h"

using namespace std;

int main() {
    Directorio per1;
    arbol_binario arbol;
    Nodo* auxNode = nullptr;
    string nom,ape,city,sex,mail,estado_civil,numero;
    char opc;
    char opcAux;
    do {
        system("cls");
        //cin.ignore();
        cout << "Que desea hacer?\n\n"
             << "1) Agregar una persona.\n"
             << "2) Buscar a una persona.\n"
             << "3) Mostrar a todas las personas registradas.\n"
             << "4) Eliminar a alguien.\n"
             << "5) Salir\t\t";
        cin >> opc;
        cin.ignore();
        switch(opc) {
            case '1':
                system("cls");
                cout << "Ingresar la siguiente informacion de la persona a registrar.\n\n";
                cout << "Nombre: ";
                getline(cin,nom);
                cout << "Apellido: ";
                getline(cin,ape);
                cout << "Ciudad de residencia: ";
                getline(cin,city);
                cout << "Correo electronico: ";
                getline(cin,mail);
                do {
                    cout << "\nElija la opcion correspondiente a su estado civil.\n\n"
                         << "1) Casado/a.\n"
                         << "2) Soltero/a.\n"
                         << "3) Divorciado/a.\n"
                         << "4) En pareja.\t\t";
                    cin >> opcAux;
                    }
                while (opcAux != '1' && opcAux != '2' && opcAux != '3' && opcAux != '4');
                cin.ignore();
                per1.setEstadoCivil(opcAux);
                do {
                    cout << "\nAhora elija la opcion correspondiente a su sexo.\n\n"
                         << "1) Hombre.\n"
                         << "2) Mujer.\n"
                         << "3) Indefinido.\t\t";
                    cin >> opcAux;
                    }
                while (opcAux != '1' && opcAux != '2' && opcAux != '3');
                cin.ignore();
                cout << "\nNumero de telefono: ";
                getline(cin,numero);
                per1.setNombre(nom);
                per1.setApellido(ape);
                per1.setCiudad(city);
                per1.setCorreo(mail);
                per1.setGenero(opcAux);
                per1.setNumero(numero);
                arbol.insertar(per1);
                cout << "\nDatos ingresados correctamente...\n" << endl;
                system("pause");
                break;
            case '2':
                system("cls");
                if (!arbol.vacio()) {
                    cout << "Ingrese el nombre de la persona que busca: ";
                    getline(cin,nom);
                    cout << "Ahora ingrese el apellido: ";
                    getline(cin,ape);
                    if (arbol.buscar(nom,ape) == nullptr) {
                        cout << "\nEsta persona no se encuentra registrada.\n" << endl;
                        }
                    else {
                        auxNode = arbol.buscar(nom,ape);
                        cout << "\nNombre: " << auxNode->getDato().getNombre() << endl
                             << "Apellido: " << auxNode->getDato().getApellido() << endl
                             << "Ciudad de residencia: " << auxNode->getDato().getCiudad() << endl
                             << "Sexo: " << auxNode->getDato().getGenero() << endl
                             << "Estado civil: " << auxNode->getDato().getEstadoCivil() << endl
                             << "Correo: " << auxNode->getDato().getCorreo() << endl
                             << "Numero de telefono: " << auxNode->getDato().getNumero() << endl << endl;
                        }
                    }
                else {
                    cout << "No hay ningun registro aun...\n" << endl;
                    }
                system("pause");
                break;
            case '3':
                system("cls");
                if (!arbol.vacio()) {
                    do {
                        cout << "De que manera desea mostrar los elementos registrados?\n\n"
                             << "1) Preorden.\n"
                             << "2) Inorden.\n"
                             << "3) Postorden.\t\t";
                        cin >> opcAux;
                        cout << endl;
                        }
                    while (opcAux != '1' && opcAux != '2' && opcAux != '3');
                    if (opcAux == '1')
                        arbol.preorden();
                    else if (opcAux == '2')
                        arbol.inorden();
                    else if (opcAux == '3')
                        arbol.postorden();
                    cout << endl;
                    }
                else {
                    cout << "No hay ningun registro aun...\n" << endl;
                    }
                system("pause");
                break;
            case '4':
                system("cls");
                if (!arbol.vacio()) {
                    cout << "Ingrese el nombre y apellido de la persona que desea eliminar.\n\n"
                         << "Nombre: ";
                    getline(cin,nom);
                    cout << "Apellido: ";
                    getline(cin,ape);
                    arbol.borrarDato(arbol.buscar(nom,ape));
                    }
                else {
                    cout << "No hay ningun registro aun...\n" << endl;
                    }
                system("pause");
                break;
            case '5':
                break;
            default:
                break;
            }
        }
    while (opc != '5');
    delete auxNode;
    return 0;
    }
