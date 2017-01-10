#include "Rainha.h"


Rainha::Rainha(void)
{
}

Rainha::Rainha(int numJogador):Peca(numJogador){
}

Rainha::~Rainha(void)
{
}

char* Rainha::getChar(){
	if(cor==0)
		return new char('q');
	else
		return new char('Q');
}

std::string* Rainha::getNome(){
	if(cor==0)
		return new std::string("Rainha");
	else
		return new std::string("RAINHA");
}

void Rainha::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
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

	//Verifica o Nordeste
	for(int NEx=*x+1,NEy=*y+1;(NEx<8)&&(NEy<8);NEx++,NEy++){
		if((*tabuleiro)[NEx][NEy]->getCor()==-1)
			inserirMovimento(NEx,NEy);
		else if((*tabuleiro)[NEx][NEy]->getCor()!=getCor()){
			inserirMovimento(NEx,NEy);
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

	//Verifica o Sudeste
	for(int NEx=*x+1,NEy=*y-1;(NEx<8)&&(NEy>=0);NEx++,NEy--){
		if((*tabuleiro)[NEx][NEy]->getCor()!=getCor())
			inserirMovimento(NEx,NEy);
		else if((*tabuleiro)[NEx][NEy]->getCor()!=getCor()){
			inserirMovimento(NEx,NEy);
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

	//Verifica o Sudoeste
	for(int NEx=*x-1,NEy=*y-1;(NEx>=0)&&(NEy>=0);NEx--,NEy--){
		if((*tabuleiro)[NEx][NEy]->getCor()!=getCor())
			inserirMovimento(NEx,NEy);
		else if((*tabuleiro)[NEx][NEy]->getCor()!=getCor()){
			inserirMovimento(NEx,NEy);
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

	//Verifica o Noroeste
	for(int NEx=*x-1,NEy=*y+1;(NEx>=0)&&(NEy<8);NEx--,NEy++){
		if((*tabuleiro)[NEx][NEy]->getCor()!=getCor())
			inserirMovimento(NEx,NEy);
		else if((*tabuleiro)[NEx][NEy]->getCor()!=getCor()){
			inserirMovimento(NEx,NEy);
			break;
		}
		else{
			break;
		}
	}
}

/*bool Rainha::verificaMovimento(int x,int y){
	printf("Este metodo ainda não foi implementado\n");
	return true;
}*/