#include "Player.h"

Player::Player(float x, float y, Game* game) :
	Actor("res/jugador.png", x, y, 50, 57, game) {
	audioShoot = new Audio("res/efecto_disparo.wav", false);

	lifePoints = 3;

	//TODO revisar 
	//fileWidth = 50;
}

void Player::update() {
	if (shootTime > 0) {
		shootTime--;
	}

	x = x + vx;
	y = y + vy;
}

void Player::moveX(float axis) {
	vx = axis * 3;
}

void Player::moveY(float axis) {
	vy = axis * 3;
}

Projectile* Player::shoot() {
	if (shootTime == 0) {
		audioShoot->play();

		shootTime = shootCadence;
		return new Projectile(x, y, game);
	}
	else {
		return NULL;
	}
}

bool Player::hasLives() {
	return lifePoints > 0;
}

void Player::decrementLife() {
	lifePoints--;
}

int Player::actualLifePoints() {
	return lifePoints;
}
