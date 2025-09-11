#include <iostream>
#include "NodoGral.h"
#include "Alumno.h"
using namespace std;
class AlumList{
    private:
    NodoGral<Alumno>* top;
    
    public:
    AlumList();
    void agregarAlumno(Alumno Student);
    void datos();
    void buscar(string nombreBuscado);
    void buscar(int idBuscado);
    
    
    
};