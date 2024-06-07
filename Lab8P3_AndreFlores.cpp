#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Dojo.h"
using namespace std;
void menu();
int main() {
	setlocale(LC_ALL, "spanish");
	srand(time(0));
	menu();
	return 0;
}

void menu() {
    Dojo dojo;
    int opcion;
    do {
        cout << "----Menú----" << endl;
        cout << "1. Agregar Estudiante" << endl;
        cout << "2. Listar Estudiantes" << endl;
        cout << "3. Promover Cinta" << endl;
        cout << "4. Degradar Cinta" << endl;
        cout << "5. Combate" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombre;
            int nivelCinta;
            cout << "Nombre: ";
            cin >> nombre;
            do {
                cout << "Nivel del estudiante (1-7): ";
                cin >> nivelCinta;
            } while (nivelCinta < 1 || nivelCinta >7);
            dojo.agregarEstudiante(nombre, nivelCinta);
            break;
        }
        case 2:
            dojo.imprimirEstudiantes();
            break;
        case 3: {
            int indice;
            dojo.imprimirEstudiantes();
            cout << "Ingrese el indice del estudiante a promover: ";
            cin >> indice;
            dojo.promoverCinta(indice);
            break;
        }
        case 4: {
            int indice;
            dojo.imprimirEstudiantes();
            cout << "Ingrese el indice del estudiante a degradar: ";
            cin >> indice;
            dojo.degradarCinta(indice);
            break;
        }
        case 5: {
            int indice1, indice2;
            cout << "Ingrese el indice del primer estudiante: ";
            cin >> indice1;
            cout << "Ingrese el indice del segundo estudiante: ";
            cin >> indice2;
            //dojo.combate(indice1, indice2);
            break;
        }
        case 6:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}