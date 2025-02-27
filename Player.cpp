#include "Player.h"

Player::Player() {
	position.x = 0;
	position.y = 0;
	health = 5;
	relics = 0;
}

void Player::takeDamage(int amount) {
	health -= amount;
	if (health < 0) health = 0;
}

void Player::heal(int amount) {
	//implement max-health logic?
	health += amount;
}

void Player::addRelic() {
	relics++;
}

int Player::getHealth() {
	return health;
}

int Player::getRelics() {
	return relics;
}