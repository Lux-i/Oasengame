#include "Player.h"
#include "Position.h"

#pragma once
class Enemy
{
public:
	Enemy();
	Position position;
	void attack(Player);
	void moveTo(Position);
	void moveTo(Player);
};

class Kacper : Enemy {
	//diagonal and straight movement
};

class Nicolas : Enemy {
	//straight only movement
};

