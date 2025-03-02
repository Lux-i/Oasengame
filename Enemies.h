#include "Player.h"
#include "Position.h"
#include "Entity.h"
#include "GameLog.h"

#pragma once
class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy() = default;
	void action(Player&);
protected:
	bool canAttack(Position);
	void attack(Player&);
	Movement bestMove(Position);
	void virtual handleMovement(Position) = 0;
	int cooldown;
	int currentCooldown;
};

class Kacper : public Enemy {
	//diagonal and straight movement
public:
	Kacper();
protected:
	void handleMovement(Position) override;
};

class Nicolas : public Enemy {
	//straight only movement
public:
	Nicolas();
protected:
	void handleMovement(Position) override;
};

