#pragma once

#include <string>
using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

public:
    Alumno();
    Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);

    int getId() ;
    string getNombre();
    string getApellido();
    string getCarrera() ;
    string getFechaIngreso();
    
    void setId(int id);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCarrera(string carrera);
    void setFechaIngreso(string fechaIngreso);
    void mostrarInfo();
};
