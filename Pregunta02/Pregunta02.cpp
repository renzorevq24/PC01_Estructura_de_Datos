//main.cpp
#include <iostream>
#include <cstdlib> // Para system("cls")
#include "opciones.h"
using namespace std;
void pausarPantalla() {
	cout << "\nPresione ENTER para continuar...";
	cin.get();
}
int main() {
	int opcion;
	int* arreglo = nullptr;
	int tamano = 0;
	do {
		system("cls"); // Limpia la pantalla
		menu();
		cin >> opcion;
		cin.ignore(); // Limpia el buffer del ENTER
		switch (opcion) {
		case 1:
			generarArreglo(&arreglo, tamano);
			break;
		case 2:
			busquedaLineal(arreglo, tamano);
			break;
		case 3:
			busquedaBinaria(arreglo, tamano);
			break;
		case 4:
			comparacionDoble(arreglo, tamano);
			break;
		case 0:
			delete[] arreglo;
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
		if (opcion != 0) {
			pausarPantalla();
		}
	} while (opcion != 0);
	return 0;
}