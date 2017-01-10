#pragma once

#include "complexobject3d.h"

class VVazio:public CComplexObject3D
{
public:
	VVazio(void);
	~VVazio(void);
	virtual void Init ();
	virtual void Destroy ();
	virtual void Draw ();
	virtual bool estaVazio();
	virtual int getAltura();
};

