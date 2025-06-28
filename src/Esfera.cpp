#include "Esfera.h"


Esfera::Esfera(int numero_faces)
{
	nfaces=numero_faces;
}

Esfera::~Esfera(void)
{
}


void Esfera::SetCor (float r1, float g1, float b1)
{
	cor_r = r1;
	cor_g = g1;
	cor_b = b1;
}


void Esfera::Draw()
{
	//cor com iluminacao
	float materialParams[4] = {cor_r, cor_g, cor_b, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams); 

	//sem ilumincao
	//glColor3f(cor_r, cor_g, cor_b);

	glutSolidSphere(1,nfaces,nfaces);
	//glutWireSphere(1,2,2);
}


void Esfera::Init ()
{
}

void Esfera::Destroy ()
{
}
