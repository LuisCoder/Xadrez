#pragma once

#define ALTURA 8
#define LARGURA 8
//#define LETRAS{'a','b','c','d','e','f','g','h'}
#include "StdAfx.h"
#include "Peca.h"
#include "Peao.h"
#include "Bispo.h"
#include "Cavalo.h"
#include "Torre.h"
#include "Rainha.h"
#include "Rei.h"
#include "Vazio.h"

#include <vector>

class Tabuleiro
{
private:
	std::vector<std::vector<Peca*>> tabuleiro;//vector para o tabuleiro
	//jogador branco
	
	std::vector<Peca*> pecas_brancas_fora;//guarda as pecas que estao fora do tabuleiro

	//jogador preto
	std::vector<Peca*> pecas_pretas_fora;//guarda as pecas que estao fora do tabuleiro

	bool checkAoJogadorBranco;//Se esta variavel for colocada a true o Rei do jogador branco foi colocado em xeque
	bool checkMateAoJogadorBranco;//Se esta variavel for colocada a true o jogador branco perdeu o jogo porque foi colocado em xeque-mate
	
	bool checkAoJogadorPreto;//Se esta variavel for colocada a true o Rei do jogador preto foi colocado em xeque
	bool checkMateAoJogadorPreto;//Se esta variavel for colocada a true o jogador preto perdeu o jogo porque foi colocado em xeque-mate

	//flag que identifica a vez do jogador branco ao preto. 
	//Se for true é a vez do jogador com pecas brancas.
	//Se for false é a vez do jogador com pecas pretas.
	bool turn;

	std::pair<int,int> posicaoSelec;//para guardar a posicao de uma peca selecionada

	bool pecaCapturada;//para guardar se uma peca foi capturada num turno de um jogador

	int x,y;//coordenadas onde se encontra a peca selecionada
	//int xj,yj;//coordenadas para onde vai ser jogada a peca
public:
	Tabuleiro(void);
	~Tabuleiro(void);

	//duvidas
	//chamar os metodos para fazer as operacoes no vector tabuleiro e vector normal

	//impressões do tabuleiro
	void imprimirTabuleiro();
	void imprimirTabuleiroBranco();//imprime as duas primeiras linhas do tabuleiro
	void imprimirTabuleiroPreto();//imprime as duas ultimas linhas do tabuleiro
	void imprimirTabuleiroMeio();//imprime as quatro linhas do meio

	//impressão de uma so casa do tabuleiro
	void imprimeCasaChar(int x,int y);//diz qual é o nome da peca que esta na casa se estivar vazia diz que esta "vazia"
	void imprimeCasaString(int x,int y);

	//metodos de visualizacao das pecas brancas
	void imprimirPecasBrancasFora();

	//metodos de visualizacao das pecas pretas
	void imprimirPecasPretasFora();

	//metodos de visualizacao dos movimentos posiveis depois de selecionada uma peca
	void imprimeMovimentos(int x,int y);//imprime todos os movimentos possiveis para a peca que foi seleccionada

	std::vector<std::pair<int,int>>* getMovimentosPeca();//Retorna os movimentos possiveis para a peca selecionada na forma de um vector

	bool verificaJogada(int x,int y);//usado para verificar se a jogada que o jogador selecionou se encontra dentro das jogadas possiveis. Se existir retorna true se nao retorna false

	bool verificaVezDoJogador();//Retorna true se for a vez do jogador branco, false se for a vez do jogador preto

	//metodos do tabuleiro
	void colocar_pecas();//coloca as pecas no vector do tabuleiro e nos vectores dos respectivos jogadores no inicio do jogo
	bool selecionarPeca(int x,int y);//seleciona uma peca retorna true se conseguir selecionar uma peca
	bool selecionarPosicao(int xf,int yf);//seleciona uma posicao para jogar a peca (retorna true se conseguir selecionar false se a jogada nao for valida)
	void jogar();
	void mover_peca(int x,int y);//movimenta uma peca para uma nova posicao x yeg
	Peca* getCasa(int x,int y);//retorna uma peca existente no tabuleiro
	void calcularJogadasPecasTabuleiro();//metodo que é invocado para calcular as jogadas de todas as pecas que se encontram no tabuleiro
	bool reiBrancoXeque();//metodo que percorre todas as pecas preto do tabuleiro para ver se alguma peca preta coloca o rei branco em xeque
	bool reiPretoXeque();//metodo que percorre todas as pecas brancas do tabuleiro para ver se alguma peca branca coloca o rei preto em xeque
};

