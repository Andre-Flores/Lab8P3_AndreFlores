#include "Cinta.h"

Cinta::Cinta(int nivel) {
	setNivel(nivel);
}

void Cinta::setNivel(int nivel) {
	this->nivel = nivel;
	switch (nivel) {
	case 1: colorCinta = "Blanco"; break;
	case 2: colorCinta = "Amarillo"; break;
	case 3: colorCinta = "Naranja"; break;
	case 4: colorCinta = "Verde"; break;
	case 5: colorCinta = "Azul"; break;
	case 6: colorCinta = "Marrón"; break;
	case 7: colorCinta = "Negro"; break;
	}
}

int Cinta::getNivel() {
	return nivel;
}

string Cinta::getColorCinta() {
	return colorCinta;
}

void Cinta::operator++() {
	if (nivel < 7) setNivel(nivel + 1);
}

void Cinta::operator--() {
	if (nivel > 1) setNivel(nivel - 1);
}