#include "Player.h"

Player::Player(float x, float y, Game* game) :
	Actor("res/jugador.png", x, y, 35, 35, game) {
	orientation = game->orientationRight;
	state = game->stateMoving;

	audioShoot = new Audio("res/efecto_disparo.wav", false);

	aShootingRight = new Animation("res/jugador_disparando_derecha.png",
		width, height, 160, 40, 6, 4, false, game);
	aShootingLeft = new Animation("res/jugador_disparando_izquierda.png",
		width, height, 160, 40, 6, 4, false, game);

	aIdleRight = new Animation("res/jugador_idle_derecha.png", width, height,
		320, 40, 6, 8, true, game);
	aIdleLeft = new Animation("res/jugador_idle_izquierda.png", width, height,
		320, 40, 6, 8, true, game);
	aRunningRight = new Animation("res/jugador_corriendo_derecha.png", width, height,
		320, 40, 6, 8, true, game);
	aRunningLeft = new Animation("res/jugador_corriendo_izquierda.png", width, height,
		320, 40, 6, 8, true, game);
	animation = aIdleRight;

	//TODO revisar 
	//fileWidth = 50;
}

void Player::update() {
	bool endAnimation = animation->update();

	// Acabo la animaci�n, no sabemos cual
	if (endAnimation) {
		// Estaba disparando
		if (state == game->stateShooting) {
			state = game->stateMoving;
		}
	}

	// Establecer orientaci�n
	if (vx > 0) {
		orientation = game->orientationRight;
	}
	if (vx < 0) {
		orientation = game->orientationLeft;
	}

	// Selecci�n de animaci�n basada en estados
	if (state == game->stateShooting) {
		if (orientation == game->orientationRight) {
			animation = aShootingRight;
		}
		if (orientation == game->orientationLeft) {
			animation = aShootingLeft;
		}
	}
	if (state == game->stateMoving) {
		if (vx != 0) {
			if (orientation == game->orientationRight) {
				animation = aRunningRight;
			}
			if (orientation == game->orientationLeft) {
				animation = aRunningLeft;
			}
		}
		if (vx == 0) {
			if (orientation == game->orientationRight) {
				animation = aIdleRight;
			}
			if (orientation == game->orientationLeft) {
				animation = aIdleLeft;
			}
		}
	}

	//if (vx > 0) {
	//	animation = aRunningRight;
	//}
	//if (vx < 0) {
	//	animation = aRunningLeft;
	//}
	//if (vx == 0) {
	//	animation = aIdleRight;
	//}

	// Selecci�n de animaci�n
	//if (vx != 0) {
	//	if (orientation == game->orientationRight) {
	//		animation = aRunningRight;
	//	}
	//	if (orientation == game->orientationLeft) {
	//		animation = aRunningLeft;
	//	}
	//}

	//if (vx == 0) {
	//	if (orientation == game->orientationRight) {
	//		animation = aIdleRight;
	//	}
	//	if (orientation == game->orientationLeft) {
	//		animation = aIdleLeft;
	//	}
	//}

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
		state = game->stateShooting;

		audioShoot->play();

		shootTime = shootCadence;
		//return new Projectile(x, y, game);
		aShootingLeft->currentFrame = 0; //"Rebobinar" animaci�n
		aShootingRight->currentFrame = 0; //"Rebobinar" animaci�n
		Projectile* projectile = new Projectile(x, y, game);
		if (orientation == game->orientationLeft) {
			projectile->vx = projectile->vx * -1; // Invertir
		}
		return projectile;
	}
	else {
		return NULL;
	}
}

void Player::draw() {
	animation->draw(x, y);
}

