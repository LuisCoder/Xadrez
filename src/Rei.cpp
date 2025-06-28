#include "Rei.h"


Rei::Rei(void)
{
}

Rei::Rei(int numJogador):Peca(numJogador){
}

Rei::~Rei(void)
{
}

char* Rei::getChar(){
	if(cor==0)
		return new char('k');
	else
		return new char('K');
}

std::string* Rei::getNome(){
	if(cor==0)
		return new std::string("Rei");
	else
		return new std::string("REI");
}

void Rei::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	//limpar os movimentos antes de calcular os novos movimentos possiveis
	limparMovimentos();

	//Verifica o Norte
	if(*y+1<8)
		if((*tabuleiro)[*x][*y+1]->getCor()!=getCor())
			inserirMovimento(*x,*y+1);

	//Verifica o Nordeste
	if((*x+1<8)&&(*y+1<8))
		if((*tabuleiro)[*x+1][*y+1]->getCor()!=getCor())
			inserirMovimento(*x+1,*y+1);

	//Verifica o Este
	if(*x+1<8)
		if((*tabuleiro)[*x+1][*y]->getCor()!=getCor())
			inserirMovimento(*x+1,*y);

	//Verifica o Sudeste
	if((*x+1<8)&&(*y-1>=0))
		if((*tabuleiro)[*x+1][*y-1]->getCor()!=getCor())
			inserirMovimento(*x+1,*y-1);

	//Verfica o Sul
	if(*y-1>=0)
		if((*tabuleiro)[*x][*y-1]->getCor()!=getCor())
			inserirMovimento(*x,*y-1);

	//Verifica o Sudoeste
	if((*x-1>=0)&&(*y-1>=0))
		if((*tabuleiro)[*x-1][*y-1]->getCor()!=getCor())
			inserirMovimento(*x-1,*y-1);

	//Verifica o Oeste
	if((*x-1>=0))
		if((*tabuleiro)[*x-1][*y]->getCor()!=getCor())
			inserirMovimento(*x-1,*y);

	//Verifica o Noroeste
	if((*x-1>=0)&&(*y+1<8))
		if((*tabuleiro)[*x-1][*y+1]->getCor()!=getCor())
			inserirMovimento(*x-1,*y+1);
}

/*bool Rei::verificaMovimento(int x,int y){
	printf("Este metodo ainda não foi implementado\n");
	return true;
}*/