#include "CuboComText.h"

CuboComText::CuboComText(){
	this->comTex=comTex;
	unsigned char* image;
	BITMAPINFOHEADER header;

	image = (unsigned char*) ::LoadBMP("base.bmp",&(header));
	if(image != NULL)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT,1);
		glGenTextures(1,&texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8,header.biWidth,header.biHeight, 0, GL_RGB,GL_UNSIGNED_BYTE, image);
		FreeBMP(image);
	}
}

CuboComText::~CuboComText(void)
{
}


void CuboComText::SetCor (float r1, float g1, float b1)
{
	cor_r = r1;
	cor_g = g1;
	cor_b = b1;
}


void CuboComText::Draw()
{
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture);

	
	//glBegin(GL_QUADS);

	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture);
	//glBegin(GL_QUADS);
	
	//glVertex3f(-0.5f,-0.5f, -0.5f);
	//glVertex3f( 0.5f,-0.5f, -0.5f);
	//glVertex3f( 0.5f, 0.5f, -0.5f);
	//glVertex3f(-0.5f, 0.5f, -0.5f);
	//glEnd();
	//glDisable(GL_TEXTURE_2D);

	



	

	

	



	////cor com iluminacao
	float materialParams[4] = {cor_r, cor_g, cor_b, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams); 

	////sem iluminacao
	////glColor3f(cor_r, cor_g, cor_b);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);


	glBegin(GL_QUADS);

	
	
	glNormal3f(0,0,-1);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(-0.5f,-0.5f, -0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f( 0.5f,-0.5f, -0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f( 0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glNormal3f(0,0,1);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(-0.5f,-0.5f, 0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f( 0.5f,-0.5f, 0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f( 0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glNormal3f(0,1,0);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(-0.5f, 0.5f ,-0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f( 0.5f, 0.5f ,-0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f( 0.5f, 0.5f ,0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(-0.5f, 0.5f ,0.5f);

	glNormal3f(0,-1,0);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(-0.5f, -0.5f,  0.5f);

	glNormal3f(-1,0,0);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(-0.5f, -0.5f,  0.5f);

	glNormal3f(1,0,0);
	glTexCoord2f(0.0F,0.0F);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0F,1.0F);
	glVertex3f(0.5f,  0.5f, -0.5f);
	glTexCoord2f(1.0F,1.0F);
	glVertex3f(0.5f,  0.5f,  0.5f);
	glTexCoord2f(1.0F,0.0F);
	glVertex3f(0.5f, -0.5f,  0.5f);


	glEnd();

	glDisable(GL_TEXTURE_2D);
}


void CuboComText::Init ()
{
}

void CuboComText::Destroy ()
{
}