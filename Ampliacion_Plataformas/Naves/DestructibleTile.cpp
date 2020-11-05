#include "DestructibleTile.h"

DestructibleTile::DestructibleTile(string filename, float x, float y, Game* game)
	: Tile(filename, x, y, game) {

	actualDuration = 0;
	maxDuration = 15;
}

bool DestructibleTile::maxDurationReached() {
	return actualDuration >= maxDuration;
}

//void DestructibleTile::update() {
//
//}

