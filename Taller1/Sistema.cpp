#include "Sistema.h"
#include <iostream>
#include <limits>
using namespace std;

Sistema::Sistema() {
}

Sistema::~Sistema() {
}

void Sistema::crearAlumno() {
    int id;
    string nombre, apellido, carrera, fechaIngreso;
    
    cout << "\n=== CREAR ALUMNO ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    
    if (existeAlumno(id)) {
        cout << "Error: Ya existe un alumno con ese ID" << endl;
        return;
    }
    
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellido: ";
    getline(cin, apellido);
    cout << "Carrera: ";
    getline(cin, carrera);
    cout << "Fecha de ingreso (DD/MM/AAAA): ";
    getline(cin, fechaIngreso);
    
    Alumno nuevoAlumno(id, nombre, apellido, carrera, fechaIngreso);
    alumnos.insertar(nuevoAlumno);
    
    cout << "Alumno creado exitosamente" << endl;
}

void Sistema::buscarAlumnoPorID() {
    int id;
    cout << "\n=== BUSCAR ALUMNO POR ID ===" << endl;
    cout << "Ingrese el ID: ";
    cin >> id;
    
    NodoAlumno* nodo = alumnos.buscarPorId(id);
    if (nodo != nullptr) {
        nodo->alumno.mostrarInfo();
    } else {
        cout << "No se encontró alumno con ese ID" << endl;
    }
}

void Sistema::buscarAlumnoPorNombre() {
    string nombre;
    cout << "\n=== BUSCAR ALUMNO POR NOMBRE ===" << endl;
    cin.ignore();
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    
    alumnos.buscarPorNombre(nombre);
}

void Sistema::eliminarAlumno() {
    int id;
    cout << "\n=== ELIMINAR ALUMNO ===" << endl;
    cout << "Ingrese el ID del alumno a eliminar: ";
    cin >> id;
    
    if (!existeAlumno(id)) {
        cout << "No existe alumno con ese ID" << endl;
        return;
    }
    
    inscripciones.eliminarPorAlumno(id);
    notas.eliminarPorAlumno(id);
    
    if (alumnos.eliminar(id)) {
        cout << "Alumno eliminado exitosamente" << endl;
    } else {
        cout << "Error al eliminar alumno" << endl;
    }
}

void Sistema::crearCurso() {
    string codigo, nombre, carrera, profesor;
    int maxEstudiantes;
    
    cout << "\n=== CREAR CURSO ===" << endl;
    cin.ignore();
    cout << "Código del curso: ";
    getline(cin, codigo);
    
    if (existeCurso(codigo)) {
        cout << "Error: Ya existe un curso con ese código" << endl;
        return;
    }
    
    cout << "Nombre del curso: ";
    getline(cin, nombre);
    cout << "Carrera: ";
    getline(cin, carrera);
    cout << "Profesor: ";
    getline(cin, profesor);
    cout << "Máximo de estudiantes: ";
    cin >> maxEstudiantes;
    
    if (maxEstudiantes <= 0) {
        cout << "Error: El máximo de estudiantes debe ser positivo" << endl;
        return;
    }
    
    Curso nuevoCurso(codigo, nombre, maxEstudiantes, carrera, profesor);
    cursos.insertar(nuevoCurso);
    
    cout << "Curso creado exitosamente" << endl;
}

void Sistema::buscarCursoPorCodigo() {
    string codigo;
    cout << "\n=== BUSCAR CURSO POR CÓDIGO ===" << endl;
    cin.ignore();
    cout << "Ingrese el código: ";
    getline(cin, codigo);
    
    NodoCurso* nodo = cursos.buscarPorCodigo(codigo);
    if (nodo != nullptr) {
        nodo->curso.mostrarInfo();
    } else {
        cout << "No se encontró curso con ese código" << endl;
    }
}

void Sistema::buscarCursoPorNombre() {
    string nombre;
    cout << "\n=== BUSCAR CURSO POR NOMBRE ===" << endl;
    cin.ignore();
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    
    cursos.buscarPorNombre(nombre);
}

