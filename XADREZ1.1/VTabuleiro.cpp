#include "VTabuleiro.h"



VTabuleiro::VTabuleiro(void)
{
	//inicializacao da parte lógica
	logicTab=new Tabuleiro();

	som = new Sound();

	//inicializar a localizacao do cursor no canto inferior esquerdo
	x=0;
	y=0;

	//inicializar a as variaves que permitem guardar a posicao final da peca
	xf=-1;
	yf=-1;

	//de inicio tambem coloca esse quadrado com a cor do cursor linha 242

	////teste
	//t1_b=new VTorre(0);
	//t1_b->mudarPosicao(1,1);
	//pecas[0][0]=t1_b;
	//AddObject(t1_b);
	//
	//teste=new CCubo();
	//teste->SetCor(1,0,0);
	mov=false;//coloca a variavel que permite o movimento a false

	andarNoTabuleiro=true;//coloca a variavel que permite o movimento no tabuleiro a true

	veloc=1;//inicializacao da velocidade de movimentacao da peca
	velocCap=0.5;

	numPecasBrancasFora=0;
	numPecasPretasFora=0;

	comp=false;//quando ficar a true o jogador branco esta a jogar contra o computador preto
}


VTabuleiro::~VTabuleiro(void)
{
}

void VTabuleiro::Init()
{
	
	bool cor = true;

	
	for(int i=0;i<8;i++)
		{
	for(int j=0;j<8;j++)
	{
		
			tabuleiro[i][j] = new CCubo();
			if(cor)
				tabuleiro[i][j]->SetCor(0,0,0);
			else
				tabuleiro[i][j]->SetCor(1,1,1);
			tabuleiro[i][j]->Esc(1,0.6,1);
			tabuleiro[i][j]->Trans(j+0.5,-0.3,i+0.5);
			AddObject(tabuleiro[i][j]);
			cor=!cor;
		}
		cor=!cor;

	}

	/*-----------------------Peças Brancas--------------------------*/

	//Experiencia
	//VTorre*
	
	/*AddObject(teste);
	pecas[0][0]->Init();
	*/

	VTorre* t1_b=new VTorre(0);
	t1_b->mudarPosicao(0,0);
	t1_b->Init();
	pecas[0][0]=t1_b;
	AddObject(t1_b);

	VCavalo* c1_b=new VCavalo(0);
	c1_b->mudarPosicao(1,0);
	c1_b->Init();
	pecas[1][0]=c1_b;
	AddObject(c1_b);

	VBispo* b1_b=new VBispo(0);
	b1_b->mudarPosicao(2,0);
	b1_b->Init();
	pecas[2][0]=b1_b;
	AddObject(b1_b);

	VRainha* ra_b=new VRainha(0);
	ra_b->mudarPosicao(3,0);
	ra_b->Init();
	pecas[3][0]=ra_b;
	AddObject(ra_b);

	VRei* re_b=new VRei(0);
	re_b->mudarPosicao(4,0);
	re_b->Init();
	pecas[4][0]=re_b;
	AddObject(re_b);

	VBispo* b2_b=new VBispo(0);
	b2_b->mudarPosicao(5,0);
	b2_b->Init();
	pecas[5][0]=b2_b;
	AddObject(b2_b);

	VCavalo* c2_b=new VCavalo(0);
	c2_b->mudarPosicao(6,0);
	c2_b->Init();
	pecas[6][0]=c2_b;
	AddObject(c2_b);

	VTorre* t2_b=new VTorre(0);
	t2_b->mudarPosicao(7,0);
	t2_b->Init();
	pecas[7][0]=t2_b;
	AddObject(t2_b);

	VPeao* p1_b=new VPeao(0);
	p1_b->mudarPosicao(0,1);
	p1_b->Init();
	pecas[0][1]=p1_b;
	AddObject(p1_b);

	VPeao* p2_b=new VPeao(0);
	p2_b->mudarPosicao(1,1);
	p2_b->Init();
	pecas[1][1]=p2_b;
	AddObject(p2_b);

	VPeao* p3_b=new VPeao(0);
	p3_b->mudarPosicao(2,1);
	p3_b->Init();
	pecas[2][1]=p3_b;
	AddObject(p3_b);

	VPeao* p4_b=new VPeao(0);
	p4_b=new VPeao(0);
	p4_b->mudarPosicao(3,1);
	p4_b->Init();
	pecas[3][1]=p4_b;
	AddObject(p4_b);

	VPeao* p5_b=new VPeao(0);
	p5_b->mudarPosicao(4,1);
	p5_b->Init();
	pecas[4][1]=p5_b;
	AddObject(p5_b);

	VPeao* p6_b=new VPeao(0);
	p6_b->mudarPosicao(5,1);
	p6_b->Init();
	pecas[5][1]=p6_b;
	AddObject(p6_b);

	VPeao* p7_b=new VPeao(0);
	p7_b->mudarPosicao(6,1);
	p7_b->Init();
	pecas[6][1]=p7_b;
	AddObject(p7_b);

	VPeao* p8_b=new VPeao(0);
	p8_b->mudarPosicao(7,1);
	p8_b->Init();
	pecas[7][1]=p8_b;
	AddObject(p8_b);

	///*-------------------------Pecas Pretas-----------------------------*/

	VTorre* t1_p=new VTorre(1);
	t1_p->mudarPosicao(0,7);
	t1_p->Init();
	pecas[0][7]=t1_p;
	AddObject(t1_p);

	VCavalo* c1_p=new VCavalo(1);
	c1_p->mudarPosicao(1,7);
	c1_p->Init();
	pecas[1][7]=c1_p;
	AddObject(c1_p);

	VBispo* b1_p=new VBispo(1);
	b1_p->mudarPosicao(2,7);
	b1_p->Init();
	pecas[2][7]=b1_p;
	AddObject(b1_p);

	VRainha* ra_p=new VRainha(1);
	ra_p=new VRainha(1);
	ra_p->mudarPosicao(3,7);
	ra_p->Init();
	pecas[3][7]=ra_p;
	AddObject(ra_p);

	VRei* re_p=new VRei(1);
	re_p->mudarPosicao(4,7);
	re_p->Init();
	pecas[4][7]=re_p;
	AddObject(re_p);

	VBispo* b2_p=new VBispo(1);
	b2_p->mudarPosicao(5,7);
	b2_p->Init();
	pecas[5][7]=b2_p;
	AddObject(b2_p);

	VCavalo* c2_p=new VCavalo(1);
	c2_p->mudarPosicao(6,7);
	c2_p->Init();
	pecas[6][7]=c2_p;
	AddObject(c2_p);

	VTorre* t2_p=new VTorre(1);
	t2_p->mudarPosicao(7,7);
	t2_p->Init();
	pecas[7][7]=t2_p;
	AddObject(t2_p);

	VPeao* p1_p=new VPeao(1);
	p1_p->mudarPosicao(0,6);
	p1_p->Init();
	pecas[0][6]=p1_p;
	AddObject(p1_p);

	VPeao* p2_p=new VPeao(1);
	p2_p->mudarPosicao(1,6);
	p2_p->Init();
	pecas[1][6]=p2_p;
	AddObject(p2_p);

	VPeao* p3_p=new VPeao(1);
	p3_p->mudarPosicao(2,6);
	p3_p->Init();
	pecas[2][6]=p3_p;
	AddObject(p3_p);

	VPeao* p4_p=new VPeao(1);
	p4_p->mudarPosicao(3,6);
	p4_p->Init();
	pecas[3][6]=p4_p;
	AddObject(p4_p);

	VPeao* p5_p=new VPeao(1);
	p5_p->mudarPosicao(4,6);
	p5_p->Init();
	pecas[4][6]=p5_p;
	AddObject(p5_p);

	VPeao* p6_p=new VPeao(1);
	p6_p->mudarPosicao(5,6);
	p6_p->Init();
	pecas[5][6]=p6_p;
	AddObject(p6_p);

	VPeao* p7_p=new VPeao(1);
	p7_p->mudarPosicao(6,6);
	p7_p->Init();
	pecas[6][6]=p7_p;
	AddObject(p7_p);

	VPeao* p8_p=new VPeao(1);
	p8_p->mudarPosicao(7,6);
	p8_p->Init();
	pecas[7][6]=p8_p;
	AddObject(p8_p);

	//Preencher os restantes espaços do tabuleiro com ComplexObject3d para que se possa capturar uma peca
	for(int i=2;i<6;i++){
		for(int j=0;j<8;j++){
			VVazio* v=new VVazio();
			v->mudarPosicao(j,i);
			v->Init();
			pecas[j][i]=v;
			AddObject(v);
			//printf("x=%d y=%d",j,i);
		}
	}


	//pecas[0][0]->mudarPosicao(0,3);
	tabuleiro[0][0]->SetCor(0.6,0.6,1);//inicialmente colocar a cor do primeiro quadrado com a cor do cursor
	//tabuleiro[0][0]->SetCor(0.9,0.8,0);

	

	//Fazer o giant cube para a base do tabuleiro
	CuboComText* base = new CuboComText();
	base->SetCor(0.9,0.8,0);
	base->Esc(10,1.75,10);
	base->Trans(4,-0.89,4);
	AddObject(base);

	//colocar o tabuleiro numa posicao mais central para usar melhor a camera
	Trans(-4,0,-4);

	//printf("Estou a renderizar o tabuleiro");
	//if(!mov)
	//	printf("Ele não esta a executar movimento");
	
}



