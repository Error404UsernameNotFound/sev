#include "GameLayer.h"

GameLayer::GameLayer(Game* game) : Layer(game) {
	init();
}

void GameLayer::init() {
	audioBackground = new Audio("res/musica_ambiente.mp3", true);
	audioBackground->play();


	points = 0;
	textPoints = new Text("0", WIDTH * 0.92, HEIGHT * 0.04, game);
	textPoints->content = to_string(points);

	textLives = new Text("Vidas jugador 1: 3", WIDTH * 0.62, HEIGHT * 0.04, game);
	textLives2 = new Text("Vidas jugador 2: 3", WIDTH * 0.62, HEIGHT * 0.10, game);

	player = new Player(50, 50, game);
	player2 = new Player(100, 100, game); 
	background = new Background("res/fondo.png", WIDTH * 0.5, HEIGHT * 0.5, -1, game);
	backgroundPoints = new Actor("res/icono_puntos.png", 
		WIDTH * 0.85, HEIGHT * 0.05, 24, 24, game);

	projectiles.clear(); //Para el reinicio del juego

	enemies.clear(); //Para el reinicio del juego
	/*enemies.push_back(new Enemy(300, 50, game));
	enemies.push_back(new Enemy(300, 200, game));*/
	//Cambio

	coins.clear();
	bombs.clear();
}

void GameLayer::processControls() {
	// obtener controles
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControls(event);
	}

	//procesar controles
	// Disparar
	if (controlShoot) {
		Projectile* newProjectile = player->shoot();
		if (newProjectile != NULL) {
			projectiles.push_back(newProjectile);
		}

	}

	if (controlShoot2) {
		Projectile* newProjectile = player2->shoot();
		if (newProjectile != NULL) {
			projectiles.push_back(newProjectile);
		}

	}

	// Eje X
	if (controlMoveX > 0) {
		player->moveX(1);
	}
	else if (controlMoveX < 0) {
		player->moveX(-1);
	}
	else {
		player->moveX(0);
	}

	if (controlMoveX2 > 0) {
		player2->moveX(1);
	}
	else if (controlMoveX2 < 0) {
		player2->moveX(-1);
	}
	else {
		player2->moveX(0);
	}

	// Eje Y
	if (controlMoveY > 0) {
		player->moveY(1);
	}
	else if (controlMoveY < 0) {
		player->moveY(-1);
	}
	else {
		player->moveY(0);
	}

	if (controlMoveY2 > 0) {
		player2->moveY(1);
	}
	else if (controlMoveY2 < 0) {
		player2->moveY(-1);
	}
	else {
		player2->moveY(0);
	}
}


void GameLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada

		switch (code) {
		case SDLK_ESCAPE:
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_d: // derecha
			controlMoveX = 1;
			break;
		case SDLK_a: // izquierda
			controlMoveX = -1;
			break;
		case SDLK_w: // arriba
			controlMoveY = -1;
			break;
		case SDLK_s: // abajo
			controlMoveY = 1;
			break;
		case SDLK_SPACE: // dispara
			controlShoot = true;
			break;
		case SDLK_RIGHT: // derecha
			controlMoveX2 = 1;
			break;
		case SDLK_LEFT: // izquierda
			controlMoveX2 = -1;
			break;
		case SDLK_UP: // arriba
			controlMoveY2 = -1;
			break;
		case SDLK_DOWN: // abajo
			controlMoveY2 = 1;
			break;
		case SDLK_RETURN: // dispara
			controlShoot2 = true;
			break;
		}
	}

	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		// Levantada

		switch (code) {
		case SDLK_d: // derecha
			if (controlMoveX == 1) {
				controlMoveX = 0;
			}
			break;
		case SDLK_a: // izquierda
			if (controlMoveX == -1) {
				controlMoveX = 0;
			}
			break;
		case SDLK_w: // arriba
			if (controlMoveY == -1) {
				controlMoveY = 0;
			}
			break;
		case SDLK_s: // abajo
			if (controlMoveY == 1) {
				controlMoveY = 0;
			}
			break;
		case SDLK_SPACE: // dispara
			controlShoot = false;
			break;
		case SDLK_RIGHT: // derecha
			if (controlMoveX2 == 1) {
				controlMoveX2 = 0;
			}
			break;
		case SDLK_LEFT: // izquierda
			if (controlMoveX2 == -1) {
				controlMoveX2 = 0;
			}
			break;
		case SDLK_UP: // arriba
			if (controlMoveY2 == -1) {
				controlMoveY2= 0;
			}
			break;
		case SDLK_DOWN: // abajo
			if (controlMoveY2 == 1) {
				controlMoveY2 = 0;
			}
			break;
		case SDLK_RETURN: // dispara
			controlShoot2 = false;
			break;
		}
	}
}

