#pragma once

#include "Peca.h"

class Vazio: public Peca
{
public:
	Vazio(void);
	Vazio(int numJogador);
	~Vazio(void);
	virtual char* getChar();
	virtual std::string* getNome();
	virtual bool verificaMovimento(int x,int y);
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y);
};