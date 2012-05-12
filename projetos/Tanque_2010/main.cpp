#include <iostream>
#include <string>
#include <sstream>
#include "engcomp_glib.h"

using namespace std;

int main(int argc, char* argv[])
{
	egl_inicializar(800,600,true);
	egl_limite_framerate(30); // limita em 30 frames por segundo (o padr�o � de 60 fps)

	imagem tanque;
	tanque.carregar("tanque.png");

	TileMap mapa;
	mapa.inicializa("mapa.txt");

	float rot = 0;
	float x = 300;
	float y = 300;
	float vel = 0.6;
	float rad;
	const float pi180 = (3.1416/180);

	while(!key[SDLK_ESCAPE])
	{
		mapa.desenha();
		tanque.desenha_rotacionado(x,y,rot);

		// comandos que habilitam o painel de Debug
		// e atualizam os valores
		egl_depurar("X",x);
		egl_depurar("Y",y);
		egl_depurar("Rotacao Tanque",rot);

		if(key[SDLK_LEFT])
		{
			rot+=vel;
		}
		if(key[SDLK_RIGHT])
		{
			rot-=vel;
		}

		if(key[SDLK_UP])
		{
			rad = rot*pi180;
			x += cos(rad) * vel;
			y += -sin(rad) * vel;
		}
		if(key[SDLK_DOWN])
		{
			rad = rot*pi180;
			x -= cos(rad) * vel;
			y -= -sin(rad) * vel;
		}
		
		// linha com espessura (�ltimo parametro indica a espessura)
		egl_linha(10,550,790,550,0,0,0,5);

		// desenha um retangulo com as bordas arredondadas
		egl_retangulo_arredondado(10,560,70,590,0,0,0,200);

		egl_desenha_frame();
	}

	egl_finalizar();

	return 0;
}