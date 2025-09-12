#pragma once

#include "Nodo.h"

class ListaAlumnos {
private:
    NodoAlumno* cabeza;
    
public:
    ListaAlumnos();
    ~ListaAlumnos();
    
    void insertar(Alumno alumno);
    bool eliminar(int id);
    NodoAlumno* buscarPorId(int id);
    void buscarPorNombre(string nombre);
    void listarPorCarrera(string carrera);
    void mostrarTodos();
    bool estaVacia();
};

class ListaCursos {
private:
    NodoCurso* cabeza;
    
public:
    ListaCursos();
    ~ListaCursos();
    
    void insertar(Curso curso);
    bool eliminar(string codigo);
    NodoCurso* buscarPorCodigo(string codigo);
    void buscarPorNombre(string nombre);
    void mostrarTodos();
    bool estaVacia();
};

class ListaNotas {
private:
    NodoNota* cabeza;
    
public:
    ListaNotas();
    ~ListaNotas();
    
    void insertar(int idAlumno, string codigoCurso, double nota);
    bool eliminarPorAlumno(int idAlumno);
    bool eliminarPorCurso(string codigoCurso);
    double calcularPromedioCurso(int idAlumno, string codigoCurso);
    double calcularPromedioGeneral(int idAlumno);
    void mostrarNotasAlumno(int idAlumno);
    bool estaVacia();
};


class ListaInscripciones {
private:
    NodoInscripcion* cabeza;
    
public:
    ListaInscripciones();
    ~ListaInscripciones();
    
    bool insertar(int idAlumno, string codigoCurso);
    bool eliminar(int idAlumno, string codigoCurso);
    bool eliminarPorAlumno(int idAlumno);
    bool eliminarPorCurso(string codigoCurso);
    bool estaInscrito(int idAlumno, string codigoCurso);
    void mostrarCursosAlumno(int idAlumno);
    int contarAlumnosCurso(string codigoCurso);
    bool estaVacia();
};