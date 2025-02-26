#include "Position.h"

#pragma once
class Player
{
public:
	Player();
	Position position;
	void takeDamage(int);
	void heal(int);
	void addRelic();
	int getHealth();
	int getRelics();
private:
	int health;
	int relics;
};

