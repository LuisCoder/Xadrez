#include "Peca.h"


Peca::Peca(void)
{
}

Peca::Peca(int cor){
	this->cor=cor;
}

Peca::~Peca(void)
{
}

int Peca::getCor(){
	return cor;
}

std::vector<std::pair<int,int>>* Peca::getMovimentos(){
	return &movimentos;
}

void Peca::limparMovimentos(){
	movimentos.clear();
}

void Peca::inserirMovimento(int x,int y){
	//printf("Valores a ser inseridos no vector de movimentos: x=%d y=%d\n",&x,&y);
	std::pair<int,int> p;
	p.first=x;
	p.second=y;
	//printf("first: %d second: %d\n",p.first,p.second);
	movimentos.push_back(p);
}

bool Peca::semMovimentos(){
	return movimentos.empty();
}

int Peca::getNumerosMovimentos(){
	return movimentos.size();
}

void Peca::imp(){
	int t=movimentos.size();
	for(int i=0;i<t;i++){
		//if(i==8)
			//printf("\n");
		printf("x=%d y=%d\n",(movimentos.at(i)).first,(movimentos.at(i)).second);
	}
	printf("\n");
}

bool Peca::verificaMovimento(int x,int y){
	printf("Jogada a verificar\nx=%d \ny=%d\n\nlista\n",x,y);
	int t=movimentos.size();
	for(int i=0;i<t;i++){
		printf("x=%d \ny=%d\n\n",movimentos.at(i).first,movimentos.at(i).second);
		if(movimentos.at(i).first==x && movimentos.at(i).second==y){
			printf("A jogada e possivel\n");
			return true;
		}
	}
	printf("A jogada nao e possivel\n");
	return false;
}

bool Peca::verificaXequeAoRei(std::vector<std::vector<Peca*>>* tabuleiro){
	int t=movimentos.size();
	for(int i=0;i<t;i++){
		if(cor==0){//Se a cor do peao for branco vai ver se em alguma das jogadas se encontra o rei preto
			if(*(*tabuleiro)[(movimentos.at(i)).first][(movimentos.at(i)).second]->getChar()=='K')
			{
				return true;
			}
		}else if(cor==1){//Se a cor do peao for preto vai ver se em alguma das jogadas se encontra o rei branco
			if(*(*tabuleiro)[(movimentos.at(i)).first][(movimentos.at(i)).second]->getChar()=='k')
			{
				return true;
			}
		}
	}
	return false;//Se não encontrar o rei em alguma das suas jogadas retorna falso
}