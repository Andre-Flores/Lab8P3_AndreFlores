#include "Dojo.h"
#include <iostream>
using namespace std;
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
			<< "Fuerza: " << student->getFuerza() << endl << "Resistencia: " << student->getResistencia() << endl <<
			"Salud: " << student->getSalud() << endl << endl;
		indice++;
	}

}
void Dojo::promoverCinta(int indice) {
	if (indice >= 0 && indice < estudiantes.size()) {
		++(*estudiantes[indice]->getCinta());
		cout << "estudiante promovido exitosamente!" << endl;
	}
}
void Dojo::degradarCinta(int indice) {
	if (indice >= 0 && indice < estudiantes.size()) {
		--(*estudiantes[indice]->getCinta());
		cout << "estudiante degradado exitosamente!" << endl;
	}
}

void Dojo::combate(int indice1, int indice2) {
	double porcentajeCinta;
	double porcentajeCinta2;
	if (indice1 >= 0 && indice1 < estudiantes.size() &&
		indice2 >= 0 && indice2 < estudiantes.size()) {
		Estudiante* student1 = estudiantes[indice1];
		Estudiante* student2 = estudiantes[indice2];
		if (student1->getCinta()->getNivel() == 1) {
			porcentajeCinta = 0.4;
		}
		else if (student1->getCinta()->getNivel() == 2) {
			porcentajeCinta = 0.5;
		}
		else if (student1->getCinta()->getNivel() == 3) {
			porcentajeCinta = 0.6;
		}
		else if (student1->getCinta()->getNivel() == 4) {
			porcentajeCinta = 0.7;
		}
		else if (student1->getCinta()->getNivel() == 5) {
			porcentajeCinta = 0.8;
		}
		else if (student1->getCinta()->getNivel() == 6) {
			porcentajeCinta = 0.9;
		}
		else if (student1->getCinta()->getNivel() == 7) {
			porcentajeCinta = 1.0;
		}
		// para el porcentaje
		if (student2->getCinta()->getNivel() == 1) {
			porcentajeCinta2 = 0.4;
		}
		else if (student2->getCinta()->getNivel() == 2) {
			porcentajeCinta2 = 0.5;
		}
		else if (student2->getCinta()->getNivel() == 3) {
			porcentajeCinta2 = 0.6;
		}
		else if (student2->getCinta()->getNivel() == 4) {
			porcentajeCinta2 = 0.7;
		}
		else if (student2->getCinta()->getNivel() == 5) {
			porcentajeCinta2 = 0.8;
		}
		else if (student2->getCinta()->getNivel() == 6) {
			porcentajeCinta2 = 0.9;
		}
		else if (student2->getCinta()->getNivel() == 7) {
			porcentajeCinta2 = 1.0;
		}
		while (student1->getSalud() > 0 && student2->getSalud() > 0) {
			cout << "Ataca " << student1->getNombre() << endl;
			double ataque1 = student1->getFuerza() * porcentajeCinta * (student1->getSalud() / 10.0);
			cout << "Ataque del Estudiante 1 = " << ataque1 << endl;
			double defensa2 = student2->getResistencia() * porcentajeCinta2 * (student2->getSalud()/ 10.0);
			cout << "Defensa del Estudiante 2 = " << defensa2 << endl;
			double danio1 = (ataque1 - defensa2);
			cout << "Ataque total del Estudiante 1 = " << danio1 << endl;
			student2->recibirDanio(danio1);
			cout << "vida del estudiante 2 después de recibir el ataque = " << student2->getSalud() << endl << endl;
			if (student2->getSalud() <= 0) {
				cout << student1->getNombre() << " ha ganado!" << endl;
				break;
			}
			cout << "Ataca " << student2->getNombre() << endl;
			double ataque2 = student2->getFuerza() * porcentajeCinta2 * (student2->getSalud() / 10.0);
			cout << "Ataque del Estudiante 2 = " << ataque2 << endl;
			double defensa1 = student1->getResistencia() * porcentajeCinta * (student1->getSalud() / 10.0);
			cout << "Defensa del Estudiante 1 = " << defensa1 << endl;
			double danio2 = (ataque2 - defensa1);
			cout << "Ataque total del Estudiante 2 = " << danio2 << endl;
			student1->recibirDanio(danio2);
			cout << "vida del estudiante 1 después de recibir el ataque = " << student1->getSalud() << endl << endl;
			if (student1->getSalud() <= 0) {
				cout << student2->getNombre() << " ha ganado!" << endl;
				break;
			}
		}
	}
}

void Dojo::operator+=(Estudiante* estudiante) {
	estudiantes.push_back(estudiante);
}