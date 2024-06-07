#include "Estudiante.h"
#include <cstdlib>

Estudiante::Estudiante(string nombre, int nivelCinta)
    : nombre(nombre), cinta(new Cinta(nivelCinta)), salud(100) {
    fuerza = rand() % 25 + 26;
    resistencia = rand() % 26;
}

Estudiante::~Estudiante() {
    delete cinta;
}

string Estudiante::getNombre() {
    return nombre;
}

Cinta* Estudiante::getCinta() {
    return cinta;
}

int Estudiante::getFuerza() {
    return fuerza;
}

int Estudiante::getResistencia() {
    return resistencia;
}

double Estudiante::getSalud() {
    return salud;
}

void Estudiante::recibirDanio(double danio) {
    salud -= danio;
    if (salud < 0) salud = 0;
}