#pragma once

#include "Enemy.h"

class Enemy2 : public Enemy {
public:
	Enemy2(float x, float y, Game* game);

	void update() override;

	bool vertical;
};

