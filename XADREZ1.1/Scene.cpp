#include "Scene.h"


Scene::Scene(void)
{
	mRotate = false;
	mAngle = 0;
	cam = 3;//posicao da camara inicialmente
	camAngle = -1.575;
	camRot = false;
	camLevel=14;
	currentLightAngle = 0.0f;
	//incializacao dos interruptores das luzes
	luz1=false;
	luz2=false;
	luz3=false;

	//inicializacao do tabuleiro
	tabuleiro=new VTabuleiro();
	tabuleiro->Init();

	numPeca=0;

	lightPosition1 = new CCubo();
	lightPosition1->Esc(0, 0, 0);
	lightPosition1->Trans(0, 4, 0);

	lightPosition2 = new CCubo();
	lightPosition2->Esc(0, 0, 0);
	lightPosition2->Trans(8, 4, 0);

	lightPosition3 = new CCubo();
	lightPosition3->Esc(0, 0, 0);
	lightPosition3->Trans(4, 8, 0);

	setLights1();
	setLights2();
	setLights3();
}

Scene::~Scene(void)
{
}

void Scene::render()
{
	glEnable (GL_LIGHTING);
	
	/*setLights1();
	setLights2();
	setLights3();*/

	drawAxis();

	lightPosition1->Display();
	lightPosition2->Display();
	lightPosition3->Display();

	tabuleiro->Display();
	drawText(100,10);
}

void Scene::update()
{
	if (mRotate)
		rotate(2.0);
}
	

void Scene::updateCam()
{
	//gluLookAt(0,0,18,0,0,0,0,1,0);//camera original
	if (cam==0)
		gluLookAt(20,7 ,0 ,
				  0 ,7 ,0 ,
				  0 ,1 ,0 );
	else if (cam==1)
		gluLookAt(1,5,5,0,0,0,0,1,0);
	else if (cam==2)
		gluLookAt(12,12,12,0,0,0,0,1,0);
	else if (cam==3)
	{
		gluLookAt(15*sin(camAngle),camLevel,15*cos(camAngle),0,-4,0,0,1,0);
		
		if (camRot)
		{
			camAngle += 0.001;
		}
		
	}
	else if (cam==4)
	{
		gluLookAt(20*sin(camAngle),camLevel,20*cos(camAngle),0,camLevel,0,0,1,0);
		
		if (camRot)
		{
			camAngle += 0.001;
		}
		
	}
	
}

void Scene::changeCam()
{
	cam = (cam+1)%CAMS;
}

void Scene::changeCam(int n)
{
	cam = n;
}

void Scene::rotateCam (float f)
{
	if (camRot) return;

	camAngle += f;


}

void Scene::rotate(float increment)
{
	mAngle+=increment;
}

void Scene::automaticCam()
{
	camRot = !camRot;
}

void Scene::toggleRotate()
{
	mRotate = !mRotate;
}

void Scene::drawAxis()
{
	//com iluminacao
	float materialParams1[4] = {0, 1, 0, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams1); 
	//sem ilumincao
	//glColor3f (0,1,0);

	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(0,5,0);
	glEnd();

	//com iluminacao
	float materialParams2[4] = {1, 0, 0, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams2); 
	//sem iluminacao
	//glColor3f (1,0,0);

	glBegin(GL_LINES);    
	glVertex3f(0,0,0);
	glVertex3f(5,0,0);
	glEnd();

	//com iluminacao
	float materialParams3[4] = {0, 0, 1, 1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialParams3); 
	//sem iluminacao
	//glColor3f (0,0,1);

	glBegin(GL_LINES);    
	glVertex3f(0,0,0);
	glVertex3f(0,0,5);
	glEnd();
}

void Scene::CamUp(){
	camLevel+=0.1;
}

void Scene::CamDown(){
	camLevel-=0.1;
}

