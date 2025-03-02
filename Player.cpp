#include "Player.h"
#include "Enemies.h"
#include <array>

Player::Player() {
	symbol = 'o';
}

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

bool Player::handleInput(char input, std::array<Position, 2> enemies) {
	constexpr char INPUT_UP = 'w';
	constexpr char INPUT_LEFT = 'a';
	constexpr char INPUT_DOWN = 's';
	constexpr char INPUT_RIGHT = 'd';
	bool blocking = false;
	switch (input) {
	case INPUT_UP:
		for (Position enemyPos : enemies) {
			if (position.x == enemyPos.x + 1 && position.y == enemyPos.y) blocking = true;
		}
		if (!blocking) move(UP);
		return true;
	case INPUT_LEFT:
		for (Position enemyPos : enemies) {
			if (position.y == enemyPos.y + 1 && position.x == enemyPos.x) blocking = true;
		}
		if (!blocking) move(LEFT);
		return true;
	case INPUT_DOWN:
		for (Position enemyPos : enemies) {
			if (position.x == enemyPos.x - 1 && position.y == enemyPos.y) blocking = true;
		}
		if (!blocking) move(DOWN);
		return true;
	case INPUT_RIGHT:
		bool blocking = false;
		for (Position enemyPos : enemies) {
			if (position.y == enemyPos.y - 1 && position.x == enemyPos.x) blocking = true;
		}
		if (!blocking) move(RIGHT);
		return true;
	}
	return false;
}