#include "Entity.h"

Position Entity::getPosition() {
	return position;
}

void Entity::move(Movement move) {
	switch (move) {
	case UP:
		position.x -= 1;
		break;
	case DOWN:
		position.x += 1;
		break;
	case LEFT:
		position.y -= 1;
		break;
	case RIGHT:
		position.y += 1;
		break;
	}
}