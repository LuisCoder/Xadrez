#pragma once

#include "Peca.h"

class Rainha :public Peca
{
public:
	Rainha(void);
	Rainha(int numJogador);
	~Rainha(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

