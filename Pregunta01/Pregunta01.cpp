//PREGUNTA 1 ---->GIANCARLO JOSE VERASTIGUE MARTINEZ (U202419483)
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
	int N = 0;
	do {
		system("cls"); // Limpia la pantalla
		menu();
		cin >> opcion;
		cin.ignore(); // Limpia el buffer del ENTER
		switch (opcion) {
		case 1:
			//int n;
			cout << "Ingresar el tamanio del arreglo : \n"; cin >> N;
			generarArreglo(arreglo, N); cin.get();
			break;
		case 2:
			busquedaLineal(arreglo, N); cin.get();
			break;
		case 3:
			sumarPrim(arreglo); cin.get();
			break;
		case 4:
			busquedaEx(arreglo, N); cin.get();
			break;
		case 5:
			cout << "Saliendo del programa..." << endl;
			break;
		case 6:
			verElementos(arreglo, N);cin.get();
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