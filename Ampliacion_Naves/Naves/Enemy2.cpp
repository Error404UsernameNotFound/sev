#include "Enemy2.h"

Enemy2::Enemy2(float x, float y, Game* game)
	: Enemy("res/asteroide.png", x, y, 50, 51, game) {

	vy = 1;
	
	vertical = true;
}

void Enemy2::update() {
	if (vertical) {
		if (vy < 0) {
			vy = 0;
		}

		y = y + vy++;

		if (vy >= 20) {
			vertical = false;
		}
	}

	if (!vertical) {
		if (vy >= 0) {
			vy = -1;
		}

		y = y + vy--;

		if (vy <= -20) {
			vertical = true;
		}
	}

	vx = -1;
	x = x + vx;
}