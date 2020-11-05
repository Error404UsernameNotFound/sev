#pragma once

#include "Enemy.h"

class EnemySpaceship : public Enemy {
public:
	EnemySpaceship(float x, float y, Game* game);
	void draw(float scrollx = 0) override;
	void update();

	void impacted(); // Recibe impacto y pone animación de morir
	float vxIntelligence;
	int state;

	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
};

