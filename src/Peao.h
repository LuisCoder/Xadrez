#pragma once

#include "Peca.h"

class Peao :public Peca
{
public:
	Peao(void);
	Peao(int numJogador);
	~Peao(void);
	virtual char* getChar();
	virtual std::string* getNome(); 
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

