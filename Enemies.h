#include "Player.h"
#include "Position.h"
#include "Entity.h"

#pragma once
class Enemy : public Entity
{
public:
	Enemy();
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

