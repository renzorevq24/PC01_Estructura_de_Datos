//main.cpp
#include <iostream>
#include <cstdlib> // Para system("cls")
#include "opciones.h"
#include <vector>
using namespace std;
void pausarPantalla() {
	cout << "\nPresione ENTER para continuar...";
	cin.get();
}
int main() {
	int opcion;
	vector<int>* numeros = nullptr;
	do {
		system("cls"); // Limpia la pantalla
		menu();
		cin >> opcion;
		cin.ignore(); // Limpia el buffer del ENTER
		switch (opcion) {
		case 1:
			generarVectorAleatorio(numeros); cin.get();
			break;
		case 2:
			contarImpares(numeros);
			break;
		case 3:
			buscarDuplicados(numeros);
			break;
		case 4:
			mostrarPrimerElemento(numeros);
			break;
		case 5:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
		if (opcion != 5) {
			pausarPantalla();
		}
	} while (opcion != 5);
	return 0;
}