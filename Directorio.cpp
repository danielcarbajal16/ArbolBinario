#include "Directorio.h"

Directorio::Directorio() {
    nombre = "";
    apellido = "";
    ciudad = "";
    correo = "";
    genero = "";
    estado_civil = "";
    numero = "";
}

void Directorio::setNombre(string nom) {
    nombre = nom;
}

string Directorio::getNombre() {
    return nombre;
}

void Directorio::setApellido(string ape) {
    apellido = ape;
}

string Directorio::getApellido() {
    return apellido;
}

void Directorio::setCiudad(string city) {
    ciudad = city;
}

string Directorio::getCiudad() {
    return ciudad;
}

void Directorio::setCorreo(string cor) {
    correo = cor;
}

string Directorio::getCorreo() {
    return correo;
}

void Directorio::setGenero(char opc) {
    if (opc == '1')
        genero = "Masculino";
    else if (opc == '2')
        genero = "Femenino";
    else if (opc == '3')
        genero = "Indefinido";
}

string Directorio::getGenero() {
    return genero;
}

void Directorio::setEstadoCivil(char opc) {
    if (opc == '1')
        estado_civil = "Casado";
    else if (opc == '2')
        estado_civil = "Soltero";
    else if (opc == '3')
        estado_civil = "Divorciado";
    else if (opc == '4')
        estado_civil = "En pareja";
}

string Directorio::getEstadoCivil() {
    return estado_civil;
}

void Directorio::setNumero(string num) {
    numero = num;
}

string Directorio::getNumero() {
    return numero;
}