void VTabuleiro::selecionarCasa()
{
	if(andarNoTabuleiro){//seleciona uma casa

		//Se a casa for uma das jogadas disponíveis de acordo com as regras lógicas é entao apresentado o cursor vermelho
		if(logicTab->selecionarPeca(x,y)){
			tabuleiro[x][y]->SetCor(1,0,0);//coloca a casa seleciona a vermelho
			andarNoTabuleiro=false;//coloca a varivel andarNoTabuleiro a false para o jogador não poder andar mais no tabuleiro
			//colocar as variaves xf e yf com o mesmo valor que as variveis x e f para partir da mesma posicao que a casa selecionada
			xf=x;
			yf=y;
			som->SomMovimento1();
		}else{
			andarNoTabuleiro=true;
		}
		iluminarJogadasPossiveis();
	}else{//se a casa ja foi selecionada e o utilizador carregar novamente enter o programa executa o movimento
		desiluminarJogadasPossiveis();
		//verificar se a jogada é possivel dentro da lógica do tabuleiro. Se a jogada não for possivel entao voltamos a andar com o cursor azul
		if(logicTab->selecionarPosicao(xf,yf)){//se a jogada for possivel ele executa a jogada na parte lógica e depois mostra a animacao na parte gráfica
			printf("Vamos comecar o movimento\n");
			printf("x =%d\n",x);
			printf("y =%d\n",y);
			printf("xf=%d\n",xf);
			printf("yf=%d\n",yf);
			calculosIniciais();//faz os calculos iniciais antes de comecar a movimentar a peca
			mov=true;//colocar a variavel mov a true para iniciar o movimento
		}else{
			desseleccionarCasa();
		}
	}
}

