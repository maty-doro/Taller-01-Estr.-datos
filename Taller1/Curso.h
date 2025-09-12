#pragma once

#include <string>
using namespace std;

class Curso {
private:
    string codigo;
    string nombre;
    int maxEstudiantes;
    string carrera;
    string profesor;

public:
    Curso();
    Curso(string codigo, string nombre, int maxEstudiantes, string carrera, string profesor);
    
    string getCodigo();
    string getNombre();
    int getMaxEstudiantes();
    string getCarrera();
    string getProfesor();
    
    void setCodigo(string codigo);
    void setNombre(string nombre);
    void setMaxEstudiantes(int maxEstudiantes);
    void setCarrera(string carrera);
    void setProfesor(string profesor);
    void mostrarInfo();
};
