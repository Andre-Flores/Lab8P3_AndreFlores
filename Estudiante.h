#include <string>
#include "Cinta.h"
using namespace std;

class Estudiante {
private:
    string nombre;
    Cinta* cinta;
    int fuerza;
    int resistencia;
    double salud;

public:
    Estudiante(string nombre, int nivelCinta);
    ~Estudiante();

    string getNombre();
    Cinta* getCinta();
    int getFuerza();
    int getResistencia();
    double getSalud();
    void recibirDanio(double danio);
};
