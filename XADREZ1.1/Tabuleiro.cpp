#include "Tabuleiro.h"


Tabuleiro::Tabuleiro(void)
{
	checkAoJogadorBranco=false;
	checkMateAoJogadorBranco=false;
	checkAoJogadorPreto=false;
	checkMateAoJogadorPreto=false;
	turn=true;
	pecaCapturada=false;

	//invocar o metodo para colocar as pecas no sitio
	colocar_pecas();
}


Tabuleiro::~Tabuleiro(void)
{
}

void Tabuleiro::colocar_pecas(){
	//
	tabuleiro.resize(ALTURA);
	for (int i = 0; i < ALTURA; ++i)
		tabuleiro[i].resize(LARGURA);

	//-------------------------colocar as pecas do jogador 1(branco)-------------------------

	Torre*  t1_b=new Torre(0);
	Cavalo* c1_b=new Cavalo(0);
	Bispo*  b1_b=new Bispo(0);
	Rainha* ra_b=new Rainha(0);
	Rei*    re_b=new Rei(0);
	Bispo*  b2_b=new Bispo(0);
	Cavalo* c2_b=new Cavalo(0);
	Torre*  t2_b=new Torre(0);

	//printf("char: %c",*t1_b->getChar());

	//peoes
	Peao* p1_b=new Peao(0);
	Peao* p2_b=new Peao(0);
	Peao* p3_b=new Peao(0);
	Peao* p4_b=new Peao(0);
	Peao* p5_b=new Peao(0);
	Peao* p6_b=new Peao(0);
	Peao* p7_b=new Peao(0);
	Peao* p8_b=new Peao(0);

	//colocar as pecas no tabuleiro
	tabuleiro[0][0]=t1_b;
	tabuleiro[1][0]=c1_b;
	tabuleiro[2][0]=b1_b;
	tabuleiro[3][0]=ra_b;
	tabuleiro[4][0]=re_b;
	tabuleiro[5][0]=b2_b;
	tabuleiro[6][0]=c2_b;
	tabuleiro[7][0]=t2_b;

	//peoes
	tabuleiro[0][1]=p1_b;
	tabuleiro[1][1]=p2_b;
	tabuleiro[2][1]=p3_b;
	tabuleiro[3][1]=p4_b;
	tabuleiro[4][1]=p5_b;
	tabuleiro[5][1]=p6_b;
	tabuleiro[6][1]=p7_b;
	tabuleiro[7][1]=p8_b;

	//-------------------------colocar as pecas do jogador 2-------------------------

	Torre*  t1_p=new Torre(1);
	Cavalo* c1_p=new Cavalo(1);
	Bispo*  b1_p=new Bispo(1);
	Rainha* ra_p=new Rainha(1);
	Rei*    re_p=new Rei(1);
	Bispo*  b2_p=new Bispo(1);
	Cavalo* c2_p=new Cavalo(1);
	Torre*  t2_p=new Torre(1);

	//peoes
	Peao* p1_p=new Peao(1);
	Peao* p2_p=new Peao(1);
	Peao* p3_p=new Peao(1);
	Peao* p4_p=new Peao(1);
	Peao* p5_p=new Peao(1);
	Peao* p6_p=new Peao(1);
	Peao* p7_p=new Peao(1);
	Peao* p8_p=new Peao(1);

	//colocar as pecas no vector que guarda todas as pecas

	//colocar as pecas no tabuleiro
	tabuleiro[0][7]=t1_p;
	tabuleiro[1][7]=c1_p;
	tabuleiro[2][7]=b1_p;
	tabuleiro[3][7]=ra_p;
	tabuleiro[4][7]=re_p;
	tabuleiro[5][7]=b2_p;
	tabuleiro[6][7]=c2_p;
	tabuleiro[7][7]=t2_p;

	//peoes
	tabuleiro[0][6]=p1_p;
	tabuleiro[1][6]=p2_p;
	tabuleiro[2][6]=p3_p;
	tabuleiro[3][6]=p4_p;
	tabuleiro[4][6]=p5_p;
	tabuleiro[5][6]=p6_p;
	tabuleiro[6][6]=p7_p;
	tabuleiro[7][6]=p8_p;

	//-------------------------casas vazias-------------------------

	tabuleiro[0][2]=new Vazio();
	tabuleiro[1][2]=new Vazio();
	tabuleiro[2][2]=new Vazio();
	tabuleiro[3][2]=new Vazio();
	tabuleiro[4][2]=new Vazio();
	tabuleiro[5][2]=new Vazio();
	tabuleiro[6][2]=new Vazio();
	tabuleiro[7][2]=new Vazio();

	tabuleiro[0][3]=new Vazio();
	tabuleiro[1][3]=new Vazio();
	tabuleiro[2][3]=new Vazio();
	tabuleiro[3][3]=new Vazio();
	tabuleiro[4][3]=new Vazio();
	tabuleiro[5][3]=new Vazio();
	tabuleiro[6][3]=new Vazio();
	tabuleiro[7][3]=new Vazio();

	tabuleiro[0][4]=new Vazio();
	tabuleiro[1][4]=new Vazio();
	tabuleiro[2][4]=new Vazio();
	tabuleiro[3][4]=new Vazio();
	tabuleiro[4][4]=new Vazio();
	tabuleiro[5][4]=new Vazio();
	tabuleiro[6][4]=new Vazio();
	tabuleiro[7][4]=new Vazio();

	tabuleiro[0][5]=new Vazio();
	tabuleiro[1][5]=new Vazio();
	tabuleiro[2][5]=new Vazio();
	tabuleiro[3][5]=new Vazio();
	tabuleiro[4][5]=new Vazio();
	tabuleiro[5][5]=new Vazio();
	tabuleiro[6][5]=new Vazio();
	tabuleiro[7][5]=new Vazio();

	//invocar o metodo que permite calcular as jogadas possiveis para as pecas colocadas no tabuleiro
	calcularJogadasPecasTabuleiro();
}

