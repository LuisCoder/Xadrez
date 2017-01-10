#include ".\ComplexObject3D.h"


CComplexObject3D::CComplexObject3D(void)
{
	num_objectos_simples = 0;

	posx=0;
	posy=0;
	//inicializacao das variaveis da posicao
	posix=0;
	posiy=0;
	
	//escala dos objectos
	scale=0.2;
}

CComplexObject3D::~CComplexObject3D(void)
{
	for (int i=0; i<num_objectos_simples; i++)
	{
		delete (ListaObjectos[i]);
	}
}

void CComplexObject3D::Display ()
{
	if (visible)
	{
		glPushMatrix();
		glMultMatrixf(m);

		for (int i=0; i<num_objectos_simples;i++)
		{
			//ListaObjectos[i]->ApplyMatrix(m);
			ListaObjectos[i]->Display();
		}

		glPopMatrix();
	}
}

void CComplexObject3D::AddObject (CObject3D *objecto)
{
	//objecto->Init();
	ListaObjectos[num_objectos_simples] = objecto;
	num_objectos_simples++;
}

void CComplexObject3D::DeleteLast ()
{
	if (num_objectos_simples>0)
	{
		delete ListaObjectos[num_objectos_simples-1];
		num_objectos_simples--;
	}
}

void CComplexObject3D::Play (char tecla)
{	
	for (int i=0; i<num_objectos_simples;i++)
	{
		ListaObjectos[i]->Play(tecla);
	}
}

void CComplexObject3D::Animate (float tempo, float velocidade)
{	
	for (int i=0; i<num_objectos_simples;i++)
	{
		ListaObjectos[i]->Animate(tempo, velocidade);
	}
}

void CComplexObject3D::Rebuild ()
{
	while (num_objectos_simples>0)
	{
		delete ListaObjectos[num_objectos_simples-1];
		num_objectos_simples--;
	}
	Init ();
}

void CComplexObject3D::Destroy ()
{
	for (int i=0; i<num_objectos_simples; i++)
	{
		delete (ListaObjectos[i]);
	}

}

void CComplexObject3D::setScale(float scale){
	this->scale=scale;
}

float CComplexObject3D::getScale(){
	return scale;
}

void CComplexObject3D::mudarPosicao(float x,float y)
{
	Trans(-posix,0,-posiy);
	Trans(y,0,x);
	posix=y;
	posiy=x;
}

int CComplexObject3D::getCor(){
	return cor;
}