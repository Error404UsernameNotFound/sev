#include "EnemySpaceship.h"

EnemySpaceship::EnemySpaceship(float x, float y, Game* game) 
	: Enemy("res/enemigo.png", x, y, 36, 40, game) {
	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, game);
	animation = aMoving;
}

void EnemySpaceship::update() {
	//Actualizacion de la animacion
	animation->update();

	//x = x + vx;

	//if (x - width/2 <= 0 || x + width/2 >= WIDTH) {
	//	vx = vx * -1;
	//}

	vx = -1;
	x = x + vx;
}

void EnemySpaceship::draw() {
	animation->draw(x, y);
}