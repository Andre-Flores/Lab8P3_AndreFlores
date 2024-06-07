#pragma once
#include <vector>
#include "Estudiante.h"
#include <string>
using namespace std;

class Dojo {
private:
	vector<Estudiante*> estudiantes;

public:
	~Dojo();
	void agregarEstudiante(string nombre, int nivelCinta);
	void imprimirEstudiantes();
	void promoverCinta(int indice);
	void degradarCinta(int indice);
	void combate(int indice1, int indice2);
	void operator+=(Estudiante* estudiante);
};