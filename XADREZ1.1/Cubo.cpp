#include "Cubo.h"


CCubo::CCubo(void)
{
}

CCubo::~CCubo(void)
{
}


void CCubo::SetCor (float r1, float g1, float b1)
{
	cor_r = r1;
	cor_g = g1;
	cor_b = b1;
}


void CCubo::Draw()
{
	//cor com iluminacao
	float materialParams[4] = {cor_r, cor_g, cor_b, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams); 

	//sem iluminacao
	//glColor3f(cor_r, cor_g, cor_b);

	glBegin(GL_QUADS);

	glNormal3f(0,0,-1);
	glVertex3f(-0.5f,-0.5f, -0.5f);
	glVertex3f( 0.5f,-0.5f, -0.5f);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glNormal3f(0,0,1);
	glVertex3f(-0.5f,-0.5f, 0.5f);
	glVertex3f( 0.5f,-0.5f, 0.5f);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glNormal3f(0,1,0);
	glVertex3f(-0.5f, 0.5f ,-0.5f);
	glVertex3f( 0.5f, 0.5f ,-0.5f);
	glVertex3f( 0.5f, 0.5f ,0.5f);
	glVertex3f(-0.5f, 0.5f ,0.5f);

	glNormal3f(0,-1,0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);

	glNormal3f(-1,0,0);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);

	glNormal3f(1,0,0);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f,  0.5f, -0.5f);
	glVertex3f(0.5f,  0.5f,  0.5f);
	glVertex3f(0.5f, -0.5f,  0.5f);

	glEnd();
}


void CCubo::Init ()
{
}

void CCubo::Destroy ()
{
}
