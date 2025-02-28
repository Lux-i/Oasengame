#include "Entity.h"

#pragma once
class Player : public Entity
{
public:
	Player() = default;
	void takeDamage(int);
	void heal(int);
	int getHealth();
	/**
	* Gets the input char of the main loop.
	* If the input corresponds to a movement, it is being executed
	* @return returns if given input was valid for this function or not
	*/
	bool handleInput(char);
	int relics = 0;
private:
	int health = 5;
};

