#pragma once

#include "Peca.h"

class Rei :public Peca
{
public:
	Rei(void);
	Rei(int numJogador);
	~Rei(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
	//virtual bool verificaMovimento(int x,int y);
};

