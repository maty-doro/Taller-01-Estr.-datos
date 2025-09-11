#include <iostream>
#include "Alumno.h"

Alumno::Alumno(string nombre, string apellido, string carrera, string fechaIngreso){
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;
}
void Alumno::mostrarDatos(){
    std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
    std::cout << "Carrera: " << carrera << "fecha de ingreso: "<< fechaIngreso << std::endl;
}