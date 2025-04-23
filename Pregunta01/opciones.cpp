#include <iostream>
#include <random>
#include <set>
#include <chrono>
using namespace std;
void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. Generar arreglo aleatorio " << endl;
	cout << "2. Buscar numero con busqueda lineal (O(n))" << endl;
	cout << "3. Sumar N al primimer elemento (O(1))" << endl;
	cout << "4. Buscar numero con comparacion doble (O(n^2))" << endl;
	cout << "5. Salir" << endl;
	cout << "Seleccione una opcion: ";
}
void generarArreglo(int*& arreglo, int N) {

	random_device rd;
	mt19937 gen(rd());  // Motor Mersenne Twister
	uniform_int_distribution<> distrib(1, 5000);


	int* arr = new int[N];
	for (int i = 0; i < N;i++) {
		int num = distrib(gen);
		arr[i] = num;
	}
	arreglo = arr;
	cout << "\nArreglo de tamanio " << N << " generado exitosamente\n";
}
void busquedaLineal(int* arreglo, int N) {
	int n;
	bool encontrado = false;
	cout << "Ingrese el numero a buscar : "; cin >> n;
	cout << "complejidad esperada : O(n)\n";
	auto inicio = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		if (arreglo[i] == n) { encontrado = true; }
	}
	if (encontrado) { cout << "\nnumero [" << n << "] SI se encuentra en el arreglo\n"; }
	else cout << "\nnumero [" << n << "] NO se encuentra en el arreglo\n";

	auto fin = chrono::high_resolution_clock::now();
	auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos." << endl;

}
void busquedaBinaria(int* arreglo, int N) {
	int x;
	cout << "ingrese el numero a buscar : \n"; cin >> x;
	cout << "complejidad esperada : O(long n)\n";
	set<int>s;
	for (int i = 0; i < N; i++) {
		s.insert(arreglo[i]);
	}
	auto inicio = chrono::high_resolution_clock::now();
	auto it = s.find(x);
	if (it != s.end()) {
		cout << "\nEl numero " << x << " SI se encontro en el arreglo\n";
	}
	else {
		cout << "\nEl numero " << x << " NO encontro en el arreglo\n";
	}
	auto fin = chrono::high_resolution_clock::now();
	auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos." << endl;
}
void busquedaEx(int* arreglo, int N) {
	int x;
	bool encontrado = false;
	cout << "ingrese el numero a buscar : \n"; cin >> x;
	cout << "complejidad esperada : O(n^2)\n";
	auto inicio = chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arreglo[i] == arreglo[j]) {}
		}
		if (arreglo[i] == x) { encontrado = true; }

	}
	if (encontrado) cout << "\nnumero [" << x << "] SI se encuentra en el arreglo\n";
	else cout << "\nnumero [" << x << "] NO se encuentra en el arreglo\n";
	auto fin = chrono::high_resolution_clock::now();
	auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos." << endl;
}
void verElementos(int* arreglo, int N) {
	for (int i = 0; i < N; i++) {
		cout << arreglo[i] << endl;
	}
}
void sumarPrim(int*& arreglo) {
	int x;
	cout << "ingrese la cantidad a sumar al 1er elemento : \n"; cin >> x;
	cout << "complejidad esperada : O(1)\n";
	auto inicio = chrono::high_resolution_clock::now();
	arreglo[0] += x;
	cout << "cantidad sumada al 1er elemento exitosamente\n";
	auto fin = chrono::high_resolution_clock::now();
	auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);

	cout << "Tiempo de ejecucion: " << duracion.count() << " microsegundos." << endl;
}