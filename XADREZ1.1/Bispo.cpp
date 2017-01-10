#include "Bispo.h"


Bispo::Bispo(void)
{
}

Bispo::Bispo(int numJogador):Peca(numJogador){
}

Bispo::~Bispo(void)
{
}

char* Bispo::getChar(){
	if(cor==0)
		return new char('b');
	else
		return new char('B');
}

std::string* Bispo::getNome(){
	if(cor==0)
		return new std::string("Bispo");
	else
		return new std::string("BISPO");
}

void Bispo::calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y){
	//limpar os movimentos antes de calcular os novos movimentos possiveis
	limparMovimentos();

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

/*bool Bispo::verificaMovimento(int x,int y){
	printf("Este metodo ainda não foi implementado\n");
	return true;
}*/