void VTabuleiro::desseleccionarCasa(){
	if(!andarNoTabuleiro){//clicando novamente no enter ele volta a tras para que se possa selecionar outra peca
		//coloca a peca na sua cor original
		tabuleiro[xf][yf]->SetCor(0.6,0.6,1);
		andarNoTabuleiro=true;//coloca a variavel que permite andar no tabuleiro novamente a true
		//guarda a posicao em que se encontra o cursor vermelho nas variaveis do cursor azul
		x=xf;
		y=yf;
		som->SomMovimento2();
		desiluminarJogadasPossiveis();
	}
}

void VTabuleiro::moverTestePeca(int xfarg, int yfarg)
{
	//if(mov=false){
	//	mov=true;//coloca a variavel mov a true para comecar o movimento
	//	//xf=xfarg;//inicializa a variavel x para comecar a incrementar
	//	//yf=yfarg;//inicializa a variavel y para comecar a incrementar
	//	
	//}

	pecas[0][0]->Trans(0.01,0,0.01);
	
}

void VTabuleiro::cursorParaCima(){
	if(!mov){//se uma peca não estiver em movimento então é possivel andar com o cursor
		if(andarNoTabuleiro){//andar no tabuleiro para selecionar uma casa
			if(y<7)
			{
				//colocar o cubo na sua cor original
				if((x+y)%2==0)
					tabuleiro[x][y]->SetCor(0,0,0);
				else
					tabuleiro[x][y]->SetCor(1,1,1);

				//incrementar uma unidade ao y
				y++;

				//colocar o cubo na sua nova cor
				tabuleiro[x][y]->SetCor(0.6,0.6,1);
			}
		}else{//andar no tabuleiro para selecionar uma casa para movimentar
			if(yf<7)
			{
				//colocar o cubo na sua cor original
				if((xf+yf)%2==0)
					tabuleiro[xf][yf]->SetCor(0,0,0);
				else
					tabuleiro[xf][yf]->SetCor(1,1,1);

				//incrementar uma unidade ao y
				yf++;

				//pinta as casas com as jogadas posiveis
				iluminarJogadasPossiveis();

				//colocar o cubo na sua nova cor
				tabuleiro[xf][yf]->SetCor(1,0,0);
				
			}
		}
	}
}

