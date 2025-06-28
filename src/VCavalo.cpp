#include "VCavalo.h"


VCavalo::VCavalo(int cor)
{
	this->cor=cor;
	//rodar o cavalo branco para a posicao do tabuleiro
	if(cor==1)
		Rot(180,0,1,0);

	//se for preto
	if(cor==1)
	{
		r=0.1;
		g=0.1;
		b=0.1;
	}
	else
	{
		r=0.9;
		g=0.9;
		b=0.9;
	}
	pri=true;
	posAux=0.0;
	alturaTotal=0.0;
	numFaces=20;
	//scale=1;

	Trans(0.5,0,0.5);
}


VCavalo::~VCavalo(void)
{
}


void VCavalo::Draw()
{
}

void VCavalo::Destroy ()
{
}

void VCavalo::Init ()
{
	//b1
	adicionaCilindro(0.40,0.37,0.4);
	
	//b2
	adicionaCilindro(0.30,0.26,0.3);

	//b3
	adicionaCilindro(0.26,0.30,0.4);

	//b4
	adicionaCilindro(0.3,0.17,0.4);

	//b5
	adicionaCilindroX(0.25,0.65,0,0,0.1,0);

	//b6
	adicionaCilindroX(0.1,1.7,0.1,0,-0.1,0);

	//b7
	//adicionaCilindroX(0.15,0.2,-0.1,0,0,0);

	//b8
	adicionaCilindroX_Elipse(0.27,0.15,0.3,-0.1,0,0.1,0);

	//b9
	adicionaCilindroX_Elipse(0.25,0.15,0.4,0.1,0,0.1,0);

	//b10
	adicionaCilindroX_Elipse(0.1,0.1,0.4,0.1,0,0,0);

	//b11
	adicionaCilindroX_Elipse(0.0,0.0,0.2,0,0,0,0);

	//orelhas
	//1ª orelha
	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,2,0.7,0,0);
	novo_cilindro->SetLocalTopo(0,0);
	novo_cilindro->SetLocalBase(-2,0);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(100,0,0,1);
	novo_cilindro->Rot(50,0,1,0);
	novo_cilindro->Esc(0.2*scale,0.2*scale,0.2*scale);
	novo_cilindro->Trans(-0.25*scale,5.17*scale,0.25*scale);
	AddObject(novo_cilindro);

	//2ªorelha
	CCilindro *novo_cilindro1 = new CCilindro(numFaces,2*3.14,2,0.7,0,0);
	novo_cilindro1->SetLocalTopo(0,0);
	novo_cilindro1->SetLocalBase(-2,0);
	novo_cilindro1->SetCor(r,g,b);
	novo_cilindro1->Rot(80,0,0,1);
	novo_cilindro1->Rot(140,0,1,0);
	novo_cilindro1->Esc(0.2*scale,0.2*scale,0.2*scale);
	novo_cilindro1->Trans(-0.25*scale,5.17*scale,-0.25*scale);
	AddObject(novo_cilindro1);

	
}

void VCavalo::adicionaCilindroX(float novoRaio,float altura){
	//Cavalo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raioAux,novoRaio);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=novoRaio;
}

void VCavalo::adicionaCilindro(float raio1,float raio2,float altura){
	//Cavalo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raio1,raio2);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=raio2;
}

void VCavalo::adicionaCilindro(float raio,float altura){
	VCavalo::adicionaCilindro(raio,raio,altura);
}

void VCavalo::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b-=0.05;
}

//void VCavalo::setScale(float scale){
//	this->scale=scale;
//}
//
//float VCavalo::getScale(){
//	return scale;
//}

void VCavalo::adicionaCilindroX(float novoRaio,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Cavalo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raioAux,novoRaio);
	novo_cilindro->SetLocalTopo(localTopo_1,localTopo_2);
	novo_cilindro->SetLocalBase(localBase_1,localBase_2);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=novoRaio;
	raioAux_Elipse_1=novoRaio;
	raioAux_Elipse_2=novoRaio;
}

void VCavalo::adicionaCilindro(float raio1,float raio2,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Cavalo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=alturaTotal+altura/2.0;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raio1,raio2);
	novo_cilindro->SetLocalTopo(localTopo_1,localTopo_2);
	novo_cilindro->SetLocalBase(localBase_1,localBase_2);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=raio2;
}

void VCavalo::adicionaCilindro(float raio,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	VCavalo::adicionaCilindro(raio,raio,altura);
}

void VCavalo::adicionaCilindroX_Elipse(float novoRaio1,float novoRaio2,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Cavalo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raioAux_Elipse_1,raioAux_Elipse_2,novoRaio1,novoRaio2);
	novo_cilindro->SetLocalTopo(localTopo_1,localTopo_2);
	novo_cilindro->SetLocalBase(localBase_1,localBase_2);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux_Elipse_1=novoRaio1;
	raioAux_Elipse_2=novoRaio2;
}

int VCavalo::getAltura(){
	return alturaTotal;
}

//void VCavalo::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VCavalo::estaVazio(){
	return false;
}