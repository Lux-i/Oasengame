#include "Position.h"

#pragma once
class Entity
{
public:
	Entity() = default;
	enum Movement {
		UP,
		LEFT,
		DOWN,
		RIGHT,
		NONE
	};
	Position getPosition();
	void move(Movement);
	char getSymbol();
protected:
	Position position;
	char symbol = '*';
};

