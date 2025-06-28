#pragma once

#include "LibGL.h"
#include <stdio.h>
#define PI 3.1415926535
#define FULLCIRCLE 2*PI
#include "math.h"
#include <GL/freeglut.h>


class CObject3D
{
public:
	CObject3D(void);
	~CObject3D(void);

	virtual void Init(void)=0;
	virtual void Destroy()=0;
	virtual void Draw(void)=0;
	virtual void Display(void)=0;

	// anima o objecto (fornece o tempo que passou desde a ultima renderização)
	virtual void Animate (float tempo, float velocidade);

	// operadores de transformação
	void Rot (float angulo, float rx, float ry, float rz);
	void Trans (float tx, float ty, float tz);
	void Esc (float ex, float ey, float ez);

	// operadores de transformação multiplicando em primeiro lugar
	void Rot_First (float angulo, float rx, float ry, float rz);
	void Trans_First (float tx, float ty, float tz);
	void Esc_First (float ex, float ey, float ez);

	// aplicar uma determinada matriz de transformação
	virtual void ApplyMatrix (float matriz[16]);

	// Executar o comando para uma determinada tecla
	virtual void Play (char tecla);

	// Obtenção das coordenadas a partir da matriz de transformação do objecto
	float GetMatrixX ();
	float GetMatrixY ();
	float GetMatrixZ ();

	void SetVisibility (bool visivel);
	bool GetVisibility ();

protected:
	float m[16];	// matriz de transformação
	bool visible;	// visibilidade do objecto
};