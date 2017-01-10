#pragma once

//#include "StdAfx.h"
#include "Object3d.h"

class CSimpleObject3D :
	public CObject3D
{
public:
	CSimpleObject3D(void);
	~CSimpleObject3D(void);

	virtual void Display ();

};
