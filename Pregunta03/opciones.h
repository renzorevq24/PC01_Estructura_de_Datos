#pragma once
#ifndef OPCIONES_H
#define OPCIONES_H

#include <vector>

using namespace std;

void menu();
void generarVectorAleatorio(vector<int>*& numeros);
void contarImpares(vector<int>* numeros);
void buscarDuplicados(vector<int>* numeros);
void mostrarPrimerElemento(vector<int>* numeros);
#endif