void VTabuleiro::cursorParaBaixo(){
	if(!mov){//se uma peca não estiver em movimento então é possivel andar com o cursor
		if(andarNoTabuleiro){//andar no tabuleiro para selecionar uma casa
			if(y>0)
			{
				//colocar o cubo na sua cor original
				if((x+y)%2==0)
					tabuleiro[x][y]->SetCor(0,0,0);
				else
					tabuleiro[x][y]->SetCor(1,1,1);

				//decrementar uma unidade ao y
				y--;

				//colocar o cubo na sua nova cor
				tabuleiro[x][y]->SetCor(0.6,0.6,1);
			}
		}else{//andar no tabuleiro para selecionar uma casa para movimentar
			if(yf>0)
			{
				//colocar o cubo na sua cor original
				if((xf+yf)%2==0)
					tabuleiro[xf][yf]->SetCor(0,0,0);
				else
					tabuleiro[xf][yf]->SetCor(1,1,1);

				//decrementar uma unidade ao y
				yf--;

				//pinta as casas com as jogadas posiveis
				iluminarJogadasPossiveis();

				//colocar o cubo na sua nova cor
				tabuleiro[xf][yf]->SetCor(1,0,0);
			}
		}
	}
}

void VTabuleiro::cursorParaEsquerda(){
	if(!mov){//se uma peca não estiver em movimento então é possivel andar com o cursor
		if(andarNoTabuleiro){//andar no tabuleiro para selecionar uma casa
			if(x>0)
			{
				//colocar o cubo na sua cor original
				if((x+y)%2==0)
					tabuleiro[x][y]->SetCor(0,0,0);
				else
					tabuleiro[x][y]->SetCor(1,1,1);

				//decrementar uma unidade ao x
				x--;

				//colocar o cubo na sua nova cor
				tabuleiro[x][y]->SetCor(0.6,0.6,1);
			}
		}else{//andar no tabuleiro para selecionar uma casa para movimentar
			if(xf>0)
			{
				//colocar o cubo na sua cor original
				if((xf+yf)%2==0)
					tabuleiro[xf][yf]->SetCor(0,0,0);
				else
					tabuleiro[xf][yf]->SetCor(1,1,1);

				//decrementar uma unidade ao x
				xf--;

				//pinta as casas com as jogadas posiveis
				iluminarJogadasPossiveis();

				//colocar o cubo na sua nova cor
				tabuleiro[xf][yf]->SetCor(1,0,0);
			}
		}
	}
}

