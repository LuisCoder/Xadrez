#include "VBispo.h"


VBispo::VBispo(int cor)
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


VBispo::~VBispo(void)
{
}

void VBispo::Draw()
{
}


void VBispo::Init ()
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
	adicionaCilindro(0.17,0.13,2);

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

	//b9

	adicionaCilindro(0.17,0.18,0.2);

	//b10
	adicionaCilindroX(0.19,0.2);

	//b11
	adicionaCilindroX(0.19,0.4);

	//b12
	adicionaCilindroX(0.18,0.2);

	//b13
	adicionaCilindroX(0.16,0.2);

	//b14
	adicionaCilindroX(0.12,0.2);

	//b15
	adicionaCilindroX(0.04,0.18);

	Esfera *b10 = new Esfera(numFaces);
	b10->SetCor(r,g,b);
	b10->Rot(90,1,0,0);
	b10->Esc(0.3*scale,0.3*scale,0.3*scale);
	b10->Trans(0,6.7*scale,0);
	AddObject(b10);

}


void VBispo::SetTipo (int t)
{
	tipo = t;
}

void VBispo::Destroy ()
{
}

void VBispo::adicionaCilindroX(float novoRaio,float altura){
	//Bispo::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VBispo::adicionaCilindro(float raio1,float raio2,float altura){
	//Bispo::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VBispo::adicionaCilindro(float raio,float altura){
	VBispo::adicionaCilindro(raio,raio,altura);
}

void VBispo::setRandomColor(){
	r+=0.05;
	//g-=0.05;
	b=0.05;
}

void VBispo::adicionaCilindroX(float novoRaio,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Bispo::setRandomColor();//para colocar uma cor aleatória no cilindro
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

void VBispo::adicionaCilindro(float raio1,float raio2,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Bispo::setRandomColor();//para colocar uma cor aleatória no cilindro
	float x=(alturaTotal+altura/2.0)*scale;

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

void VBispo::adicionaCilindro(float raio,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	VBispo::adicionaCilindro(raio,raio,altura);
}

void VBispo::adicionaCilindroX_Elipse(float novoRaio1,float novoRaio2,float altura,float localTopo_1,float localTopo_2,float localBase_1,float localBase_2){
	//Bispo::setRandomColor();//para colocar uma cor aleatória no cilindro
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

int VBispo::getAltura(){
	return alturaTotal;
}

//void VBispo::setScale(float scale){
//	this->scale=scale;
//}
//
//float VBispo::getScale(){
//	return scale;
//}

//void VBispo::mudarPosicao(float x,float y)
//{
//	Trans(x+0.5,0,y+0.5);
//	//posx=x+0.5;
//	//posy=y+0.5;
//}

bool VBispo::estaVazio(){
	return false;
}