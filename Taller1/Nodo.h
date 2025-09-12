#pragma once

#include "Alumno.h"
#include "Curso.h"

class NodoAlumno {
public:
    Alumno alumno;
    NodoAlumno* siguiente;
    
    NodoAlumno(Alumno a) {
        alumno = a;
        siguiente = nullptr;
    }
};


class NodoCurso {
public:
    Curso curso;
    NodoCurso* siguiente;
    
    NodoCurso(Curso c) {
        curso = c;
        siguiente = nullptr;
    }
};

class NodoNota {
public:
    int idAlumno;
    string codigoCurso;
    double nota;
    NodoNota* siguiente;
    
    NodoNota(int id, string codigo, double n) {
        idAlumno = id;
        codigoCurso = codigo;
        nota = n;
        siguiente = nullptr;
    }
};

class NodoInscripcion {
public:
    int idAlumno;
    string codigoCurso;
    NodoInscripcion* siguiente;
    
    NodoInscripcion(int id, string codigo) {
        idAlumno = id;
        codigoCurso = codigo;
        siguiente = nullptr;
    }
};