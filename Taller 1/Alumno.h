#include<iostream> 
using namespace std;
#pragma once
class Alumno{
    private:
        int id;
        string nombre;
        string apellido;
        string carrera;
        string fechaIngreso;
    public:
        Alumno(string nombre, string apellido, string carrera, string fechaIngreso);
        int getId();
        string getNombre();
        string getCarrera();
        void mostrarDatos();
        ~Alumno();
    
    
    
};