void Scene::setLights1()
{
	// Liga a luz 0
	glEnable (GL_LIGHT0);

	// Define cada uma das 3 componentes da luz
	float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	float diffuse[4] = {0.9, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambient);

	float specular[4] = {0.9f, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, ambient);


	// Define a posição da luz

	currentLightAngle += LIGHT_INCREMENT;

	float position[4] = {sin(currentLightAngle) * 5, 4, cos(currentLightAngle) * 5, 1.0};
	glLightfv (GL_LIGHT0, GL_POSITION, position);
	

	// Desenha uma marca no local da luz
		// Repoe na origem
		lightPosition1->Trans(-lightPosition1->GetMatrixX(), 0, -lightPosition1->GetMatrixZ());
		// Efectua uma translação igual à luz
		lightPosition1->Trans(sin(currentLightAngle) * 5, 0, cos(currentLightAngle) * 5);

}

void Scene::setLights2()
{
	// Liga a luz 0
	glEnable (GL_LIGHT1);

	// Define cada uma das 3 componentes da luz
	float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);

	float diffuse[4] = {0.9, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambient);

	float specular[4] = {0.9f, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT1, GL_SPECULAR, ambient);


	// Define a posição da luz

	currentLightAngle += LIGHT_INCREMENT;

	float position[4] = {sin(currentLightAngle) * 5, 4, cos(currentLightAngle) * 5, 1.0};
	glLightfv (GL_LIGHT1, GL_POSITION, position);
	

	// Desenha uma marca no local da luz
		// Repoe na origem
		lightPosition2->Trans(-lightPosition2->GetMatrixX(), 0, -lightPosition2->GetMatrixZ());
		// Efectua uma translação igual à luz
		lightPosition2->Trans(sin(currentLightAngle) * 5, 0, cos(currentLightAngle) * 5);

}

void Scene::setLights3()
{
	// Liga a luz 0
	glEnable (GL_LIGHT2);

	// Define cada uma das 3 componentes da luz
	float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);

	float diffuse[4] = {0.9, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT2, GL_DIFFUSE, ambient);

	float specular[4] = {0.9f, 0.9f, 0.9f, 1.0f};
	glLightfv(GL_LIGHT2, GL_SPECULAR, ambient);


	// Define a posição da luz

	currentLightAngle += LIGHT_INCREMENT;

	float position[4] = {sin(currentLightAngle) * 5, 4, cos(currentLightAngle) * 5, 1.0};
	glLightfv (GL_LIGHT2, GL_POSITION, position);
	

	// Desenha uma marca no local da luz
		// Repoe na origem
		lightPosition3->Trans(-lightPosition3->GetMatrixX(), 0, -lightPosition3->GetMatrixZ());
		// Efectua uma translação igual à luz
		lightPosition3->Trans(sin(currentLightAngle) * 5, 0, cos(currentLightAngle) * 5);

}

void Scene::Lights1(){
	if(luz1){
		glDisable (GL_LIGHT0);
		luz1=false;
	}else{
		setLights1();
		luz1=true;
	}
}

void Scene::Lights2(){
	if(luz2){
		glDisable (GL_LIGHT1);
		luz2=false;
	}else{
		setLights2();
		luz2=true;
	}
}

void Scene::Lights3(){
	if(luz3){
		glDisable (GL_LIGHT2);
		luz3=false;
	}else{
		setLights3();
		luz3=true;
	}
}

VTabuleiro* Scene::retornarVTabuleiro(){
	return tabuleiro;
}

void Scene::drawText(int w, int h)
{
	
	// Texto colocado em posições 3D

	/*glColor3f(0,0,0);

	glRasterPos3f(2, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'x');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'x');

	glRasterPos3f(0,2,0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'y');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'y');

	glRasterPos3f(0,0,2);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'z');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'z');*/



	/* Texto com coordenadas de ecrã
	
	 Projecção
	 Matriz identidade numa projecção ortografica
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, w, 0.0, h);

	 Modelação a partir da matriz identidade
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	 Coordenadas do texto
	glRasterPos2i(100, 10);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'e');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'l');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'l');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'o');

	 Repoe as transformações
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();*/



}