void VTabuleiro::cursorParaDireita(){
	if(!mov){//se uma peca não estiver em movimento então é possivel andar com o cursor
		if(andarNoTabuleiro){//andar no tabuleiro para selecionar uma casa
			if(x<7)
			{
				//colocar o cubo na sua cor original
				if((x+y)%2==0)
					tabuleiro[x][y]->SetCor(0,0,0);
				else
					tabuleiro[x][y]->SetCor(1,1,1);

				//incrementar uma unidade ao x
				x++;

				//colocar o cubo na sua nova cor
				tabuleiro[x][y]->SetCor(0.6,0.6,1);
			}
		}else{//andar no tabuleiro para selecionar uma casa para movimentar
			if(xf<7)
			{
				//colocar o cubo na sua cor original
				if((xf+yf)%2==0)
					tabuleiro[xf][yf]->SetCor(0,0,0);
				else
					tabuleiro[xf][yf]->SetCor(1,1,1);

				//incrementar uma unidade ao x
				xf++;

				//pinta as casas com as jogadas posiveis
				iluminarJogadasPossiveis();

				//colocar o cubo na sua nova cor
				tabuleiro[xf][yf]->SetCor(1,0,0);
			}
		}
	}
}

void VTabuleiro::calculosIniciais(){
	//inicio dos calculos inicias para o movimento da peca até ao seu destino

	//variaveis que são colocadas a false no inicio do programa e fim de um movimento em x e y.
		movx=false;
		movy=false;

		//variaveis para ir incrementando ate chegar ao destino
		xinc=x+0.5;//o programa vai incrementar ou decrementar estes dois (xinc e yinc) valores até a peca chegar ao seu destino
		yinc=y+0.5;

		

		//coloca as peca na posicao 0 0 (z x) do tabuleiro
		//printf("Ele está a executar o movimento");

		//verifica se tem de incrementar ou decrementar valores em x
		if(xf>x){//se a posicao final da peca for superior a inicial vai incrementar
			velocx=veloc;
			boolIncx=true;
		}else if(xf<x){//se a posicao final da peca for inferior a inicial vai decrementar
			velocx=-veloc;
			boolIncx=false;
		}else{//se x e xf forem iguais a peca nunca vai se mexer nas coordenadas de x
			movx=true;
			printf("A peca não se vai movimentar em x\n");
		}

		//verifica se tem de incrementar ou decrementar valores em y
		if(yf>y){//se a posicao final da peca for superior a inicial vai incrementar
			velocy=veloc;
			boolIncy=true;
		}else if(yf<y){//se a posicao final da peca for inferior a inicial vai decrementar
			velocy=-veloc;
			boolIncy=false;
		}else{//se y e yf forem iguais a peca nunca vai se mexer nas coordenadas de y
			movy=true;
			printf("A peca não se vai movimentar em y\n");
		}

		//inicio dos calculos inicias para a captura da peca que se encontra no destino
		existePecaParaCapturar=false;
		//verifica se existe uma peca para onde a peca vai ser jogada
		if(!pecas[xf][yf]->estaVazio()){
			existePecaParaCapturar=true;
			auxTransCaptura=0.0;
			auxCapturaParaBorda=true;
			movimentoBaixo=true;
			printf("Existe uma peca para capturar\n");
		}
		//inicio dos calculos inicias para a captura da peca que se encontra no destino
}

