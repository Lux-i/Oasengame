#include "Player.h"

Player::Player() {
	this->position.x = 0;
	this->position.y = 0;
	this->health = 5;
	this->relics = 0;
}

void Player::takeDamage(int amount) {
	this->health -= amount;
	if (this->health < 0) health = 0;
}

void Player::heal(int amount) {
	//implement max-health logic?
	this->health += amount;
}

void Player::addRelic() {
	this->relics++;
}

int Player::getHealth() {
	return this->health;
}

int Player::getRelics() {
	return this->relics;
}