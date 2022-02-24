#ifndef DIRECTORIO_H_INCLUDED
#define DIRECTORIO_H_INCLUDED
#include <iostream>

using namespace std;

class Directorio {
    private:
        string nombre;
        string apellido;
        string ciudad;
        string correo;
        string genero;
        string estado_civil;
        string numero;
    public:
        Directorio();
        void setNombre(string nom);
        string getNombre();
        void setApellido(string ape);
        string getApellido();
        void setCiudad(string city);
        string getCiudad();
        void setCorreo(string cor);
        string getCorreo();
        void setGenero(char opc);
        string getGenero();
        void setEstadoCivil(char opc);
        string getEstadoCivil();
        void setNumero(string num);
        string getNumero();
};

#endif // DIRECTORIO_H_INCLUDED
