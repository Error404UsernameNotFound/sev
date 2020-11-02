#pragma once

#include "Actor.h"
#include "Animation.h"

class Enemy : public Actor{
public:
	Enemy(string filename, float x, float y, int width, int height, Game* game);
	virtual void update();
};

