#include "VPeao.h"



VPeao::VPeao(int cor)
{
	this->cor=cor;
	//se for preto
	if(cor==1)
	{
		r=0.1;
		g=0.1;
		b=0.1;
	}else
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


VPeao::~VPeao(void)
{
}


void VPeao::Draw()
{
}


void VPeao::Init ()
{
	
	//p1
	adicionaCilindro(0.30,0.28,0.4);

	//p2
	adicionaCilindro(0.22,0.15,0.2);

	//p3
	adicionaCilindro(0.15,0.2,0.4);

	//p4
	adicionaCilindro(0.2,0.14,0.4);

	//p5
	adicionaCilindro(0.14,0.11,1.5);

	//p6
	adicionaCilindro(0.11,0.11,0.4);

	//p7
	adicionaCilindro(0.2,0.14,0.4);
		
	//p8
	Esfera *p8 = new Esfera(numFaces);
	p8->SetCor(r,g,b);
	p8->Rot(90,1,0,0);
	p8->Esc(0.8*scale,0.8*scale,0.8*scale);
	p8->Trans(posx,4.3*scale,posy);
	AddObject(p8);
}


/*void VPeao::SetTipo (int t)
{
	tipo = t;
}*/

void VPeao::Destroy ()
{
}

void VPeao::adicionaCilindroX(float novoRaio,float altura){
	//Peao::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=alturaTotal+altura/2.0;

	CCilindro *novo_cilindro = new CCilindro(numFaces,2*3.14,raioAux,novoRaio);
	novo_cilindro->SetCor(r,g,b);
	novo_cilindro->Rot(90,1,0,0);
	novo_cilindro->Esc(5,altura,5);
	novo_cilindro->Trans(0,x,0);
	AddObject(novo_cilindro);

	alturaTotal+=altura;
	raioAux=novoRaio;
}

void VPeao::adicionaCilindro(float raio1,float raio2,float altura){
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

void VPeao::adicionaCilindro(float raio,float altura){
	VPeao::adicionaCilindro(raio,raio,altura);
}

void VPeao::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b-=0.05;
}

int VPeao::getAltura(){
	return alturaTotal;
}

//void VPeao::setScale(float scale){
//	this->scale=scale;
//}
//
//float VPeao::getScale(){
//	return scale;
//}

//void VPeao::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VPeao::estaVazio(){
	return false;
}

