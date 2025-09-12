#include <iostream>
#include "Sistema.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== SISTEMA DE GESTIÓN ACADÉMICA ===" << endl;
    cout << "1.  Gestión de Alumnos" << endl;
    cout << "2.  Gestión de Cursos" << endl;
    cout << "3.  Inscripciones" << endl;
    cout << "4.  Gestión de Notas" << endl;
    cout << "5.  Consultas y Reportes" << endl;
    cout << "6.  Salir" << endl;
    cout << "Seleccione una opción: ";
}

void menuAlumnos(Sistema& sistema) {
    int opcionAlm;
    do {
        cout << "\n=== GESTIÓN DE ALUMNOS ===" << endl;
        cout << "1. Crear alumno" << endl;
        cout << "2. Buscar alumno por ID" << endl;
        cout << "3. Buscar alumno por nombre" << endl;
        cout << "4. Eliminar alumno" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Opción: ";
        cin >> opcionAlm;
        
        switch(opcionAlm) {
            case 1:
                sistema.crearAlumno();
                break;
            case 2:
                sistema.buscarAlumnoPorID();
                break;
            case 3:
                sistema.buscarAlumnoPorNombre();
                break;
            case 4:
                sistema.eliminarAlumno();
                break;
            case 5:
                break;
        }
    } while(opcionAlm != 5);
}
void menuCursos(Sistema& sistema) {
    int opcionCursos;
    do {
        cout << "\n=== GESTIÓN DE CURSOS ===" << endl;
        cout << "1. Crear curso" << endl;
        cout << "2. Buscar curso por código" << endl;
        cout << "3. Buscar curso por nombre" << endl;
        cout << "4. Eliminar curso" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Opción: ";
        cin >> opcionCursos;
        
        switch(opcionCursos) {
            case 1:
                sistema.crearCurso();
                break;
            case 2:
                sistema.buscarCursoPorCodigo();
                break;
            case 3:
                sistema.buscarCursoPorNombre();
                break;
            case 4:
                sistema.eliminarCurso();
                break;
            case 5:
                break;
        }
    } while(opcionCursos!= 5);
}

void menuInscripciones(Sistema& sistema) {
    int opcionIns;
    do {
        cout << "\n=== GESTIÓN DE INSCRIPCIONES ===" << endl;
        cout << "1. Inscribir alumno en curso" << endl;
        cout << "2. Eliminar alumno de curso" << endl;
        cout << "3. Volver al menú principal" << endl;
        cout << "Opción: ";
        cin >> opcionIns;
        
        switch(opcionIns) {
            case 1:
                sistema.inscribirAlumno();
                break;
            case 2:
                sistema.eliminarInscripcion();
                break;
            case 3:
                break;
        }
    } while(opcionIns!= 3);
}

void menuNotas(Sistema& sistema) {
    int opcionNot;
    do {
        cout << "\n=== GESTIÓN DE NOTAS ===" << endl;
        cout << "1. Registrar nota" << endl;
        cout << "2. Volver al menú principal" << endl;
        cout << "Opción: ";
        cin >> opcionNot;
        
        switch(opcionNot) {
            case 1:
                sistema.registrarNota();
                break;
            case 2:
                break;
        }
    } while(opcionNot != 2);
}

void menuReportes(Sistema& sistema) {
    int opcionRep;
    do {
        cout << "\n=== CONSULTAS Y REPORTES ===" << endl;
        cout << "1. Alumnos de una carrera" << endl;
        cout << "2. Cursos de un alumno" << endl;
        cout << "3. Promedio de alumno en curso" << endl;
        cout << "4. Promedio general de alumno" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "Opción: ";
        cin >> opcionRep;
        
        switch(opcionRep) {
            case 1:
                sistema.alumnosPorCarrera();
                break;
            case 2:
                sistema.cursosDeAlumno();
                break;
            case 3:
                sistema.promedioAlumnoEnCurso();
                break;
            case 4:
                sistema.promedioGeneralAlumno();
                break;
            case 5:
                break;
                
        }
    } while(opcionRep != 5);
}

int main() {
    Sistema sistema;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                menuAlumnos(sistema);
                break;
            case 2:
                menuCursos(sistema);
                break;
            case 3:
                menuInscripciones(sistema);
                break;
            case 4:
                menuNotas(sistema);
                break;
            case 5:
                menuReportes(sistema);
                break;
            case 6:
                cout << "Gracias por usar el sistema" << endl;
                break;
        }
    } while(opcion != 6);
    
    return 0;
} 