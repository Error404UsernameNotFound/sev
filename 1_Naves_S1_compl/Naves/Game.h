#pragma once

//Librerias y utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//Valores generales
#define WIDTH 480
#define HEIGHT 320

#include "Layer.h"

class Layer; //Para evitar problemas de dependencias ciclicas

class Game {
public:
	Game();
	void loop();

	void scale();
	bool scaledToMax = false;
	float scaleLower = 1;

	SDL_Window* window; //Ventana del juego
	SDL_Renderer* renderer; //Renderizador del juego
	bool loopActive; //Juego activo

	Layer* gameLayer;
};