void Tabuleiro::imprimirTabuleiro(){
	printf("\n");
	for(int i=7;i>=0;i--){
		printf("%d   ",i);
		for(int j=0;j<8;j++)
			printf("%c ",*tabuleiro[j][i]->getChar());
		printf("\n");
	}
	printf("|\ny");
	printf("\n  x-0 1 2 3 4 5 6 7\n\n");
	printf("\n");
}

void Tabuleiro::imprimirTabuleiroBranco(){
	for(int i=1;i>=0;i--){
		for(int j=0;j<8;j++)
			printf("%c ",*tabuleiro[j][i]->getChar());
		printf("\n");
	}
	printf("\n");
}

void Tabuleiro::imprimirTabuleiroPreto(){
	for(int i=7;i>=6;i--){
		for(int j=0;j<8;j++)
			printf("%c ",*tabuleiro[j][i]->getChar());
		printf("\n");
	}
	printf("\n");
}

void Tabuleiro::imprimirTabuleiroMeio(){
	for(int i=5;i>=2;i--){
		for(int j=0;j<8;j++)
			printf("%c ",*tabuleiro[j][i]->getChar());
		printf("\n");
	}
	printf("\n");
}

void Tabuleiro::imprimirPecasBrancasFora(){
	int t=pecas_brancas_fora.size();
	for(int i=0;i<t;i++){
		if(i==8)
			printf("\n");
		printf("%s ",pecas_brancas_fora.at(i)->getNome()->c_str());
	}
	printf("\n");
}

void Tabuleiro::imprimirPecasPretasFora(){
	int t=pecas_pretas_fora.size();
	for(int i=0;i<t;i++){
		if(i==8)
			printf("\n");
		printf("%s ",pecas_pretas_fora.at(i)->getNome()->c_str());
	}
	printf("\n");
}

void Tabuleiro::imprimeCasaChar(int x,int y){
	printf("%c",*tabuleiro[y][x]->getChar());
}

void Tabuleiro::imprimeCasaString(int x,int y){
	printf("%s",tabuleiro[x][y]->getNome()->c_str());
}

bool Tabuleiro::selecionarPeca(int x,int y){
	imprimirTabuleiro();
	if(x<0 || x>7 || y<0 || y>7){
		printf("A casa que escolheu esta fora do tabuleiro. Por favor selecione outra casa.\n\n");
		return false;
	}else{
		if(tabuleiro[x][y]->getCor()==-1){
			printf("A casa que escolheu esta vazia. Por favor selecione outra casa.\n\n");
			return false;
		}else{
			if(tabuleiro[x][y]->getCor()==0 && turn){
				this->x=x;
				this->y=y;
				printf("Foi selecionado o %s da cor branca na posicao x: %d y: %d.\n\n",tabuleiro[x][y]->getNome()->c_str(),posicaoSelec.first,posicaoSelec.second);
				return true;
			}
			else if(tabuleiro[x][y]->getCor()==1 && !turn){
				this->x=x;
				this->y=y;
				printf("Foi selecionado o %s da cor preta na  posicao x: %d y: %d.\n\n",tabuleiro[x][y]->getNome()->c_str(),posicaoSelec.first,posicaoSelec.second);
				return true;
			}
			else{
				printf("O peao que escolheu não é da sua cor por favor selecione novamente uma casa.\n\n");
				return false;
			}
		}
	}
}

