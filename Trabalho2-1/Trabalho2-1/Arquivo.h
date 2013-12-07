#ifndef ARQUIVO_H_
#define ARQUIVO_H__
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


class Arquivo
{
private:
	int vetaux[300];
	int MaxVet = 0;
	int Origem, Destino;
public:
	int getOrigem() { return Origem;  }
	int getDestino(){ return Destino; }
	int SizeVet(){ return MaxVet; } //Retorna o tamanho do vetor com os nos
	int vetAux(int i) { return vetaux[i]; } //Retorna o vetor com os nos
	void abrirArquivo(string entrada);
	void pegarMatriz(int * matriz, int *origem, int* destino);
	Arquivo();
	//std::string removerEspaco(std::string str)
	//{
	//	std::string temp;
	//	for (unsigned int i = 0; i < str.length(); i++)
	//	{
	//		if (str[i] != ' ' ) temp += str[i];
	//	}
	//	return temp;
	//}

};



void Arquivo::abrirArquivo(string  entrada)
{
	
	

	string buffer;
	char caracter;
	int cont = 0;

	ifstream myfile;
	myfile.open(entrada);
	if (myfile.is_open())
	{
		while (!myfile.eof()) //enquanto end of file for false continua
		{

			myfile.get(caracter);
			if ((caracter == ' ') || (caracter == '\n'))
			{
				int aux = stoi(buffer);
				if (cont == 0)
				{
					Origem = aux;
					cont++;
				}
				else if (cont == 1)
				{
					Destino = aux;
					cont++;
				}
				else if (cont == 2)
				{
					cont++;
				}
				else if (cont == 3)
				{
					cont++;
				}
				else
				{
					vetaux[MaxVet] = aux; //  Converte para inteiro e guardar em um vetor TODOS os nos
					MaxVet++;
				}
				buffer.clear(); //Limpa o buffer para o proximo


			}
			buffer = buffer + caracter;



			//		cout << caracter << endl;
		}
		myfile.close();

	}
	else {
		cout << "Não foi possivel abrir o arquivo!!" << endl;
		myfile.clear();
	}


}

void Arquivo::pegarMatriz(int *matriz, int* origem, int* destino)
{
	*origem = this->Origem;
	*destino = this->Destino;
	for (int i = 0; i < MaxVet; i++)
	{
		matriz[i] = this->vetaux[i];
	}
}

Arquivo::Arquivo()
{
	
	//Arquivo *vetaux[0] = NULL;
};


#endif
