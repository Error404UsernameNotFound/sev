#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, int width, int height, Game* game)
	: Actor(filename, x, y, width, height, game) {
	vx = 1;
}

void Enemy::update() {
	vx = -1;
	x = x + vx;
}