#include <iostream>
#include "AlumList.h"

class menu{
    private:
    int opcion;
    AlumList listaAlumnos;
    public:
    void mostrarMenuPrincipal();
    void menuAlumno();
    void menuRamo();
    void menuIncripcion();
    void menuNotas();
    void menuReportes();
    
};