void GameLayer::update() {
	background->update();

	list<Enemy*> deleteEnemies;
	list<Projectile*> deleteProjectiles;
	list<Coin*> deleteCoins;
	list<Bomb*> deleteBombs;

	// Generar enemigos
	newEnemyTime--;
	if (newEnemyTime <= 0) {
		int rX = (rand() % (600 - 500)) + 1 + 500;
		int rY = (rand() % (300 - 60)) + 1 + 60;

		int rXCoin = (rand() % 500) + 1;
		int rYCoin = (rand() % 400) + 1;

		int rXBomb = (rand() % 500) + 1;
		int rYBomb = (rand() % 400) + 1;
		//enemies.push_back(new Enemy(rX, rY, game));
		switch (rand() % 2) {
		case 0:
			enemies.push_back(new EnemySpaceship(rX, rY, game));
			break;
		case 1:
			enemies.push_back(new Enemy2(rX, rY, game));
			break;
		}

		//Generacion de monedas
		coins.push_back(new Coin(rXCoin, rYCoin, game));

		//Generacion de bombas
		bombs.push_back(new Bomb(rXBomb, rYBomb, game));

		newEnemyTime = 110;
	}

	background->update();
	player->update();
	player2->update();

	for (auto const& enemy : enemies) {
		enemy->update();
	}

	for (auto const& projectile : projectiles) {
		projectile->update();
	}

	//Colisiones
	for (auto const& enemy : enemies) {
		if (player->isOverlap(enemy)) {
			if (player->hasLives()) {
				player->decrementLife();
				textLives->content = "Vidas jugador 1: " + to_string(player->actualLifePoints());

				bool eInList = std::find(deleteEnemies.begin(),
					deleteEnemies.end(),
					enemy) != deleteEnemies.end();

				if (!eInList) {
					deleteEnemies.push_back(enemy);
				}
			}
			else {
				init();
				return;
			}
		}
	}

	for (auto const& coin : coins) {
		if (player->isOverlap(coin)) {
			deleteCoins.push_back(coin);

			points++;
			textPoints->content = to_string(points);
		}
	}

	for (auto const& bomb : bombs) {
		if (player->isOverlap(bomb)) {
			deleteBombs.push_back(bomb);

			for (auto const& enemy : enemies) {
				deleteEnemies.push_back(enemy);
			}
		}
	}

	//Player2
	for (auto const& enemy : enemies) {
		if (player2->isOverlap(enemy)) {
			if (player2->hasLives()) {
				player2->decrementLife();
				textLives2->content = "Vidas jugador 2: " + to_string(player2->actualLifePoints());

				bool eInList = std::find(deleteEnemies.begin(),
					deleteEnemies.end(),
					enemy) != deleteEnemies.end();

				if (!eInList) {
					deleteEnemies.push_back(enemy);
				}
			}
			else {
				init();
				return;
			}
		}
	}

	for (auto const& coin : coins) {
		if (player2->isOverlap(coin)) {
			deleteCoins.push_back(coin);

			points++;
			textPoints->content = to_string(points);
		}
	}

	for (auto const& bomb : bombs) {
		if (player2->isOverlap(bomb)) {
			deleteBombs.push_back(bomb);

			for (auto const& enemy : enemies) {
				deleteEnemies.push_back(enemy);
			}
		}
	}

	// Colisiones , Enemy - Projectile
	for (auto const& projectile : projectiles) {
		if (!projectile->isInRender()) {
			bool pInList = find(deleteProjectiles.begin(),
				deleteProjectiles.end(), projectile) != deleteProjectiles.end();

			if (!pInList) {
				deleteProjectiles.push_back(projectile);
			}
		}
	}

	for (auto const& enemy : enemies) {
		for (auto const& projectile : projectiles) {
			if (enemy->isOverlap(projectile)) {
				bool pInList = std::find(deleteProjectiles.begin(),
					deleteProjectiles.end(),
					projectile) != deleteProjectiles.end();

				if (!pInList) {
					deleteProjectiles.push_back(projectile);
				}

				bool eInList = std::find(deleteEnemies.begin(),
					deleteEnemies.end(),
					enemy) != deleteEnemies.end();

				if (!eInList) {
					deleteEnemies.push_back(enemy);
				}

				points++;
				textPoints->content = to_string(points);
			}
		}
	}

	for (auto const& delEnemy : deleteEnemies) {
		enemies.remove(delEnemy);
	}
	deleteEnemies.clear();

	for (auto const& delProjectile : deleteProjectiles) {
		projectiles.remove(delProjectile);
		delete delProjectile;
	}

	deleteProjectiles.clear();

	for (auto const& delCoin : deleteCoins) {
		coins.remove(delCoin);
	}
	deleteCoins.clear();

	for (auto const& delBomb : deleteBombs) {
		bombs.remove(delBomb);
	}
	deleteCoins.clear();

	std::cout << "update gameLayer" << std::endl;
}

void GameLayer::draw() {
	background->draw();

	for (auto const& projectile : projectiles) {
		projectile->draw();
	}

	player->draw();
	player2->draw();

	for (auto const& enemy : enemies) {
		enemy->draw();
	}

	for (auto const& coin : coins) {
		coin->draw();
	}

	for (auto const& bomb : bombs) {
		bomb->draw();
	}

	backgroundPoints->draw();
	textPoints->draw();
	textLives->draw();
	textLives2->draw();

	SDL_RenderPresent(game->renderer); //Renderiza
}
