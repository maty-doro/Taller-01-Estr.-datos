#pragma once

#include "Lista.h"

class Sistema {
private:
    ListaAlumnos alumnos;
    ListaCursos cursos;
    ListaNotas notas;
    ListaInscripciones inscripciones;
    
public:
    Sistema();
    ~Sistema();
    
    void crearAlumno();
    void buscarAlumnoPorID();
    void buscarAlumnoPorNombre();
    void eliminarAlumno();
    
    void crearCurso();
    void buscarCursoPorCodigo();
    void buscarCursoPorNombre();
    void eliminarCurso();
    
    void inscribirAlumno();
    void eliminarInscripcion();
    
    void registrarNota();
    
    void alumnosPorCarrera();
    void cursosDeAlumno();
    void promedioAlumnoEnCurso();
    void promedioGeneralAlumno();
    
    bool validarNota(double nota);
    bool existeAlumno(int id);
    bool existeCurso(string codigo);
};