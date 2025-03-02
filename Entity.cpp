#include "Entity.h"

Position Entity::getPosition() {
	return position;
}

void Entity::move(Movement move) {
	switch (move) {
	case UP:
		if (position.x != 0) position.x -= 1;
		break;
	case DOWN:
		if (position.x != 4) position.x += 1;
		break;
	case LEFT:
		if (position.y != 0) position.y -= 1;
		break;
	case RIGHT:
		if (position.y != 4) position.y += 1;
		break;
	}
}

char Entity::getSymbol() {
	return symbol;
}