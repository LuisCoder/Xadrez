#include "Cavalo.h"


Cavalo::Cavalo(void)
{
}

Cavalo::Cavalo(int numJogador):Peca(numJogador){
}

Cavalo::~Cavalo(void)
{
}

char* Cavalo::getChar(){
	if(cor==0)
		return new char('c');
	else
		return new char('C');
}

std::string* Cavalo::getNome(){
	if(cor==0)
		return new std::string("Cavalo");
	else
		return new std::string("CAVALO");
}

void Cavalo::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	//limpar os movimentos antes de calcular os novos movimentos possiveis
	limparMovimentos();

	//Verifica o nor-nordeste
	if(*x+1<8 && *y+2<8 && (*tabuleiro)[*x+1][*y+2]->getCor()!=getCor())
		inserirMovimento(*x+1,*y+2);

	//Verifica o lés-nordeste
	if(*x+2<8 && *y+1<8 && (*tabuleiro)[*x+2][*y+1]->getCor()!=getCor())
		inserirMovimento(*x+2,*y+1);

	//Verifica o lés-sudeste
	if(*x+2<8 && *y-1>=0 && (*tabuleiro)[*x+2][*y-1]->getCor()!=getCor())
		inserirMovimento(*x+2,*y-1);

	//Verifica o su-sudeste
	if(*x+1<8 && *y-2>=0 && (*tabuleiro)[*x+1][*y-2]->getCor()!=getCor())
		inserirMovimento(*x+1,*y-2);

	//Verifica o su-sudoeste
	if(*x-1>=0 && *y-2>=0 && (*tabuleiro)[*x-1][*y-2]->getCor()!=getCor())
		inserirMovimento(*x-1,*y-2);

	//Verifica o oés-sudoeste
	if(*x-2>=0 && *y-1>=0 && (*tabuleiro)[*x-2][*y-1]->getCor()!=getCor())
		inserirMovimento(*x-2,*y-1);

	//Verifica o oés-noroeste
	if(*x-2>=0 && *y+1<8 && (*tabuleiro)[*x-2][*y+1]->getCor()!=getCor())
		inserirMovimento(*x-2,*y+1);

	//Verifica o nor-noroeste
	if(*x-1>=0 && *y+1<8 && (*tabuleiro)[*x-1][*y+2]->getCor()!=getCor())
		inserirMovimento(*x-1,*y+2);
}

/*bool Cavalo::verificaMovimento(int x,int y){
	printf("Este metodo ainda não foi implementado\n");
	return true;
}*/