#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "EnemySpaceship.h"
#include "Enemy2.h"
#include "Projectile.h"
#include "Coin.h"

#include "Text.h"

#include "Audio.h"

#include <list>


class GameLayer : public Layer {
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;

	void keysToControls(SDL_Event event);
	int newEnemyTime = 0;

	Player* player;
	Player* player2; 
	Background* background;
	Actor* backgroundPoints;

	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;

	//Controles para el segundo jugador 
	bool controlShoot2 = false; 
	int controlMoveY2 = 0; 
	int controlMoveX2 = 0; 

	list<Enemy*> enemies;
	list<Projectile*> projectiles;
	list<Coin*> coins;

	Audio* audioBackground;

	Text* textPoints;
	int points; //Revisar

	Text* textLives;
	Text* textLives2;
};

