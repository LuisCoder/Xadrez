#pragma once

#include "SimpleObject3d.h"


class Esfera:public CSimpleObject3D
{
public:
	Esfera(int numero_faces);
	~Esfera(void);

	virtual void Draw ();
	virtual void Init ();
	virtual void Destroy ();

	void SetCor (float r, float g, float b);

protected:
	float cor_r;
	float cor_g;
	float cor_b;

	int nfaces;// numero de faces
};


