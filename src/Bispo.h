#pragma once

#include "Peca.h"

class Bispo: public Peca
{
public:
	Bispo(void);
	Bispo(int numJogador);
	~Bispo(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

