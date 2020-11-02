#pragma once

#include "Enemy.h"

class EnemySpaceship : public Enemy {
public:
	EnemySpaceship(float x, float y, Game* game);

	void draw() override;
	void update() override;

	Animation* aMoving;
	Animation* animation;
};

