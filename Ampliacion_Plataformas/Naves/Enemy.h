#pragma once

#include "Actor.h"
#include "Animation.h"

class Enemy : public Actor {
public:
	Enemy(float x, float y, Game* game);
	void draw(float scrollx = 0) override;
	void update();

	void impacted(); // Recibe impacto y pone animación de morir
	float vxIntelligence;
	int state;

	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
};

