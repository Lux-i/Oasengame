#include <cstdlib>
#include "Enemies.h"
#include <iostream>

Enemy::Enemy() {
	int randX = rand() % 3 + 2; //1 - 4
	int randY = rand() % 3 + 2;
	position.x = randX;
	position.y = randY;
	cooldown = 0;
	currentCooldown = cooldown;
}

void Enemy::action(Player& player) {
	//execute action
	//can always attack if player in range
	if (canAttack(player.getPosition())) {
		attack(player);
	}
	else {
		//moving is a cooldown action
		if (currentCooldown != 0) {
			currentCooldown--;
		}
		else {
			//reset cooldown
			currentCooldown = cooldown;
			handleMovement(player.getPosition());
		}
	}
}

bool Enemy::canAttack(Position pos) {
	int distanceX = abs(position.x - pos.x);
	int distanceY = abs(position.y - pos.y);
	//attacks can only happen horizontally or vertically, even if the enemy can move diagonally
	//this means that the player can only be away 1 field on one axis
	return (distanceX == 1 && distanceY == 0) || (distanceX == 0 && distanceY == 1);
}

void Enemy::attack(Player& player) {
	player.takeDamage(1);
}

Entity::Movement Enemy::bestMove(Position pos) {
	int distanceX = position.x - pos.x;
	int distanceY = position.y - pos.y;
	//moveTowards tries to get closer in the axis with most distance
	if (abs(distanceX) > abs(distanceY)) {
		//further away on x-axis
		if (distanceX > 1) {
			return UP;
		}
		else if (distanceX < -1) {
			return DOWN;
		}
	}
	else {
		//further away on y-axis
		if (distanceY > 1) {
			return LEFT;
		}
		else if (distanceY < -1) {
			return RIGHT;
		}
	}
	return NONE;
}

Kacper::Kacper() {
	cooldown = 2;
	currentCooldown = cooldown;
	symbol = 'x';
}

void Kacper::handleMovement(Position pos) {
	Movement firstMove = bestMove(pos);
	if (firstMove != Movement::NONE) move(firstMove);
	Movement secondMove = bestMove(pos);
	if (secondMove != Movement::NONE && secondMove != firstMove) move(secondMove);
}

Nicolas::Nicolas() {
	cooldown = 1;
	currentCooldown = cooldown;
	symbol = 'v';
}

void Nicolas::handleMovement(Position pos) {
	Movement dir = Movement(rand() % 4);
	int distanceX = position.x - pos.x;
	int distanceY = position.y - pos.y;
	switch (dir) {
	case UP:
		if (distanceX < -1) return;
		break;
	case LEFT:
		if (distanceY < -1) return;
		break;
	case DOWN:
		if (distanceX > 1) return;
		break;
	case RIGHT:
		if (distanceY > 1) return;
		break;
	}
	move(dir);
}