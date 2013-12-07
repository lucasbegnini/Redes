#include "Arquivo.h"
#include "Lista.h"
#include "Grafo.h"
#include <iostream>
#include <stdlib.h>

using namespace std;



int main(int argc, const char * argv[]) {

	

	Arquivo entrada;
	grafo grafo;
	
	
	entrada.abrirArquivo("/topologia.txt");
	

	int MaxValue = entrada.SizeVet();
	int vetor[300];
	int origem, destino;

	entrada.pegarMatriz(vetor, &origem, &destino);
	grafo.setargrafo(vetor, MaxValue, &origem, &destino);



	system("pause");

	return 0;
}


