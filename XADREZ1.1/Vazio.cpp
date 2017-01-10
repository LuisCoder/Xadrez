#include "Vazio.h"


Vazio::Vazio(void)
{
	cor=-1;
}

Vazio::Vazio(int numJogador):Peca(numJogador){
}

Vazio::~Vazio(void)
{
}

char* Vazio::getChar(){
		return new char('-');
}

std::string* Vazio::getNome(){
	return new std::string("Vazia");
}

void Vazio::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	printf("O metodo calcularJogadas para a peca selecionada ainda nao foi implementado\n");
}

bool Vazio::verificaMovimento(int x,int y){
	printf("Nao se encotra nenhum peao nesta casa.\n");
	return false;
}