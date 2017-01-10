#pragma once

#include "StdAfx.h"
#include<string>
#include <vector>

class Peca
{
protected:
	int cor;//0-branco 1-preto -1-casaVazia
	std::vector<std::pair<int,int>> movimentos;
public:
	Peca(void);
	Peca(int cor);//construtor que coloca a cor do peao
	~Peca(void);

	//metodos abstractos
	virtual char* getChar()=0;
	virtual std::string* getNome()=0;

	virtual int getCor();//metodo para saber a cor do peca e se a casa esta vazia

	//metodo para calcular as jogadas possiveis
	virtual void calcularJogadas(std::vector<std::vector<Peca*>>* tabuleiro,int* x,int* y)=0;

	//metodo para retornar as jogadas
	virtual std::vector<std::pair<int,int>>* getMovimentos();
	
	//verifica se o movimento recebido como argumento existe na lista de movimentos
	virtual bool verificaMovimento(int x,int y);

	//metodos para manipular o vector de movimentos
	virtual void limparMovimentos();
	virtual void inserirMovimento(int x,int y);
	virtual bool semMovimentos();//verifica se o vector de movimentos esta vazio
	virtual int getNumerosMovimentos();//retorna o numero de movimentos existentes no vector movimentos
	virtual void imp();//imprime os movimentos no vector movimentos apenas para efeitos de teste. Remover este metodo mais tarde
	//metodos para verificar se alguma das jogadas da peca coloca o Rei de uma determinada cor em xeque
	virtual bool verificaXequeAoRei(std::vector<std::vector<Peca*>>* tabuleiro);//Verifica se numa das posicoes do vector movimentos se encontra o rei e se tal acontecer returna true
};

