#pragma once
#include <string>
using namespace std;

class Cinta {
private:
	int nivel;
	string colorCinta;

public:
	Cinta(int nivel);

	void setNivel(int nivel);
	int getNivel();
	string getColorCinta();

	void operator++();
	void operator--();
};