void Sistema::eliminarCurso() {
    string codigo;
    cout << "\n=== ELIMINAR CURSO ===" << endl;
    cin.ignore();
    cout << "Ingrese el código del curso a eliminar: ";
    getline(cin, codigo);
    
    if (!existeCurso(codigo)) {
        cout << "No existe curso con ese código" << endl;
        return;
    }
    
    inscripciones.eliminarPorCurso(codigo);
    notas.eliminarPorCurso(codigo);
    
    if (cursos.eliminar(codigo)) {
        cout << "Curso eliminado exitosamente" << endl;
    } else {
        cout << "Error al eliminar curso" << endl;
    }
}
void Sistema::inscribirAlumno() {
    int id;
    string codigo;
    
    cout << "\n=== INSCRIBIR ALUMNO ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    cin.ignore();
    cout << "Código del curso: ";
    getline(cin, codigo);
    
    if (!existeAlumno(id)) {
        cout << "Error: No existe alumno con ese ID" << endl;
        return;
    }
    
    if (!existeCurso(codigo)) {
        cout << "Error: No existe curso con ese código" << endl;
        return;
    }
    
    NodoAlumno* nodoAlumno = alumnos.buscarPorId(id);
    NodoCurso* nodoCurso = cursos.buscarPorCodigo(codigo);
    
    if (nodoAlumno->alumno.getCarrera() != nodoCurso->curso.getCarrera()) {
        cout << "Error: El alumno no puede inscribirse en un curso de otra carrera" << endl;
        return;
    }
    
    int alumnosInscritos = inscripciones.contarAlumnosCurso(codigo);
    if (alumnosInscritos >= nodoCurso->curso.getMaxEstudiantes()) {
        cout << "Error: El curso ha alcanzado su máximo de estudiantes" << endl;
        return;
    }
    
    if (inscripciones.insertar(id, codigo)) {
        cout << "Alumno inscrito exitosamente" << endl;
    } else {
        cout << "Error: El alumno ya está inscrito en este curso" << endl;
    }
}

void Sistema::eliminarInscripcion() {
    int id;
    string codigo;
    
    cout << "\n=== ELIMINAR INSCRIPCIÓN ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    cin.ignore();
    cout << "Código del curso: ";
    getline(cin, codigo);
    
    if (inscripciones.eliminar(id, codigo)) {
        cout << "Inscripción eliminada exitosamente" << endl;
    } else {
        cout << "Error: No se encontró la inscripción" << endl;
    }
}

void Sistema::registrarNota() {
    int id;
    string codigo;
    double nota;
    
    cout << "\n=== REGISTRAR NOTA ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    cin.ignore();
    cout << "Código del curso: ";
    getline(cin, codigo);
    cout << "Nota (1.0 - 7.0): ";
    cin >> nota;
    if (!inscripciones.estaInscrito(id, codigo)) {
        cout << "Error: El alumno no está inscrito en este curso" << endl;
        return;
    }
    
    if (!validarNota(nota)) {
        cout << "Error: La nota debe estar entre 1.0 y 7.0" << endl;
        return;
    }
    
    notas.insertar(id, codigo, nota);
    cout << "Nota registrada exitosamente" << endl;
}

void Sistema::alumnosPorCarrera() {
    string carrera;
    cout << "\n=== ALUMNOS POR CARRERA ===" << endl;
    cin.ignore();
    cout << "Ingrese la carrera: ";
    getline(cin, carrera);
    
    alumnos.listarPorCarrera(carrera);
}

void Sistema::cursosDeAlumno() {
    int id;
    cout << "\n=== CURSOS DE ALUMNO ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    
    if (!existeAlumno(id)) {
        cout << "No existe alumno con ese ID" << endl;
        return;
    }
    
    inscripciones.mostrarCursosAlumno(id);
}

void Sistema::promedioAlumnoEnCurso() {
    int id;
    string codigo;
    
    cout << "\n=== PROMEDIO DE ALUMNO EN CURSO ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    cin.ignore();
    cout << "Código del curso: ";
    getline(cin, codigo);
    
    if (!inscripciones.estaInscrito(id, codigo)) {
        cout << "El alumno no está inscrito en este curso" << endl;
        return;
    }
    
    double promedio = notas.calcularPromedioCurso(id, codigo);
    if (promedio > 0) {
        cout << "Promedio en el curso: " << promedio << endl;
    } else {
        cout << "No hay notas registradas para este alumno en este curso" << endl;
    }
}

void Sistema::promedioGeneralAlumno() {
    int id;
    cout << "\n=== PROMEDIO GENERAL DE ALUMNO ===" << endl;
    cout << "ID del alumno: ";
    cin >> id;
    
    if (!existeAlumno(id)) {
        cout << "No existe alumno con ese ID" << endl;
        return;
    }
    
    double promedio = notas.calcularPromedioGeneral(id);
    if (promedio > 0) {
        cout << "Promedio general: " << promedio << endl;
    } else {
        cout << "No hay notas registradas para este alumno" << endl;
    }
}

bool Sistema::validarNota(double nota) {
    return nota >= 1.0 && nota <= 7.0;
}

bool Sistema::existeAlumno(int id) {
    return alumnos.buscarPorId(id) != nullptr;
}

bool Sistema::existeCurso(string codigo) {
    return cursos.buscarPorCodigo(codigo) != nullptr;
}