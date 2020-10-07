#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Tile.h"

#include "Pad.h"

#include "Text.h"

#include "Audio.h"
#include "Space.h" 

#include <sstream> //Leer lineas (String)
#include <fstream> //Leer ficheros
#include <list>


class GameLayer : public Layer {
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;

	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event); // USO DE MOUSE
	int newEnemyTime = 0;

	Player* player;
	Background* background;
	Actor* backgroundPoints;

	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;

	list<Enemy*> enemies;
	list<Projectile*> projectiles;

	Audio* audioBackground;

	Text* textPoints;
	int points; //Revisar

	list<Tile*> tiles;
	int mapWidth;
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();
	// Elementos de interfaz
	Pad* pad;
	Actor* buttonJump;
	Actor* buttonShoot;
	Tile* cup; // Elemento de final de nivel
	Space* space;
	float scrollx;
};

