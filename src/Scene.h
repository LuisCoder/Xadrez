#pragma once
#include "VTabuleiro.h"
#include "LibGL.h"


#define CAMS 3
#define PI 3.14159265358979

#define DEG2RAD 3.14159/180.0

#define LIGHT_INCREMENT 0.0005


class Scene
{
	public:
		Scene(void);
		~Scene(void);

		void render();
		void update();
		void updateCam();
		void changeCam ();
		void changeCam (int n);
		void rotateCam (float f);
		void automaticCam ();
		void toggleRotate();
		void rotate (float increment);
		void drawAxis();

		void CamUp();
		void CamDown();

		void setLights1();//metodos para acender as três luzes
		void setLights2();
		void setLights3();

		void Lights1();//metodos dos interruptores das luzes
		void Lights2();
		void Lights3();

		void drawText(int w, int h);//layer titulo projecto

		float currentLightAngle;

		VTabuleiro* retornarVTabuleiro();


protected:
	
		VTabuleiro* tabuleiro;
		VPeao* peao;
		VTorre* torre;
		VBispo* bispo;
		VRainha* rainha;
		VRei* rei;
		VCavalo* cavalo;

		int numPeca;//para guardar o numero da peca a apresentar no ecran

		//variaveis da camera
		bool mRotate;
		float mAngle;
		int cam;
		float camAngle;
		bool camRot;
		
		//variavel para subir e baixar a camera
		float camLevel;

		CCubo* lightPosition1;
		CCubo* lightPosition2;
		CCubo* lightPosition3;

		//variaveis para representar os interruptores da luz
		bool luz1;
		bool luz2;
		bool luz3;
};
