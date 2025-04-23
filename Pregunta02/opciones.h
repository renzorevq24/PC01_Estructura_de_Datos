//opciones.h
#pragma once
#ifndef OPCIONES_H
#define OPCIONES_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;


void menu();
void generarArreglo(int** arreglo, int& tamano);
void busquedaLineal(int* arreglo, int tamano);
void busquedaBinaria(int* arreglo, int tamano);
void comparacionDoble(int* arreglo, int tamano);

void mostrarTiempo(std::chrono::high_resolution_clock::time_point inicio, std::chrono::high_resolution_clock::time_point fin);
#endif