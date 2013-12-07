//
//  Lista.h
//  ED_ListaPonteiros
//
//  Created by Coelho on 23/09/13.
//  Copyright (c) 2013 Flavio Jose Mendes Coelho. All rights reserved.
//

#ifndef LISTA_H_
#define LISTA_H_

#include<iostream>
#include <string>
using namespace std;

typedef int Chave;
typedef int Posicao;

struct Item {
	Chave Vertice1;
	Chave Vertice2;
};

struct Celula {
	Item item;
	Celula *prox;
};

class Lista {
private:
	Celula *prim, *ult;
	void flVazia();
public:
	Lista();
	bool vazia();
	void insere(Item item);
	void retira(Celula *p, Item &item);
	Celula* busca(Posicao pos);
	void imprime();
	void imprimeItem(Item &item);

};

#endif