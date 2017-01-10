#include "Torre.h"


Torre::Torre(void)
{
}

Torre::Torre(int numJogador):Peca(numJogador){
}

Torre::~Torre(void)
{
}

char* Torre::getChar(){
	if(cor==0)
		return new char('t');
	else
		return new char('T');
}

std::string* Torre::getNome(){
	if(cor==0)
		return new std::string("Torre");
	else
		return new std::string("TORRE");
}

void Torre::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	//limpar os movimentos antes de calcular os novos movimentos possiveis
	limparMovimentos();

	//Verifica o Norte
	for(int NEy=*y+1;(NEy<8);NEy++){
		if((*tabuleiro)[*x][NEy]->getCor()==-1)
			inserirMovimento(*x,NEy);
		else if((*tabuleiro)[*x][NEy]->getCor()!=getCor()){
			inserirMovimento(*x,NEy);
			break;
		}
		else{
			break;
		}
	}

	//Verifica o Este
	for(int NEx=*x+1;(NEx<8);NEx++){
		if((*tabuleiro)[NEx][*y]->getCor()==-1)
			inserirMovimento(NEx,*y);
		else if((*tabuleiro)[NEx][*y]->getCor()!=getCor()){
			inserirMovimento(NEx,*y);
			break;
		}
		else{
			break;
		}
	}

	//Verfica o Sul
	for(int NEy=*y-1;(NEy>=0);NEy--){
		if((*tabuleiro)[*x][NEy]->getCor()==-1)
			inserirMovimento(*x,NEy);
		else if((*tabuleiro)[*x][NEy]->getCor()!=getCor()){
			inserirMovimento(*x,NEy);
			break;
		}
		else{
			break;
		}
	}

	//Verifica o Oeste
	for(int NEx=*x-1;(NEx>=0);NEx--){
		if((*tabuleiro)[NEx][*y]->getCor()==-1)
			inserirMovimento(NEx,*y);
		else if((*tabuleiro)[NEx][*y]->getCor()!=getCor()){
			inserirMovimento(NEx,*y);
			break;
		}
		else{
			break;
		}
	}
}

/*bool Torre::verificaMovimento(int x,int y){
	printf("Este metodo ainda não foi implementado\n");
	return true;
}*/