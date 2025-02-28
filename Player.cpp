#include "Player.h"

void Player::takeDamage(int amount) {
	health -= amount;
	if (health < 0) health = 0;
}

void Player::heal(int amount) {
	//implement max-health logic?
	health += amount;
}

int Player::getHealth() {
	return health;
}

bool Player::handleInput(char input) {
	constexpr char INPUT_UP = 'w';
	constexpr char INPUT_LEFT = 'a';
	constexpr char INPUT_DOWN = 's';
	constexpr char INPUT_RIGHT = 'd';
	switch (input) {
	case INPUT_UP:
		move(UP);
		return true;
	case INPUT_LEFT:
		move(LEFT);
		return true;
	case INPUT_DOWN:
		move(DOWN);
		return true;
	case INPUT_RIGHT:
		move(RIGHT);
		return true;
	default:
		return false;
	}
}