#include "Curso.h"
#include <iostream>
using namespace std;

Curso::Curso() {
    codigo = "";
    nombre = "";
    maxEstudiantes = 0;
    carrera = "";
    profesor = "";
}

Curso::Curso(string codigo, string nombre, int maxEstudiantes, string carrera, string profesor) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->maxEstudiantes = maxEstudiantes;
    this->carrera = carrera;
    this->profesor = profesor;
}

string Curso::getCodigo(){
    return codigo;
}

string Curso::getNombre() {
    return nombre;
}

int Curso::getMaxEstudiantes(){
    return maxEstudiantes;
}

string Curso::getCarrera(){
    return carrera;
}

string Curso::getProfesor(){
    return profesor;
}

void Curso::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

void Curso::setMaxEstudiantes(int maxEstudiantes) {
    this->maxEstudiantes = maxEstudiantes;
}

void Curso::setCarrera(string carrera) {
    this->carrera = carrera;
}

void Curso::setProfesor(string profesor) {
    this->profesor = profesor;
}

void Curso::mostrarInfo(){
    cout << "Código: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Máximo estudiantes: " << maxEstudiantes << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Profesor: " << profesor << endl;
}