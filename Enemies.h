#include "Player.h"
#include "Position.h"

#pragma once
class Enemy
{
public:
	Enemy();
	void attack(Player);
	void moveTo(Position);
	void moveTo(Player);
};

class Kacper : Enemy {

};

class Nicolas : Enemy {

};

