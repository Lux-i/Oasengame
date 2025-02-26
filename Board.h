#include "Field.h"
#include "Position.h"

#pragma once
class Board
{
public:
	Board();
	Field getTile(int, int);
	void generateBoard();
	void renderBoard(Position);
	int getRelicAmount();
private:
	Field board[5][5];
	int generatedRelics;
};

