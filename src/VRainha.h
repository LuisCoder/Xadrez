#pragma once

#include "complexobject3d.h"

class VRainha:public CComplexObject3D
{
public:
	VRainha(int cor);
	~VRainha(void);

		virtual void Init ();
		virtual void Destroy ();
		virtual void Draw ();

		void SetTipo (int t);

		void adicionaCilindroX(float novoRaio,float altura);//ao invocar este metodo acrescenta um novo cilindro com o mesmo raio de fundo igual ao raio de topo do ultimo cilindro colocado. util para criar afunilamentos.
		void adicionaCilindro(float raio1,float raio2,float altura);//ao invocar este metodo acrescenta um novo cilindro podendo introduzir o raio de topo e fundo
		void adicionaCilindro(float raio,float altura);//ao invocar este metodo cria um cilindro com raio em baixo e em cima

		void setRandomColor();//para colocar cores por camadas para efeito de testes

		virtual int getAltura();//para obter a altura da peca para operacoes no tabuleiro

	    //void setScale(float scale);
	    //float getScale(void);

	    //void VRainha::mudarPosicao(float x,float y);

		virtual bool estaVazio();

	private:
		float r,g,b;//variaveis para que guarda as cores do peao quando o mesmo é criado
		float raioAux;//para guardar o raio do topo do ultimo cilindro a ser inserido que depois usado na criação do proximo cilindro
		float posAux;//usado como variavel auxiliar para colocar a altura exacta do proximo objecto
		bool pri;//ao chamar o metodo adicionaCilindro pela primeira vez ele coloca esta variavel a false;
		float alturaTotal;//para guardar a altura total
		float numFaces;//para guardar o numero de lados
		int tipo;
};
