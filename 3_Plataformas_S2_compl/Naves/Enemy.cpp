#include "Enemy.h"

Enemy::Enemy(float x, float y, Game* game) 
	: Actor("res/enemigo.png", x, y, 36, 40, game) {
	vx = 1; //wa

	state = game->stateMoving;

	aDying = new Animation("res/enemigo_morir.png", width, height,
		280, 40, 6, 8, false, game);

	aMoving = new Animation("res/enemigo_movimiento.png", width, height, 
		108, 40, 6, 3, true, game);
	animation = aMoving;
}

void Enemy::update() {
	// Actualizar la animación
	bool endAnimation = animation->update();

	// Acabo la animación, no sabemos cual
	if (endAnimation) {
		// Estaba muriendo
		if (state == game->stateDying) {
			state = game->stateDead;
		}
	}

	if (state == game->stateMoving) {
		animation = aMoving;
	}
	if (state == game->stateDying) {
		animation = aDying;
	}

	//x = x + vx;

	//if (x - width/2 <= 0 || x + width/2 >= WIDTH) {
	//	vx = vx * -1;
	//}

	if (state != game->stateDying) {
		vx = -1;
		x = x + vx;
	}
}

void Enemy::draw() {
	animation->draw(x, y);
}

void Enemy::impacted() {
	if (state != game->stateDying) {
		state = game->stateDying;
	}
}
