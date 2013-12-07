#include "grafo.h"
#include <iostream>
#include <fstream>
#include <string>
#include"Lista.h"
//#include"Arquivo.h"


void grafo::setargrafo(int *vetor, int MaxValue, int *Origem, int *Destino)

{
	this->Origem = *Origem;
	this->Destino = *Destino;

	cout << "De :" << this->Origem << " Para :" << this->Destino << endl;
	for (int i = 0; i < MaxValue; i= i+2)
	{
		Lista l;
		Item x;
		int aux = vetor[i];
		int aux1 = vetor[i + 1];
		x.Vertice1 = aux;
		x.Vertice2 = aux1;
		l.insere(x);
		l.imprime();
	}


}