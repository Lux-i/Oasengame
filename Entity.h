#include "Position.h"

#pragma once
class Entity
{
public:
	Entity() = default;
	Entity(int x, int y) : position(x, y) {}
	enum Movement {
		UP,
		LEFT,
		DOWN,
		RIGHT
	};
	Position getPosition();
	void move(Movement);
protected:
	Position position;
};

