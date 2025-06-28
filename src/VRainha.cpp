#include "VRainha.h"


VRainha::VRainha(int cor)
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

	//scale=1;

	Trans(0.5,0,0.5);
}


VRainha::~VRainha(void)
{
}

void VRainha::Draw()
{
}


void VRainha::Init ()
{

	//b1
	adicionaCilindro(0.40,0.37,0.4);

	//b2
	adicionaCilindro(0.33,0.29,0.3);

	//b3
	adicionaCilindro(0.26,0.30,0.4);

	//b4
	adicionaCilindro(0.3,0.20,0.4);

	//b5
	adicionaCilindro(0.20,0.13,3);

	//b6
	adicionaCilindro(0.13,0.2,0.4);

	//b7
	adicionaCilindro(0.2,0.23,0.4);
	
	//b10
	adicionaCilindro(0.27,0.27,0.2);

	//b9
	adicionaCilindro(0.24,0.24,0.2);

	//b8
	adicionaCilindro(0.21,0.21,0.2);

	//b8
	adicionaCilindro(0.21,0.27,0.6);

	//b8
	adicionaCilindro(0.27,0.27,0.2);

	//b9
	adicionaCilindro(0.14,0.14,0.15);

	//b10
	adicionaCilindroX(0.13,0.15);

	//b11
	adicionaCilindroX(0.11,0.13);

	//b12
	adicionaCilindroX(0.09,0.10);

	//b13
	adicionaCilindroX(0,0.10);

	Esfera *b10 = new Esfera(numFaces);
	b10->SetCor(r,g,b);
	b10->Rot(90,1,0,0);
	b10->Esc(0.2*scale,0.2*scale,0.2*scale);
	b10->Trans(0,7.5*scale,0);
	AddObject(b10);

}


void VRainha::SetTipo (int t)
{
	tipo = t;
}

void VRainha::Destroy ()
{
}

void VRainha::adicionaCilindroX(float novoRaio,float altura){
	//Rainha::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VRainha::adicionaCilindro(float raio1,float raio2,float altura){
	//Rainha::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VRainha::adicionaCilindro(float raio,float altura){
	VRainha::adicionaCilindro(raio,raio,altura);
}

void VRainha::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b=0.05;
}

int VRainha::getAltura(){
	return alturaTotal;
}

//void VRainha::setScale(float scale){
//	this->scale=scale;
//}
//
//float VRainha::getScale(){
//	return scale;
//}

//void VRainha::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VRainha::estaVazio(){
	return false;
}