void VTabuleiro::movimentarPeca(double elapsedTime){
	if(mov)
	{
		//inicio do codigo animacao da captura da peca
		if(existePecaParaCapturar){
			if(movimentoBaixo){
				auxTransCaptura=auxTransCaptura-velocCap*elapsedTime;

				if(auxTransCaptura<-1.5){//Se a peca ja tiver passado uma altura que não se vê é entao feita uma translacao para a borda do tabuleiro da sua cor
					if(auxCapturaParaBorda){//Aqui faz a translacao para a borda do jogador preto ao branco
						if(pecas[xf][yf]->getCor()==0){//Se for uma peca branca a ser captura
							pecas[xf][yf]->Trans(0,0,-xf-1);//translacao para a borda branca
							pecas[xf][yf]->Trans(-yf,0,0);
							pecas[xf][yf]->Trans(numPecasBrancasFora++,0,0);//translacao para a sua posicao correcta de acordo com o numero de pecas que existe no tabuleiro
							movimentoBaixo=false;//coloca esta variavel a false porque terminou o movimento
						}else{//se for uma peca preta a ser a capturada
							pecas[xf][yf]->Trans(0,0,(8-xf));
							pecas[xf][yf]->Trans(7-yf,0,0);
							pecas[xf][yf]->Trans(-numPecasPretasFora,0,0);//translacao para a sua posicao correcta de acordo com o numero de pecas que existe no tabuleiro
							numPecasPretasFora++;
							movimentoBaixo=false;//coloca esta variavel a false porque terminou o movimento
						}
						auxCapturaParaBorda=false;
					}
				}else{//se a peca ainda não tiver desaparecido
					//codigo para subir a peca para baixo

					pecas[xf][yf]->Trans(0,-velocCap*elapsedTime,0);
					//printf("AuxTransCaptura: %f\n",auxTransCaptura);
				}
			}else{
				auxTransCaptura=auxTransCaptura+velocCap*elapsedTime;
				//codigo para subir a peca para cima
				if((auxTransCaptura<0.0)){
					pecas[xf][yf]->Trans(0,velocCap*elapsedTime,0);
				}else{//aqui terminou o movimento para cima
					existePecaParaCapturar=false;//termina a captura da peca
					//A peca é entao colocada fora do array do tabuleiro
					if(pecas[xf][yf]->getCor()==0){//Se for de cor branca é colocado no array de pecas Brancas
						pecasBrancas[numPecasBrancasFora]=pecas[xf][yf];
						pecas[xf][yf]=new VVazio();//coloca a referencia do array do tabuleiro com uma casa vazia
					}
					else{//se for preto é colocado no array de pecas Pretas
						pecasPretas[numPecasPretasFora]=pecas[xf][yf];
						pecas[xf][yf]=new VVazio();//coloca a referencia do array do tabuleiro com uma casa vazia
					}
				}
			}
		}

		

		//fim do codigo animacao da captura da peca

		//incio do codigo animacao relativo a peca selecionada pelo jogador para movimentar a peca
		if(!movx){
			pecas[x][y]->Trans(0,0,velocx*elapsedTime);
			xinc=xinc+velocx*elapsedTime;
			if(boolIncx){
				if(xinc>=xf+0.5){
					movx=true;
					printf("O movimento terminou em x\n");
				}
			}else{
				if(xinc<=xf+0.5){
					movx=true;
					printf("O movimento terminou em x\n");
				}
			}
		}

		if(!movy){//se a posicao final da peca for superior a inicial vai incrementar
			pecas[x][y]->Trans(velocy*elapsedTime,0,0);
			yinc=yinc+velocy*elapsedTime;
			if(boolIncy){
				if(yinc>=yf+0.5){
					movy=true;
					printf("O movimento terminou em y\n");
				}
			}else{
				if(yinc<=yf+0.5){
					movy=true;
					printf("O movimento terminou em y\n");
				}
			}
		}
		//fim do codigo animacao relativo a peca selecionada pelo jogador para movimentar a peca


		if(movx==true && movy==true && existePecaParaCapturar==false){
			printf("O movimento terminou tanto em x como em y\n");
			
			movx=false;
			movy=false;

			//quando o movimento terminar coloca novamente a casa na de cor azul
			//tabuleiro[xf][yf]->SetCor(0.6,0.6,1);

			//quando o movimento terminar coloca novamente a peca na sua posicao correcta no array de casas
			pecas[xf][yf]=pecas[x][y];

			//chamar o metodo que permite desselecionar a casa para poder voltar a trabalhar com o cursor azul
			desseleccionarCasa();

			//coloca a variavel a false assim que o movimento estiver concluido
			mov=false;

			

			if(!(logicTab->verificaVezDoJogador())){
				if(comp){//Se for para jogar contra o computador
					//desilumina a posicao do cursor
					if((xf+yf)%2==0)
						tabuleiro[xf][yf]->SetCor(0,0,0);
					else
						tabuleiro[xf][yf]->SetCor(1,1,1);
					int t=0;//quando existir uma jogada com uma peca que seja possivel esta variavel vais estar com uma valor maior que 0
					do{
						desseleccionarCasa();
						//1-Selecionar uma peca aléatoria
						//enqunto nao encontrar uma peca peca preta ele vai andar no ciclo
						int xaux,yaux;
						for(;;){
							xaux=rand()%(8);
							yaux=rand()%(8);
							if(pecas[xaux][yaux]->getCor()==1)
								break;
						}
						x=xaux;
						y=yaux;
						selecionarCasa();

						if((x+y)%2==0)
							tabuleiro[xf][yf]->SetCor(0,0,0);
						else
							tabuleiro[xf][yf]->SetCor(1,1,1);
						if((xf+yf)%2==0)
							tabuleiro[xf][yf]->SetCor(0,0,0);
						else
							tabuleiro[xf][yf]->SetCor(1,1,1);
						//2-Selecionar um dos movimentos aléatorios

						t=(*logicTab->getMovimentosPeca()).size();

					}while(t==0);
					//printf("*******************************************************************\n");
					//printf("indice da jogada: %d\n",t);
					
					int jog=rand()%(t);//Para guardar um valor da jogada aleatória de entre as jogadas posiveis

					xf=((*logicTab->getMovimentosPeca()).at(jog)).first;
					yf=((*logicTab->getMovimentosPeca()).at(jog)).second;

					selecionarCasa();
					//desiluminar cursor vermelho
					if((xf+yf)%2==0)
						tabuleiro[xf][yf]->SetCor(0,0,0);
					else
						tabuleiro[xf][yf]->SetCor(1,1,1);
					
				}
			}
		}
	}

	


}

