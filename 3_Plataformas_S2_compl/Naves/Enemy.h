#pragma once

#include "Actor.h"
#include "Animation.h"

class Enemy : public Actor{
public:
	Enemy(float x, float y, Game* game);
	void draw() override;
	void update();

	void impacted(); // Recibe impacto y pone animaci�n de morir
	int state;

	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
};

