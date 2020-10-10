#pragma once

//Librerias y utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>

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
	SDL_Texture* getTexture(string filename);

	map<string, SDL_Texture*> mapTextures; // map - cache
	bool scaledToMax = false;
	float scaleLower = 1;

	SDL_Window* window; //Ventana del juego
	SDL_Renderer* renderer; //Renderizador del juego
	bool loopActive; //Juego activo

	Layer* gameLayer;

	int currentLevel = 0;
	int finalLevel = 2;

	int input;
	int const inputKeyboard = 1;
	int const inputMouse = 2;
	int const inputGamePad = 3;

	TTF_Font* font;

	int const stateMoving = 1;
	int const stateJumping = 2;
	int const stateDying = 3;
	int const stateDead = 4;
	int const stateShooting = 5;

	int const orientationRight = 1;
	int const orientationLeft = 2;
};

