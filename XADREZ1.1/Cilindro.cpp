#include "cilindro.h"


CCilindro::CCilindro(void)
{
	nfaces = 20;
	angle = 360;

	raio1_1 = 0.5;
	raio1_2 = 0.5;

	raio2_2 = 0.5;
	raio2_1 = 0.5;

	topos = 1;

	localTopo_1=0;
	localTopo_2=0;

	localBase_1=0;
	localBase_2=0;
}

CCilindro::CCilindro(int numero_faces, int angulo, float r1, float r2)
{
	nfaces = numero_faces;
	angle = angulo;

	raio1_1 = r1;
	raio1_2 = r1;

	raio2_1 = r2;
	raio2_2 = r2;

	localTopo_1=0;
	localTopo_2=0;

	localBase_1=0;
	localBase_2=0;
}

CCilindro::CCilindro(int numero_faces, int angulo, float r1_1 , float r1_2, float r2_1 , float r2_2)
{
	nfaces = numero_faces;
	angle = angulo;

	raio1_1 = r1_1;
	raio1_2 = r1_2;

	raio2_1 = r2_1;
	raio2_2 = r2_2;

	localTopo_1=0;
	localTopo_2=0;

	localBase_1=0;
	localBase_2=0;
}

CCilindro::~CCilindro(void)
{
}

void CCilindro::SetNFaces (int numero_faces)
{
	nfaces = numero_faces;
}

void CCilindro::SetAngle (int angulo)
{
	angle = angulo;
}

void CCilindro::SetRaio (float r1, float r2)
{
	raio1_1 = r1;
	raio1_2 = r1;
	raio2_1 = r2;
	raio2_2 = r2;
}

int CCilindro::GetNFaces ()
{
	return nfaces;
}

int CCilindro::GetAngle ()
{
	return angle;
}


void CCilindro::Draw ()
{
	if (topos)
	{

		//com iluminacao
		float materialParams[4] = {cor_r1, cor_g1, cor_b1, 1};
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams); 

		//sem iluminacao
		//glColor3f(cor_r2, cor_g2, cor_b2);
			
		// topo
		glBegin(GL_POLYGON);
	
		glNormal3f(0,0,1);
	
		for (float ciclo=0;ciclo<=angle;ciclo=ciclo+(FULLCIRCLE/nfaces))
		{
			float x = raio1_1 * cosf (ciclo);
			float y = raio1_2 * sinf (ciclo);
			glVertex3f (x+localTopo_1,y+localTopo_2,0.5); 
		}
		glEnd();



		// baixo
		glBegin(GL_POLYGON);

		glNormal3f(0,0,-1);

		glColor3f(cor_r1, cor_g1, cor_b1);
		//material(GL_FRONT_AND_BACK , GL_AMBIENT_AND_DIFFUSE, cor_r1, cor_g1, cor_b1, 1);


		for (float ciclo=0;ciclo<=angle;ciclo=ciclo+(FULLCIRCLE/nfaces))
		{
			float x = raio2_1 * cosf (ciclo);
			float y = raio2_2 * sinf (ciclo);
			glVertex3f (x+localBase_1,y+localBase_2,-0.5); 
		}
		glEnd();
	}


	for (float ciclo=0;ciclo<angle;ciclo=ciclo+(2*PI/nfaces))
	{
		glBegin(GL_QUADS);
	
		float x1 = raio2_1 * cosf (ciclo);
		float y1 = raio2_2 * sinf (ciclo);

		float x2 = raio2_1 * cosf (ciclo+(FULLCIRCLE/nfaces));
		float y2 = raio2_2 * sinf (ciclo+(FULLCIRCLE/nfaces));
		
		float x3 = raio1_1 * cosf (ciclo+(FULLCIRCLE/nfaces));
		float y3 = raio1_2 * sinf (ciclo+(FULLCIRCLE/nfaces));

		float x4 = raio1_1 * cosf (ciclo);
		float y4 = raio1_2 * sinf (ciclo);
		
		glNormal3f (cosf (ciclo), sinf (ciclo), (raio2_1 - raio1_1)/2);
		
		glColor3f(cor_r1, cor_g1, cor_b1);
		//material(GL_FRONT_AND_BACK , GL_AMBIENT_AND_DIFFUSE, cor_r1, cor_g1, cor_b1, 1);
		glVertex3f (x1+localBase_1,y1+localBase_2,-0.5); 
		glVertex3f (x2+localBase_1,y2+localBase_2,-0.5); 
		glColor3f(cor_r2, cor_g2, cor_b2);
		//material(GL_FRONT_AND_BACK , GL_AMBIENT_AND_DIFFUSE, cor_r2, cor_g2, cor_b2, 1);
		glVertex3f (x3+localTopo_1,y3+localTopo_2,0.5); 
		glVertex3f (x4+localTopo_1,y4+localTopo_2,0.5);
		glEnd();
	}

}

void CCilindro::SetCor (float r1, float g1, float b1)
{
	cor_r1 = r1;
	cor_g1 = g1;
	cor_b1 = b1;
	cor_r2 = r1;
	cor_g2 = g1;
	cor_b2 = b1;
}

void CCilindro::SetCor (float r1, float g1, float b1, float r2, float g2, float b2)
{
	cor_r1 = r1;
	cor_g1 = g1;
	cor_b1 = b1;
	cor_r2 = r2;
	cor_g2 = g2;
	cor_b2 = b2;
}

void CCilindro::Init ()
{
}

void CCilindro::Destroy ()
{
}

void CCilindro::SetTopo(float i)
{
	topos = i;
}

void CCilindro::SetLocalTopo(float localTopo_1,float localTopo_2){
	this->localTopo_1=localTopo_1;
	this->localTopo_2=localTopo_2;
}

void CCilindro::SetLocalBase(float localBase_1,float localBase_2)
{
	this->localBase_1=localBase_1;
	this->localBase_2=localBase_2;
}