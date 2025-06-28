#include "Peao.h"


Peao::Peao(void)
{
}

Peao::Peao(int numJogador):Peca(numJogador){
}

Peao::~Peao(void)
{
}

char* Peao::getChar(){
	if(cor==0)
		return new char('p');
	else
		return new char('P');
}

std::string* Peao::getNome(){
	if(cor==0)
		return new std::string("Peao");
	else
		return new std::string("PEAO");
}

void Peao::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	//limpar os movimentos antes de calcular os novos movimentos possiveis
	limparMovimentos();

	//calculo das jogadas se o peao for branco
	if(cor==0){

		//verifica o Norte
		if(*y>=1 && (*tabuleiro)[*x][*y+1]->getCor()==-1)
			inserirMovimento(*x,*y+1);

		//verifica o duplo norte
		if(*y==1 && (*tabuleiro)[*x][*y+2]->getCor()==-1)
			inserirMovimento(*x,*y+2);

		//verifica o noroeste
		if(*x+1<8 && (*tabuleiro)[*x+1][*y+1]->getCor()==1)
			inserirMovimento(*x+1,*y+1);

		//verifica o nordeste
		if(*x-1>=0 && (*tabuleiro)[*x-1][*y+1]->getCor()==1)
			inserirMovimento(*x-1,*y+1);

	}

	//calculo das jogadas se o peao for preto
	if(cor==1){

		//verifica o sul
		if(*y<=6 && (*tabuleiro)[*x][*y-2]->getCor()==-1)
			inserirMovimento(*x,*y-1);

		//verifica duplo sul
		if(*y==6 && (*tabuleiro)[*x][*y-1]->getCor()==-1)
			inserirMovimento(*x,*y-2);

		//verifica o sudoeste
		if(*x-1>=0 && (*tabuleiro)[*x-1][*y-1]->getCor()==0)
			inserirMovimento(*x-1,*y-1);
		
		//verifica o sudeste
		if(*x+1<8 && (*tabuleiro)[*x+1][*y-1]->getCor()==0)
			inserirMovimento(*x+1,*y-1);
	}

	//verificar se nas jogadas que foram calculadas em cima, coloca o Rei do adversario em xeque
	int corAdv=(getCor()==0)?1:0;//Calcula a cor do adversario

}

/*bool Peao::verificaMovimento(int x,int y){
	int t=movimentos.size();
	for(int i=0;i<t;i++){
		if(movimentos.at(i).first==x && movimentos.at(i).second==y){
			return true;
		}
	}
	return false;
}*/