void VTabuleiro::adicionarPeca()
{

}
void VTabuleiro::Draw()
{
}

void VTabuleiro::Destroy()
{
}

void VTabuleiro::iluminarJogadasPossiveis(){
	int t=(*logicTab->getMovimentosPeca()).size();
	for(int i=0;i<t;i++){
		tabuleiro[((*logicTab->getMovimentosPeca()).at(i)).first][((*logicTab->getMovimentosPeca()).at(i)).second]->SetCor(0.6,0.6,1);
	}
}

void VTabuleiro::desiluminarJogadasPossiveis(){
	int t=(*logicTab->getMovimentosPeca()).size();
	for(int i=0;i<t;i++){
		tabuleiro[((*logicTab->getMovimentosPeca()).at(i)).first][((*logicTab->getMovimentosPeca()).at(i)).second]->SetCor(0.6,0.6,1);
		if((((*logicTab->getMovimentosPeca()).at(i)).first+((*logicTab->getMovimentosPeca()).at(i)).second)%2==0)
			tabuleiro[((*logicTab->getMovimentosPeca()).at(i)).first][((*logicTab->getMovimentosPeca()).at(i)).second]->SetCor(0,0,0);
		else
			tabuleiro[((*logicTab->getMovimentosPeca()).at(i)).first][((*logicTab->getMovimentosPeca()).at(i)).second]->SetCor(1,1,1);
	}
}

bool VTabuleiro::estaVazio(){//este metodo aqui nao faz muito sentido
	return false;
}

int VTabuleiro::getAltura(){//este metodo não faz muito sentido aqui
	return 0;
}

void VTabuleiro::jogarContraComputador(){
	comp=!comp;
}
