#include "Object3d.h"


CObject3D::CObject3D(void)
{
	// Coloca a matriz identidade na matriz m do objecto
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity ();
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

CObject3D::~CObject3D(void)
{
}

void CObject3D::Rot (float angulo, float rx, float ry, float rz)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angulo, rx, ry, rz);
	glMultMatrixf(m);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void CObject3D::Trans (float tx, float ty, float tz)
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(tx, ty, tz);
	glMultMatrixf(m);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void CObject3D::Esc (float ex, float ey, float ez)
{
	glPushMatrix();
	glLoadIdentity();
	glScalef(ex, ey, ez);
	glMultMatrixf(m);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}


void CObject3D::ApplyMatrix (float matriz[16])
{
	glPushMatrix();
	glLoadMatrixf(matriz);
	glMultMatrixf(m);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

float CObject3D::GetMatrixX ()
{
	return m[12];
}

float CObject3D::GetMatrixY ()
{
	return m[13];
}

float CObject3D::GetMatrixZ ()
{
	return m[14];
}


void CObject3D::Rot_First (float angulo, float rx, float ry, float rz)
{
	glPushMatrix();
	glLoadMatrixf(m);
	glRotatef(angulo, rx, ry, rz);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();

}

void CObject3D::Trans_First (float tx, float ty, float tz)
{
	glPushMatrix();
	glLoadMatrixf(m);
	glTranslatef(tx, ty, tz);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void CObject3D::Esc_First (float ex, float ey, float ez)
{
	glPushMatrix();
	glLoadMatrixf(m);
	glScalef(ex, ey, ez);
	glGetFloatv(GL_MODELVIEW_MATRIX,m);
	glPopMatrix();
}

void CObject3D::SetVisibility (bool visivel)
{
	visible = visivel;
}

bool CObject3D::GetVisibility ()
{
	return visible;
}

void CObject3D::Play (char tecla)
{
	// Empty play
}

void CObject3D::Animate (float tempo, float velocidade)
{
	// Empty Animation function
}