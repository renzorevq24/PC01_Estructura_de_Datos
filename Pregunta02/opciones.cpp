//opciones.cpp
#include "opciones.h"
#include <iostream>

/*
 * Autor:	Leonardo Javier Acurio Landa
 * Codigo:	U202312965
 */

void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. Generar arreglo aleatorio" << endl;
	cout << "2. Buscar numero con busqueda lineal (O(n))" << endl;
	cout << "3. Buscar numero con busqueda binaria (O(log n))" << endl;
	cout << "4. Buscar numero con busqueda doble (O(n^2))" << endl;
	cout << "0. Salir" << endl;
	cout << "Seleccione una opcion: ";
}
void generarArreglo(int** arreglo, int& tamano) {
	int nuevoTamano;
	cout << "\nIngrese el tamano del arreglo: ";
	cin >> nuevoTamano;
	tamano = nuevoTamano;

	*arreglo = new int[tamano];

	cout << "\nArreglo generado:";
	for (int i = 0; i < tamano; i++) {
		(*arreglo)[i] = (std::rand() % 10000) + 1;
		if (i == 0) {
			cout << "\n" << (*arreglo)[i];
		}
		else {
			cout << " - " << (*arreglo)[i];
		}
	}
	cin.get();
}
void busquedaLineal(int* arreglo, int tamano) {
	auto inicio = std::chrono::high_resolution_clock::now();

	int valor;
	bool encontrado = false;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;

	for (int i = 0; i < 10; i++) {
		if (arreglo[i] == valor) {
			encontrado = true;
			cout << "\nEl valor " << valor << " fue encontrado en la posicion " << i << endl;
		}
	}
	if (encontrado == false) {
		cout << "El valor ingresado no fue encontrado en el arreglo";
	}

	auto fin = std::chrono::high_resolution_clock::now();
	mostrarTiempo(inicio, fin);
	cin.get();
}
void busquedaBinaria(int* arreglo, int tamano) {
	auto inicio = std::chrono::high_resolution_clock::now();

	int valor;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;

	int* copia = new int[tamano];
	for (int i = 0; i < tamano; i++) {
		copia[i] = arreglo[i];
	}

	std::sort(copia, copia + tamano);
	cout << "\nCon el arreglo ordenado..." << endl;

	int izquierda = 0;
	int derecha = tamano - 1;
	bool encontrado = false;
	int indice = -1;

	while (izquierda <= derecha) {
		int medio = izquierda + (derecha - izquierda) / 2;

		if (copia[medio] == valor) {
			encontrado = true;
			indice = medio;
			break;
		}
		else if (copia[medio] < valor) {
			izquierda = medio + 1;
		}
		else {
			derecha = medio - 1;
		}
	}

	if (encontrado == true) {
		cout << "Elemento " << valor << " encontrado en la posicion " << indice << endl;
	}
	else {
		cout << "Elemento " << valor << " no encontrado en el arreglo." << endl;
	}

	auto fin = std::chrono::high_resolution_clock::now();
	mostrarTiempo(inicio, fin);
	cin.get();

	delete[] copia;
}
void comparacionDoble(int* arreglo, int tamano) {
	auto inicio = std::chrono::high_resolution_clock::now();

	int valor;
	int posicion = 0;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;
	bool encontrado = false;

	for (int i = 0; i < tamano; i++) {
		for (int j = 0; j < tamano; j++) {
			if (arreglo[i] == valor || arreglo[j] == valor) {
				encontrado = true;
			}
		}
	}

	if (encontrado) {
		cout << "\nEl valor " << valor << " fue encontrado en el arreglo." << endl;
	}
	else {
		cout << "\nEl valor " << valor << " no fue encontrado en el arreglo." << endl;
	}

	auto fin = std::chrono::high_resolution_clock::now();
	mostrarTiempo(inicio, fin);
	cin.get();
}

void mostrarTiempo(std::chrono::high_resolution_clock::time_point inicio, std::chrono::high_resolution_clock::time_point fin) {
	auto tiempoEjecucion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
	cout << "\nTiempo de ejecucion fue de " << tiempoEjecucion.count() << " ms.";
}