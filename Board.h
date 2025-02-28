#include "Field.h"
#include "Position.h"

#pragma once
class Board
{
public:
	Board();
	Field getTile(int, int);
	Field getTile(Position);
	void generateBoard(int, int);
	void renderBoard(Position);
	int getRelicAmount();
	void foundTile(Position);
private:
	Field board[5][5];
	int generatedRelics;
};

