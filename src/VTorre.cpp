#include "VTorre.h"


VTorre::VTorre(int cor)
{
	this->cor=cor;
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

	//valor do do scale por default
	//scale=1;

	Trans(0.5,0,0.5);
}


VTorre::~VTorre(void)
{
}

void VTorre::Draw()
{
}


void VTorre::Init ()
{

	//t1
	adicionaCilindro(0.40,0.37,0.4);

	//t2
	adicionaCilindro(0.30,0.26,0.3);

	//t3
	adicionaCilindro(0.26,0.3,0.4);

	//t4
	adicionaCilindro(0.3,0.19,0.4);

	//t5
	adicionaCilindro(0.19,0.14,2);

	//t6
	adicionaCilindro(0.14,0.2,0.4);

	//t7
	adicionaCilindro(0.23,0.23,0.4);

	//t8
	adicionaCilindro(0.23,0.20,0.7);


	// Arvore com cerca de 10 metros de altura e coloca o tronco no plano z=0 (chao supostamente)
//	Esc(5,5,5);
//	Trans (0,3,0);
}


void VTorre::SetTipo (int t)
{
	tipo = t;
}

void VTorre::Destroy ()
{
}

void VTorre::adicionaCilindroX(float novoRaio,float altura){
	//Peao::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raioAux,novoRaio);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(0,x,0);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=novoRaio;
}

void VTorre::adicionaCilindro(float raio1,float raio2,float altura){
	//Peao::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raio1,raio2);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5*scale,altura*scale,5*scale);
	novo_cilindro->Trans(posx,x,posy);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	//raioAux=0;
}

void VTorre::adicionaCilindro(float raio,float altura){
	VTorre::adicionaCilindro(raio,raio,altura);
}

void VTorre::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b-=0.05;
}

int VTorre::getAltura(){
	return alturaTotal;
}

//void VTorre::setScale(float scale){
//	this->scale=scale;
//}
//
//float VTorre::getScale(){
//	return scale;
//}

//void VTorre::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VTorre::estaVazio(){
	return false;
}