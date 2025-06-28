#pragma once
//#include "ComplexObject3D.h"
#include "Tabuleiro.h"
#include "Cubo.h"
#include "Cilindro.h"
#include "VPeao.h"
#include "VTorre.h"
#include "VCavalo.h"
#include "VBispo.h"
#include "VRei.h"
#include "VRainha.h"
#include "VVazio.h"
#include "Sound.h"
#include "CuboComText.h"


class VTabuleiro:public CComplexObject3D
{
public:
	VTabuleiro(void);
	~VTabuleiro(void);

	virtual void Init ();
	virtual void Destroy ();
	virtual void Draw ();
	void adicionarPeca();
	void moverTestePeca(int x, int y);

	//metodos para movimentar o cursor
	void cursorParaCima();
	void cursorParaBaixo();
	void cursorParaEsquerda();
	void cursorParaDireita();

	//metodos de selecacao/desseleccionar uma casa
	void selecionarCasa();//metodo para selecionar um cubo, colocalo a vermelho, e o jogador ja nao poder fazer a movimentacao no tabuleiro com o cursor azul
	void desseleccionarCasa();//metodo que permite desseleccionar uma casa

	//metodo para movimentar o tabuleiro que esta constantemente a ser chamado 
	void calculosIniciais();//metodo para realizar calculos iniciais antes de comecar a realizar o movimento( que variavel decrementar etc.)
	void movimentarPeca(double elapsedTime);//movimentar a peca despois de efectuados os calculos

	virtual bool estaVazio();//este metodo não faz muito sentido. Apenas tem de ser implementado aqui porque é abstracto

	virtual int getAltura();//este metodo não faz muito sentido. Apenas tem de ser implementado aqui porque é abstracto

	void iluminarJogadasPossiveis();//metodo usado para iluminar as casas das jogadas possiveis. Vai buscar o vector das jogadas possiveis a logica do jogo
	void desiluminarJogadasPossiveis();//para desiluminar as casas das jogadas possives depois de selecionado a casa destino da peca

	void jogarContraComputador();//metodo que quando invocado o jogador branco fica a jogar contra um computador preto
private:
	//A ligacao a parte logica do programa encontra-se aqui
	Tabuleiro* logicTab;

	//instancia da classe Sound criada para colocar som nesta classe
	Sound* som;

	CCubo* tabuleiro[8][8];//Array para guardar os cubos do tabuleiro
	CComplexObject3D* pecas[8][8];//Array para guardar as pecas do tabuleiro e casas Vazias
	CComplexObject3D* pecasBrancas[15];//Array usado para guardar as referencias das Pecas Brancas fora do tabuleiro
	CComplexObject3D* pecasPretas[15];//Array usado para guardar as referencias das Pecas Pretas fora do tabuleiro
	int numPecasBrancasFora;//usado para guardar o numero de pecas brancas fora do tabuleiro
	int numPecasPretasFora;//usado para guardar o numero de pecas pretasd fora do tabuleiro

	int x;//para guardar o valor da peca a incrementar no array de pecas
	int y;
	/*VTorre* t1_b;
	CCubo* teste;*/
	bool mov;//enquanto esta varivel for true a peca vai realizando o movimento

	bool comp;//variavel que quando esta a true estamos a jogar contra um computador branco

	bool andarNoTabuleiro;//enquanto esta variavel for true é possivel andar no tabuleiro. Depois de carregar a tecla enter ja não é possivel
	int xf,yf;//variaveis para ir incrementando ate chegar ao destino

	double veloc;//variavel usada no metodo movimentar peca(pode ser alterada no construtor para dar mais ou menos movimento)
	double velocCap;//Variavel usada no metodo movimentar para a captura da peca

	//variaveis utilizadas para movimentar a peca(acho que ficam alguma espalhas)
	//variaveis usadas para capturar uma peca
	bool existePecaParaCapturar;//Se existe uma peca no destino essa peca tem de mostrar uma animacao de captura. False se nao existir uma peca no destino true se existir
	double auxTransCaptura;//Variavel auxiliar para guardar a translacao total realizada a animacao da peca capturada
	bool auxCapturaParaBorda;//(switch)Variavel auxiliar usada para mover uma peca do seu respectivo jogador
	bool movimentoBaixo;//variavel e colocada a false quando a peca termina o movimento para baixo

	//Quando as duas variaveis são colocadas a true significa que o movimento terminou e são entao colocadas novamente a false
	bool movx;
	bool movy;
	double velocx;
	double velocy;
	//variaveis para ir incrementando ate a peca chegar ao destino
	double xinc;//o programa vai incrementar ou decrementar estes dois (xinc e yinc) valores até a peca chegar ao seu destino
	double yinc;
	bool boolIncx;//se esta variavel for true significa que se tem de incrementar valores em x se for false significa que tem de se decrementar
	bool boolIncy;;//se esta variavel for true significa que se tem de incrementar valores em y se for false significa que tem de se decrementar
};