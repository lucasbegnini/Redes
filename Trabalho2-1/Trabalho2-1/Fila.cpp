#include "Fila.h"

Fila::Fila() {
	ffVazia();
};

void Fila::ffVazia() {
	tras = frente = new PosicaoFila; // célula cabeça
	tras->ant = NULL;
};

bool Fila::vazia() {
	return frente == tras;
};

void Fila::enfileira(No item) {
	tras->ant = new PosicaoFila;
	tras = tras->ant;
	tras->item = item;
	tras->ant = NULL;
};

void Fila::desenfileira(No &item){
	if (vazia()) {
		cout << "fila vazia" << endl;
	}
	else {
		PosicaoFila *q = frente;
		frente = frente->ant;
		item = frente->item;
		delete(q);
	}
};

void Fila::imprime() {
	cout << "Fila: <-";
	for (PosicaoFila *p = frente->ant; p != NULL; p = p->ant) {
		cout << p->item.chave << ", ";
	}
	cout << "<-" << endl;
};
