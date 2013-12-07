#include "Lista.h"
#include <string>
#include<iostream>
using namespace std;

Lista::Lista() {
	flVazia();
};

void Lista::flVazia() {
	prim = new Celula();
	prim->item = { 0, 0 };
	ult = prim;
	ult->prox = NULL;
};

bool Lista::vazia() {
	return prim == ult;
};

void Lista::insere(Item x) {
	ult->prox = new Celula();
	ult = ult->prox;
	ult->item = x;
	ult->prox = NULL;
	
};


void Lista::retira(Celula *p, Item &item) {
	if (vazia() || p == NULL || p->prox == NULL) {
		cout << "Erro: retirada impossível" << endl;
	}
	else {
		Celula *q = p->prox;
		item = q->item;
		p->prox = q->prox;
		if (p->prox == NULL) ult = p;
		delete(q);
	}
};

Celula* Lista::busca(Posicao pos) {
	int i = 0;
	for (Celula *p = prim; p != NULL; p = p->prox) {
		if (pos == i) {
			return p;
		}
		++i;
	}
	return NULL;
};



void Lista::imprime() {
	cout << "Lista: " << endl;
	Celula *p = NULL;
	p = prim->prox;
	while (p != NULL) {
		imprimeItem(p->item);
		p = p->prox;
	}
};

void Lista::imprimeItem(Item &item) {
	
	cout << item.Vertice1 << "-> " << item.Vertice2 << endl;
};
