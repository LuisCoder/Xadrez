#pragma once

#include "SimpleObject3d.h"


class CCubo:public CSimpleObject3D
{
public:
	CCubo(void);
	CCubo(bool comTex);
	~CCubo(void);

	virtual void Draw ();
	virtual void Init ();
	virtual void Destroy ();

	void SetCor (float r, float g, float b);

protected:
	float cor_r;
	float cor_g;
	float cor_b;
	GLuint texture;
	bool comTex;//Se for um cubo com texturas esta variavel vai ser true
};
