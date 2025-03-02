#include "Field.h"
#include "Position.h"
#include <array>
#include "Player.h"
#include "Enemies.h"

#pragma once
class Board
{
public:
	Board();
	Field getTile(int, int);
	Field getTile(Position);
	void generateBoard(int, int, int);
	void renderBoard(Player, std::array<Enemy*, 2>);
	int getRelicAmount();
	void foundTile(Position);
private:
	Field board[5][5];
	int generatedRelics = 0;
};

