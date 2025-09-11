#include <iostream>
#include "AlumList.h"
using namespace std;
AlumList::AlumList(){
    top = nullptr;
}
void AlumList::agregarAlumno(Alumno Student){
    NodoGral<Alumno>* mechon = new NodoGral<Alumno>(Student);
    if(top == nullptr){
        top = mechon;
    }else{
        NodoGral<Alumno>* cursor = top;
        while(cursor->sgt != nullptr){
            cursor = cursor->sgt;
        }
        cursor->sgt = mechon;
    }
}
void AlumList::mostrarAlumnos() {
    NodoGral<Alumno>* cursor = top;
    while (cursor != nullptr) {
        // Mostrar el valor (alumno) en cada nodo
        std::cout << "Nombre: " << cursor->valor.getNombre() << ", "
                  << "Apellido: " << cursor->valor.getApellido() << ", "
                  << "Carrera: " << cursor->valor.getCarrera() << std::endl;
        cursor = cursor->sgt;
    }
}