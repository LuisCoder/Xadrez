#pragma once

//#include <stdio.h>
#include "SimpleObject3D.h"
//#include "ComplexObject3d.h"
#include "Cubo.h"
#include "Cilindro.h"
#include "Esfera.h"

class CComplexObject3D:public CObject3D
{

public:
	CComplexObject3D();
	~CComplexObject3D();

	virtual void Display ();

	void AddObject (CObject3D *objecto);
	void DeleteLast ();

	virtual void Play (char tecla);

	virtual void Destroy ();

	virtual void Animate (float tempo, float velocidade);

	void Rebuild ();

	//metodo inspector e modificador do scaleSca
	void setScale(float scale);
	float getScale(void);

	void mudarPosicao(float x,float y);

	virtual bool estaVazio()=0;

	virtual int getAltura()=0;

	int getCor();

protected:
	CObject3D *ListaObjectos[100000];
	int num_objectos_simples;
	float scale;
	float posx,posy;
	float posix,posiy;//para guardar as posicoes no tabuleiro
	//Branco->0 Preto->1
	int cor;//para guardar a cor dos objectos nas varias instancias criadas das classes que vao herdar desta(VPeao, VRei,...)
};
