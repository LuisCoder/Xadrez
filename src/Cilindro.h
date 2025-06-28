#pragma once
#include "simpleobject3d.h"




class CCilindro :public CSimpleObject3D
{
public:
	CCilindro(void);
	CCilindro(int numero_faces, int angulo, float r1, float r2);
	CCilindro(int numero_faces, int angulo, float r1_1 , float r1_2, float r2_1 , float r2_2);
	~CCilindro(void);

	virtual void Draw ();
	virtual void Init ();
	virtual void Destroy ();

	void SetNFaces (int numero_faces);
	void SetAngle (int angulo);
	void SetRaio (float r1, float r2);
	void SetCor (float r1, float g1, float b1);
	void SetCor (float r1, float g1, float b1, float r2, float g2, float b2);
	void SetTopo (float i);

	void SetLocalTopo(float localTopo_1,float localTopo_2);
	void SetLocalBase(float localBase_1,float localBase_2);

	int GetNFaces ();
	int GetAngle ();


protected:
	int nfaces;								// numero de faces (definição)
	int angle;								// angulo de revolução (360 é um cilindro completo, p.e.)

	int topos;								// 1 para desenhar o topo
	
	float raio1_1;							// raio do topo
	float raio1_2;
	float raio2_1;							// raio da base
	float raio2_2;

	float cor_r1, cor_g1, cor_b1;
	float cor_r2, cor_g2, cor_b2;

	//os valores do topo e da base sao colocados a zero por default podendo despois ser alterados atraves dos metodos
	//SetLocalTopo e SetLocalBase
	float localTopo_1,localTopo_2;//para colocar a localizacao do topo do cilindro
	float localBase_1,localBase_2;//para colocar a localizacao da base do cilindro
};
