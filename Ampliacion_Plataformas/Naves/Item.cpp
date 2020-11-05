#include "Item.h"

Item::Item(float x, float y, Game* game)
	: Actor("res/icono_recolectable.png", x, y, 40, 40, game) {
	
	animation = new Animation("res/recolectable.png", width, height,
		256, 32, 6, 8, true, game);
}

void Item::update() {
	animation->update();
}

void Item::draw(float scrollx) {
	animation->draw(x - scrollx, y);
}