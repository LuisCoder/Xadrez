#include "VRei.h"


VRei::VRei(int cor)
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


VRei::~VRei(void)
{
}

void VRei::Draw()
{
}


void VRei::Init ()
{

	//b1
	adicionaCilindro(0.43,0.40,0.4);

	//b2
	adicionaCilindro(0.33,0.29,0.3);

	//b3
	adicionaCilindro(0.26,0.30,0.4);

	//b4
	adicionaCilindro(0.3,0.20,0.4);

	//b5
	adicionaCilindro(0.20,0.13,3.5);

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
	adicionaCilindro(0.21,0.31,1);

	//b8
	adicionaCilindro(0.31,0.31,0.2);


	CCubo *b10 = new CCubo();
	b10->SetCor(r,g,b);
	//b10->Rot(90,1,0,0);
	b10->Esc(0.3*scale,0.8*scale,0.3*scale);
	b10->Trans(0,(alturaTotal+0.8/2.0)*scale,0);
	AddObject(b10);

	CCubo *b101 = new CCubo();
	b101->SetCor(r,g,b);
	b101->Esc(0.3*scale,0.90*scale,0.3*scale);
	b101->Rot(90,0,0,1);
	b101->Trans(0,(alturaTotal+0.90/2.0)*scale,0);
	AddObject(b101);

}


void VRei::SetTipo (int t)
{
	tipo = t;
}

void VRei::Destroy ()
{
}

void VRei::adicionaCilindroX(float novoRaio,float altura){
	//Peao::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VRei::adicionaCilindro(float raio1,float raio2,float altura){
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

void VRei::adicionaCilindro(float raio,float altura){
	VRei::adicionaCilindro(raio,raio,altura);
}

void VRei::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b-=0.05;
}

int VRei::getAltura(){
	return alturaTotal;
}

//void VRei::setScale(float scale){
//	this->scale=scale;
//}
//
//float VRei::getScale(){
//	return scale;
//}

//void VRei::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VRei::estaVazio(){
	return false;
}