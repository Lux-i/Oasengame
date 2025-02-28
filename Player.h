#include "Entity.h"

#pragma once
class Player : public Entity
{
public:
	Player() = default;
	void takeDamage(int);
	void heal(int);
	void addRelic();
	int getHealth();
	int getRelics();
	/**
	* Gets the input char of the main loop.
	* If the input corresponds to a movement, it is being executed
	* @return returns if given input was valid for this function or not
	*/
	bool handleInput(char);
private:
	int health = 5;
	int relics = 0;
};

