#include ".\simpleobject3d.h"


CSimpleObject3D::CSimpleObject3D(void)
{
}

CSimpleObject3D::~CSimpleObject3D(void)
{
}

void CSimpleObject3D::Display ()
{
	glPushMatrix();
	glMultMatrixf(m);
	Draw();
	glPopMatrix();
}

