#ifndef FILA_H_
#define FILA_H__
#include <iostream>
#include <fstream>
#include <string>

#include<iostream>
using namespace std;

typedef string ChaveFila;

struct No {
	ChaveFila chave;
	// outros campos...
};

struct PosicaoFila {
	No item;
	PosicaoFila *ant; // ant: antecessor
};

class Fila {
private:
	PosicaoFila *frente, *tras;
	void ffVazia();
public:
	Fila();
	bool vazia();
	void enfileira(No item);
	void desenfileira(No &item);
	void imprime();
};


#endif