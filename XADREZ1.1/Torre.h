#pragma once

#include "Peca.h"

class Torre :public Peca
{
public:
	Torre(void);
	Torre(int numJogador);
	~Torre(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

