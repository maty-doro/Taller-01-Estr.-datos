#include "Lista.h"
#include <iostream>
using namespace std;

ListaAlumnos::ListaAlumnos() {
    cabeza = nullptr;
}

ListaAlumnos::~ListaAlumnos() {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        NodoAlumno* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaAlumnos::insertar(Alumno alumno) {
    NodoAlumno* nuevo = new NodoAlumno(alumno);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

bool ListaAlumnos::eliminar(int id) {
    if (cabeza == nullptr) return false;
    
    if (cabeza->alumno.getId() == id) {
        NodoAlumno* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }
    
    NodoAlumno* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->alumno.getId() != id) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente != nullptr) {
        NodoAlumno* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        return true;
    }
    
    return false;
}

NodoAlumno* ListaAlumnos::buscarPorId(int id) {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        if (actual->alumno.getId() == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaAlumnos::buscarPorNombre(string nombre) {
    NodoAlumno* actual = cabeza;
    bool encontrado = false;
    
    while (actual != nullptr) {
        if (actual->alumno.getNombre() == nombre) {
            actual->alumno.mostrarInfo();
            cout << "-------------------" << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado) {
        cout << "No se encontraron alumnos con ese nombre" << endl;
    }
}

void ListaAlumnos::listarPorCarrera(string carrera) {
    NodoAlumno* actual = cabeza;
    bool encontrado = false;
    
    cout << "Alumnos de " << carrera << ":" << endl;
    while (actual != nullptr) {
        if (actual->alumno.getCarrera() == carrera) {
            actual->alumno.mostrarInfo();
            cout << "-------------------" << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado) {
        cout << "No hay alumnos en esa carrera" << endl;
    }
}

void ListaAlumnos::mostrarTodos() {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        actual->alumno.mostrarInfo();
        cout << "-------------------" << endl;
        actual = actual->siguiente;
    }
}

bool ListaAlumnos::estaVacia() {
    return cabeza == nullptr;
}


ListaCursos::ListaCursos() {
    cabeza = nullptr;
}

ListaCursos::~ListaCursos() {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        NodoCurso* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaCursos::insertar(Curso curso) {
    NodoCurso* nuevo = new NodoCurso(curso);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

bool ListaCursos::eliminar(string codigo) {
    if (cabeza == nullptr) return false;
    
    if (cabeza->curso.getCodigo() == codigo) {
        NodoCurso* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }
    
    NodoCurso* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->curso.getCodigo() != codigo) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente != nullptr) {
        NodoCurso* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        return true;
    }
    
    return false;
}

NodoCurso* ListaCursos::buscarPorCodigo(string codigo) {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        if (actual->curso.getCodigo() == codigo) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaCursos::buscarPorNombre(string nombre) {
    NodoCurso* actual = cabeza;
    bool encontrado = false;
    
    while (actual != nullptr) {
        if (actual->curso.getNombre() == nombre) {
            actual->curso.mostrarInfo();
            cout << "-------------------" << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado) {
        cout << "No se encontraron cursos con ese nombre" << endl;
    }
}

void ListaCursos::mostrarTodos() {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        actual->curso.mostrarInfo();
        cout << "-------------------" << endl;
        actual = actual->siguiente;
    }
}

bool ListaCursos::estaVacia() {
    return cabeza == nullptr;
}


ListaNotas::ListaNotas() {
    cabeza = nullptr;
}

ListaNotas::~ListaNotas() {
    NodoNota* actual = cabeza;
    while (actual != nullptr) {
        NodoNota* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaNotas::insertar(int idAlumno, string codigoCurso, double nota) {
    NodoNota* nuevo = new NodoNota(idAlumno, codigoCurso, nota);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

bool ListaNotas::eliminarPorAlumno(int idAlumno) {
    bool eliminado = false;
    
    while (cabeza != nullptr && cabeza->idAlumno == idAlumno) {
        NodoNota* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        eliminado = true;
    }
    
    NodoNota* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->siguiente->idAlumno == idAlumno) {
            NodoNota* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            eliminado = true;
        } else {
            actual = actual->siguiente;
        }
    }
    
    return eliminado;
}

bool ListaNotas::eliminarPorCurso(string codigoCurso) {
    bool eliminado = false;
    
    while (cabeza != nullptr && cabeza->codigoCurso == codigoCurso) {
        NodoNota* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        eliminado = true;
    }
    
    NodoNota* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->siguiente->codigoCurso == codigoCurso) {
            NodoNota* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            eliminado = true;
        } else {
            actual = actual->siguiente;
        }
    }
    
    return eliminado;
}

double ListaNotas::calcularPromedioCurso(int idAlumno, string codigoCurso) {
    NodoNota* actual = cabeza;
    double suma = 0;
    int contador = 0;
    
    while (actual != nullptr) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            suma += actual->nota;
            contador++;
        }
        actual = actual->siguiente;
    }
    
    return (contador > 0) ? suma / contador : 0;
}

double ListaNotas::calcularPromedioGeneral(int idAlumno) {
    NodoNota* actual = cabeza;
    string cursosVistos[100];
    double promediosCursos[100];
    int numCursos = 0;
    
    while (actual != nullptr) {
        if (actual->idAlumno == idAlumno) {
            bool cursoExistente = false;
            for (int i = 0; i < numCursos; i++) {
                if (cursosVistos[i] == actual->codigoCurso) {
                    cursoExistente = true;
                    break;
                }
            }
            
            if (!cursoExistente) {
                cursosVistos[numCursos] = actual->codigoCurso;
                promediosCursos[numCursos] = calcularPromedioCurso(idAlumno, actual->codigoCurso);
                numCursos++;
            }
        }
        actual = actual->siguiente;
    }
    
    if (numCursos == 0) return 0;
    
    double suma = 0;
    for (int i = 0; i < numCursos; i++) {
        suma += promediosCursos[i];
    }
    
    return suma / numCursos;
}

void ListaNotas::mostrarNotasAlumno(int idAlumno) {
    NodoNota* actual = cabeza;
    bool encontrado = false;
    
    while (actual != nullptr) {
        if (actual->idAlumno == idAlumno) {
            cout << "Curso: " << actual->codigoCurso << " - Nota: " << actual->nota << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado) {
        cout << "No hay notas para este alumno" << endl;
    }
}

bool ListaNotas::estaVacia() {
    return cabeza == nullptr;
}


ListaInscripciones::ListaInscripciones() {
    cabeza = nullptr;
}

ListaInscripciones::~ListaInscripciones() {
    NodoInscripcion* actual = cabeza;
    while (actual != nullptr) {
        NodoInscripcion* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

bool ListaInscripciones::insertar(int idAlumno, string codigoCurso) {
    if (estaInscrito(idAlumno, codigoCurso)) {
        return false;
    }
    
    NodoInscripcion* nuevo = new NodoInscripcion(idAlumno, codigoCurso);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    return true;
}

bool ListaInscripciones::eliminar(int idAlumno, string codigoCurso) {
    if (cabeza == nullptr) return false;
    
    if (cabeza->idAlumno == idAlumno && cabeza->codigoCurso == codigoCurso) {
        NodoInscripcion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }
    
    NodoInscripcion* actual = cabeza;
    while (actual->siguiente != nullptr) {
        if (actual->siguiente->idAlumno == idAlumno && 
            actual->siguiente->codigoCurso == codigoCurso) {
            NodoInscripcion* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return true;
        }
        actual = actual->siguiente;
    }
    
    return false;
}

bool ListaInscripciones::eliminarPorAlumno(int idAlumno) {
    bool eliminado = false;
    
    while (cabeza != nullptr && cabeza->idAlumno == idAlumno) {
        NodoInscripcion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        eliminado = true;
    }
    
    NodoInscripcion* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->siguiente->idAlumno == idAlumno) {
            NodoInscripcion* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            eliminado = true;
        } else {
            actual = actual->siguiente;
        }
    }
    
    return eliminado;
}

bool ListaInscripciones::eliminarPorCurso(string codigoCurso) {
    bool eliminado = false;
    
    while (cabeza != nullptr && cabeza->codigoCurso == codigoCurso) {
        NodoInscripcion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        eliminado = true;
    }
    
    NodoInscripcion* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        if (actual->siguiente->codigoCurso == codigoCurso) {
            NodoInscripcion* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            eliminado = true;
        } else {
            actual = actual->siguiente;
        }
    }
    
    return eliminado;
}

bool ListaInscripciones::estaInscrito(int idAlumno, string codigoCurso) {
    NodoInscripcion* actual = cabeza;
    while (actual != nullptr) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void ListaInscripciones::mostrarCursosAlumno(int idAlumno) {
    NodoInscripcion* actual = cabeza;
    bool encontrado = false;
    
    cout << "Cursos del alumno ID " << idAlumno << ":" << endl;
    while (actual != nullptr) {
        if (actual->idAlumno == idAlumno) {
            cout << "- " << actual->codigoCurso << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado) {
        cout << "El alumno no está inscrito en ningún curso" << endl;
    }
}

int ListaInscripciones::contarAlumnosCurso(string codigoCurso) {
    NodoInscripcion* actual = cabeza;
    int contador = 0;
    
    while (actual != nullptr) {
        if (actual->codigoCurso == codigoCurso) {
            contador++;
        }
        actual = actual->siguiente;
    }
    
    return contador;
}

bool ListaInscripciones::estaVacia() {
    return cabeza == nullptr;
}