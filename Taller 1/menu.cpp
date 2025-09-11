#include <iostream>
#include "menu.h"
#include "Alumno.h"
#include "AlumList.h"
using namespace std;
void menu::mostrarMenuPrincipal() {
	std::cout << "---Bienvenido---" << std::endl;
	std::cout << "1. Gestionar Alumnos." << std::endl;
	std::cout << "2. Gestionar Cursos." << std::endl;
	std::cout << "3. Gestionar inscripciones." << std::endl;
	std::cout << "4. Registrar notas." << std::endl;
	std::cout << "5. Consultas o reportes." << std::endl;
	std::cout << "6. Salir." << std::endl;

	do {
		std::cin>> opcion;
		switch(opcion) {

		case 1:
			menuAlumno();
			break;
			/*
			case 2:
			    menuRamo();
			    break;
			case 3:
			    menuIncripcion();
			    break;
			case 4:
			    menuNotas();
			    break;
			case 5:
			    menuReportes();
			    break;
			case 6:
			    std::cout << "Saliendo..." << std::endl;
			    break;

			default:
			    std::cout << "Error" << std::endl;
			    break;
			*/
		}
	} while(opcion!=6);


}

void menu::menuAlumno() {
	int optAlumn;
	std::cout << "---GESTION DE ALUMNOS---" << std::endl;
	std::cout << "1. Ingresar Alumno." << std::endl;
	std::cout << "2. Buscar Alumno por nombre." << std::endl;
	std::cout << "3. Buscar Alumno por Id." << std::endl;
	std::cout << "4. Eliminar Alumno." << std::endl;
	std::cout << "5. Salir." << std::endl;
	do {
		std::cin>>optAlumn;
		switch(optAlumn) {
		case 1:
			string Name,Apellido,Carrera,fechaI;
			std::cout << "Ingrese Nombre: " << std::endl;
			std::cin >> Name;
			std::cout << "Ingrese Apellido: " << std::endl;
			std::cin >> Apellido;
			std::cout << "Ingrese Carrera: " << std::endl;
			std::cin >> Carrera;
			std::cout << "Ingrese Fecha de ingreso(ej: 01-12-2023): "<<endl;
			std::cin >> fechaI;
			listaAlumnos->agregarAlumno(new Alumno(Name,Apellido,Carrera,fechaI));
			
			
			break;
		}
	} while(optAlumn!=5);


}

