#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;
/*
 * Autor:	Renzo Zamir Revilla Quispe
 * Codigo:	U201717085
 */
void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. Generar vector aleatorio" << endl;
	cout << "2. Contar impares con count_if (O(n))" << endl;
	cout << "3. Detectar duplicados tras ordenar (O(n log n))" << endl;
	cout << "4. Mostrar primer elemento (O(1))" << endl;
	cout << "5. Salir" << endl;
	cout << "Seleccione una opcion: ";
}


void mostrarVector(vector<int>* numeros) {
	for (int i = 0; i < numeros->size(); i++) {
		cout << (*numeros)[i];
		if (i != numeros->size() - 1) {
			cout << " - ";
		}
	}
	cout << endl;
}

void generarVectorAleatorio(vector<int>*& numeros) {
	int tamanio;
	cout << "\nIngrese el tamanio del vector aleatorio: "; cin >> tamanio;

	numeros = new vector<int>(tamanio);
	for (int i = 0; i < tamanio; i++) {
		(*numeros)[i] = 1 + rand() % 10000;
	}

	cout << "\nLos numeros generados fueron: \n";
	mostrarVector(numeros);
}

void mostrarTiempoEjecucion(high_resolution_clock::time_point inicio, high_resolution_clock::time_point fin, string complejidad) {
	auto tiempoEjecucion = duration_cast<microseconds>(fin - inicio);
	cout << "\nTiempo de ejecucion fue de " << tiempoEjecucion.count() << " ms.";
	cout << "\nComplejidad Big-O: " << complejidad << endl;
}

void contarImpares(vector<int>* numeros) {
	auto inicio = high_resolution_clock::now();

	if (numeros->empty()) {
		cout << "\nEl vector esta vacio.\n";
		return;
	}

	int ultimoValorEvaluado = 0;
	auto esImpar = [&ultimoValorEvaluado](int n) -> bool {
		ultimoValorEvaluado = n;
		return n % 2 != 0;
		};
	auto cantidadImpares = count_if(numeros->begin(), numeros->end(), esImpar);

	cout << "\nLa cantidad de numeros impares es: " << cantidadImpares << endl;
	cout << "\nEn el vector generado: \n";
	mostrarVector(numeros);
	cout << "\nUltimo valor evaluado: " << ultimoValorEvaluado << endl;

	auto fin = high_resolution_clock::now();
	mostrarTiempoEjecucion(inicio, fin, "O(n)");
}

void buscarDuplicados(vector<int>* numeros) {
	auto inicio = high_resolution_clock::now();
	if (numeros->empty()) {
		cout << "\nEl vector esta vacio.\n";
		return;
	}

	sort(numeros->begin(), numeros->end());

	cout << "\nEl vector ordenado es: \n";
	mostrarVector(numeros);
	cout << endl;

	bool existeDuplicados = false;

	for (int i = 0; i < numeros->size(); i++) {
		if (i != numeros->size() - 1) {
			if ((*numeros)[i] == (*numeros)[i + 1]) {
				existeDuplicados = true;
				break;
			}
		}
	}

	cout << "Existen duplicados: " << (existeDuplicados ? "Si" : "No") << endl;

	auto fin = high_resolution_clock::now();
	mostrarTiempoEjecucion(inicio, fin, "O(n.log(n))");
}

void mostrarPrimerElemento(vector<int>* numeros) {
	auto inicio = high_resolution_clock::now();
	if (numeros->empty()) {
		cout << "\nEl vector esta vacio.\n";
		return;
	}

	cout << "\nEl primer elemento es: " << numeros->front() << endl;

	cout << "\nEn el vector generado: \n";
	mostrarVector(numeros);

	auto fin = high_resolution_clock::now();
	mostrarTiempoEjecucion(inicio, fin, "O(1)");
}