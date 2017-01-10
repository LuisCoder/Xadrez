#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#include <time.h>
#include <sys/timeb.h>

#include "Scene.h"
#include "Tabuleiro.h"

// Scene object
Scene* scene;

// dimensões da janela e referencia da propria janela
GLsizei wi,he;				

// modo sólido ou wireframe
int wired = 0;

//modar cor de fundo
int corFundo=0;

//muda a peca
int numPeca=6;

double oldTime=0.0;
bool mexe=false;

// Projecção
void Projectar(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (40.0F, (GLfloat)w/(GLfloat)h, 0.15F, 10000.0F);
	scene->updateCam();
}


// Reformatar o ecrã

void Reformatar(GLsizei w, GLsizei h)
{
    h = (h == 0) ? 1 : h;
    glViewport(0, 0, w, h);
	Projectar(w,h);
	wi=w;
	he=h;
}


// Renderização da cena
void RenderScene (void)
{
	if (wired)
		glPolygonMode (GL_FRONT_AND_BACK,GL_LINE);	// ver wireframe
	else
		glPolygonMode (GL_FRONT_AND_BACK,GL_FILL);	// ver com preenchimento
	

   
	// cor de fundo
	if(corFundo)
		glClearColor (1.0, 1.0, 1.0, 0.0);//cor de fundo branco
	else
		glClearColor (0.2, 0.2, 0.2, 0.2);//cor de fundo preto
    
	// limpa o ecrã
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// modelo de matrizes para o modelo (e não para a perspectiva)
	glMatrixMode(GL_MODELVIEW);				

	// carrega a matriz identidade
	glLoadIdentity();
	
	
	// faz o display do objecto mundo
	scene->render();



	//muda a peca
	//scene->modarPeca(numPeca);



	// troca os buffers
	glutSwapBuffers ();

	// Descarrega a imagem renderizada
	glFlush();	


	//***************
	struct __timeb64 tstruct;
	_ftime64_s(&tstruct);
	double currentTime=tstruct.time+(double)tstruct.millitm/1000;
	if(oldTime==0)
		oldTime=currentTime;
	double elapsedTime=currentTime-oldTime;
	oldTime=currentTime;
	/*if(mexe)
		scene->mexerPeca(elapsedTime);*/
	//printf("FPS(lab9): %f\n",1/elapsedTime);

	//o programa neste ponto vai estar sempre a chamar o tabuleiro para movimentar a peca
	//mas apenas movimenta a peca se a variavel mov estiver a true
	scene->retornarVTabuleiro()->movimentarPeca(elapsedTime);
	
	//animacao teste
	//scene->retornarVTabuleiro()->moverTestePeca(7,8);
	int min=0;
	int max=8;
	printf("%d\n",rand()%(max-min)+min);
}

// força o redraw da imagem
void force_redraw ()
{
	Projectar(wi,he);
	glutPostRedisplay();
}



void keyboardCallback(unsigned char c,int i1,int i2)
{
	
	switch(c)
	{
		
		case 122:
			scene->changeCam(3);
			//numPeca=0;
			break;
		case 120:  
			numPeca=1;
			break;
		case 99:  
			numPeca=2;
			break;
		case 118: 
			numPeca=3;
			break;
		case 98:  
			numPeca=4;
			break;
		case 110:
			numPeca=5;
			break;
		case 109:
			numPeca=6;
			break;

		case 103:
			wired = (wired + 1) % 2;
			//force_redraw ();
			break;
		case 104:
			corFundo = (corFundo + 1) % 2;
			//force_redraw ();
			break;

		case 27:
			exit(0);
			break;

	// Togles auto rotate
		case 114:
			scene->toggleRotate();
			break;
		case 97:
			scene->rotate(-1);
			break;
		case 100:
			scene->rotate(1);
			break;
		case 49:
			scene->changeCam(0);
			break;
		case 50:
			scene->changeCam(1);
			break;
		case 51:
			scene->changeCam(2);
			break;
		case 52:
			scene->changeCam(3);
			break;
		case 53:
			scene->changeCam(4);
			break;
		case 101:
			scene->rotateCam (-0.1);
			break;
		case 113:
			scene->rotateCam (0.1);
			break;
		case 119:
			scene->automaticCam ();
			break;
		case 117:
			scene->CamUp();
			break;
		case 106:
			scene->CamDown();
			break;
		case 48:
			scene->Lights1();
			break;
		case 57:
			scene->Lights2();
			break;
		case 56:
			scene->Lights3();
			break;
		// Enter
		case 13:
			scene->retornarVTabuleiro()->selecionarCasa();
			break;
		// Backspace
		case 8 :
			scene->retornarVTabuleiro()->desseleccionarCasa();
			break;
		//Tecla para jogada aleatória - Tecla K
		case 107 :
			scene->retornarVTabuleiro()->jogarContraComputador();
			break;

	}
}

// Keyboard callback Special
void myKeyboard(int key,int i1,int i2)
{
	
	switch(key)
	{
		case GLUT_KEY_LEFT :
			scene->retornarVTabuleiro()->cursorParaEsquerda();
		break;

		case GLUT_KEY_RIGHT :
		scene->retornarVTabuleiro()->cursorParaDireita();
		break;

		case GLUT_KEY_UP :
			scene->retornarVTabuleiro()->cursorParaCima();
		break;

		case GLUT_KEY_DOWN :
			scene->retornarVTabuleiro()->cursorParaBaixo();
		break;

	}

	/*
	// se foi captado um evento de tecla, não foi instanciado o Idle
	// então é necessário mandar novamente renderizar a cena
	force_redraw ();*/

}




int main(int argc, char** argv)
{
	//iniciar a parte logica do do xadrez
	/*Tabuleiro t;
	t.colocar_pecas();
	t.jogar();*/

	// Explicação na consola
	/*printf ("Cubo em rotacao\n");
	printf ("R -> Rotacao automatica ou manual\n");
	printf ("A -> Rodar o cubo para a esquerda\n");
	printf ("D -> Rodar o cubo para a direita\n");
	printf ("1..3 -> Mudar camara\n");
	printf ("4 -> Camara dinamica\n");
	printf ("Q E-> Rodar camara dinamica\n");
	printf ("W-> Rodar camara dinamica continuamente\n");*/

	// Init glut
	glutInit(&argc, argv);


	// Double Buffered RGB display
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	// Window creation
	//glutInitWindowSize (640, 480);//tamanho da janela original
	glutInitWindowSize(800,600);
    glutCreateWindow ("Xadrez");
    glClearColor (1.0, 1.0, 1.0, 1.0);

	// Enable depth tests
	glEnable(GL_DEPTH_TEST);


	// Creates our scene object (empty for now)
	scene = new Scene();


	// Declare the display, reshape and keyboard functions
	glutDisplayFunc(RenderScene);
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(myKeyboard);
	glutReshapeFunc (Reformatar);
	glutIdleFunc(force_redraw);

	// Start the Main Loop
	glutMainLoop();
	
	// Simply finishes returning 0
	return 0;
}







