#pragma once

#include "Peca.h"

class Cavalo :public Peca
{
public:
	Cavalo(void);
	Cavalo(int numJogador);
	~Cavalo(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

