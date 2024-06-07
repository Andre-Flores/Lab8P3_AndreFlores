#include "Dojo.h"
#include <iostream>
Dojo::~Dojo() {
	for (Estudiante* student : estudiantes) {
		delete student;
	}
}
void Dojo::agregarEstudiante(string nombre, int nivelCinta) {
	estudiantes.push_back(new Estudiante(nombre, nivelCinta));
}
void Dojo::imprimirEstudiantes() {
	int indice = 0;
	for (Estudiante* student : estudiantes) {

		cout << indice << endl << "Nombre: " << student->getNombre() << endl << "Cinta: " << student->getCinta()->getColorCinta() << endl
			<< "Fuerza: " << student->getFuerza() << endl << "Resistencia: " << student->getResistencia()<< endl <<
			 "Salud: " << student->getSalud() << endl;
		indice++;
	}

}
void Dojo::promoverCinta(int indice) {
	if (indice >= 0 && indice < estudiantes.size()) {
		++(*estudiantes[indice]->getCinta());
	}
}
void Dojo::degradarCinta(int indice) {
	if (indice >= 0 && indice < estudiantes.size()) {
		--(*estudiantes[indice]->getCinta());
	}
}
void Dojo::operator+=(Estudiante* estudiante) {
	estudiantes.push_back(estudiante);
}