bool Tabuleiro::selecionarPosicao(int xf,int yf){

	//verificar primeiro se a jogada que o jogador selecionou se encontra dentro das jogadas posiveis do tabuleiro
	if(tabuleiro[x][y]->verificaMovimento(xf,yf)){
		//printf usado para testes
		//printf("A posicao selecionada para jogar é possivel. A jogada vai ser executada\n");


		Peca* paux;//para guardar que ao realizar a sua jogada o jogador colocou o seu rei em xeque

		//Rollback da jogada
		//Se a jogada que um determinado jogador fizer colocar a peca em xeque tem de se colocar as pecas na mesma posicao onde estava originalmente e
		//selecionar uma nova jogada para a peca
		if(turn?checkAoJogadorBranco:checkAoJogadorPreto){
			if(turn){//retirar a peca no vector de pecas fora
				paux=pecas_pretas_fora.back();
				pecas_pretas_fora.pop_back();
			}else
			{
				paux=pecas_brancas_fora.back();
				pecas_brancas_fora.pop_back();
			}

			//colocar a peca novamente no local onde estava
			tabuleiro[x][y]=tabuleiro[xf][yf];
			//colocar a peca que foi capturada no local onde estava
			tabuleiro[xf][yf]=paux;
			//fazer novamente o calculo de todas as jogadas possiveis depois de ter colocado as pecas como estavam
			calcularJogadasPecasTabuleiro();
		}

		Peca* p=tabuleiro[x][y];
		tabuleiro[x][y]=new Vazio();
		if(tabuleiro[xf][yf]->getCor()!=-1){//Se exitir uma peca na casa para onde o jogador vai jogar
			if(tabuleiro[xf][yf]->getCor()==0)//Se a peca nessa casa for do jogador branco
				pecas_brancas_fora.push_back(tabuleiro[xf][yf]);
			else							  //Se a peca nessa casa for do jogador preto
				pecas_pretas_fora.push_back(tabuleiro[xf][yf]);
		}

		tabuleiro[xf][yf]=p;//colocar o peao na sua nova casa

		//fazer o calculo de todas as jogadas possiveis depois de realizada a jogada
		calcularJogadasPecasTabuleiro();

		//Aqui o jogador vê se colocou o seu próprio Rei em xeque ao o Rei do jogador adversario
		checkAoJogadorBranco=reiBrancoXeque();//coloca a variavel a true se existir alguma peca que coloque o rei branco em xeque
		checkAoJogadorPreto=reiPretoXeque();//coloca a variavel a true se existir alguma peca que coloque o rei preto em xeque

		//}while(turn?checkAoJogadorBranco:checkAoJogadorPreto);//Se o jogador que estiver a jogar colocar o seu proprio Rei em xeque tem de repetir o ciclo para selecionar outra jogada. É feito entao o roolback da jogada
		//if(!turn?checkAoJogadorBranco:checkAoJogadorPreto)
			turn=!turn;
		imprimirTabuleiro();
		return true;
	}else{
		//printf("Não é posivel realizar a jogada?????????\n");
		return false;
	}
}

void Tabuleiro::mover_peca(int x,int y){
	//tabuleiro[x][y]->getMovimentos()
}

void Tabuleiro::imprimeMovimentos(int x,int y){
	printf("O metodo que permite imprimir no ecran os movimetos ainda nao foi implementado\n\n");
}

void Tabuleiro::calcularJogadasPecasTabuleiro(){
	//calcular todas as jogadas possiveis para todas as pecas do tabuleiro
	for(int x=0;x<8;x++)
		for(int y=0;y<8;y++)
			if(tabuleiro[x][y]->getCor()!=-1)
				tabuleiro[x][y]->calcularJogadas(&tabuleiro,&x,&y);
}

bool Tabuleiro::reiBrancoXeque(){
	//percorre todas as pecas pretas do tabuleiro para ver se alguma peca preta coloca o Rei em xeque
	//e se existir alguma retorna true;
	for(int x=0;x<8;x++)
		for(int y=0;y<8;y++)
			if(tabuleiro[x][y]->getCor()==1)//Se a peca for preta
				if(tabuleiro[x][y]->verificaXequeAoRei(&tabuleiro))//Se a peca tiver a fazer xeque ao rei da cor oposta entao é verdade e retorna true
					return true;
	return false;//se nao encontrar nenhuma peca que coloque o rei branco em xeque retorna false
}

bool Tabuleiro::reiPretoXeque(){
	//percorre todas as pecas brancas do tabuleiro para ver se alguma peca branca coloca o Rei em xeque
	//e se existir alguma retorna true;
	for(int x=0;x<8;x++)
		for(int y=0;y<8;y++)
			if(tabuleiro[x][y]->getCor()==0)//Se a peca for branca
				if(tabuleiro[x][y]->verificaXequeAoRei(&tabuleiro))//Se a peca tiver a fazer xeque ao rei da cor oposta entao é verdade e retorna true
					return true;
	return false;//se nao encontrar nenhuma peca que coloque o rei preto em xeque retorna false
}

std::vector<std::pair<int,int>>* Tabuleiro::getMovimentosPeca(){
	return tabuleiro[x][y]->getMovimentos();
}

bool Tabuleiro::verificaJogada(int x,int y){
	//percorre todas as jogadas possiveis da peca selecionada
	//se a jogada se encontrar numa das jogadas posiveis dentro do vector de jogadas posiveis da peca retorna true
	if(tabuleiro[x][y]->verificaMovimento(x,y))
		return true;
	return false;
}

bool Tabuleiro::verificaVezDoJogador(){
	return turn;
}