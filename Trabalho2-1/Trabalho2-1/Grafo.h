#ifndef grafo_h_
#define grafo_h__
#include <iostream>
#include <fstream>
#include <string>



using namespace std;
class grafo
{
private:
	int Origem, Destino;

public:
	void setargrafo(int *vetor, int MaxValue, int *Origem, int *Destino);
};


#endif