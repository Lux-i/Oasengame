#include "Board.h"
#include <iostream>

Board::Board() {
	generatedRelics = 0;
	generateBoard(0, 0);
}

Field Board::getTile(int x, int y) {
	return board[x][y];
}

Field Board::getTile(Position position) {
	return board[position.x][position.y];
}

void Board::generateBoard(int posX, int posY) {
	srand(time(nullptr));
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			//generate Field-type randomly
			Field::Type type = Field::EMPTY;
			int r = rand() % 10 + 1; //1 - 10
			//allocate type
			if (r <= 4) {
				//first 40%
				//field already empty, do nothing
			}
			else if (r <= 8) {
				//next 40%
				type = Field::DANGER;
			}
			else if (r <= 9) {
				type = Field::WELL;
			}
			else {
				type = Field::RELIC;
				generatedRelics++;
			}
			board[x][y] = Field(type);
		}
	}
	//remove field type from given position (should be player position)
	if (board[posX][posY].getType() == Field::RELIC) {
		generatedRelics--;
	}
	board[posX][posY] = Field(Field::EMPTY);
	if (generatedRelics == 0) {
		//spawn relic if not generated
		int randX;
		int randY;
		do {
			randX = rand() % 5;
			randY = rand() % 5;
			//random position would be on given position => rerandomzie
		} while (randX == posX && randY == posY);
		board[randX][randY] = Field::RELIC;
		generatedRelics++;
	}
}

void Board::renderBoard(Position position) {
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			char symbol = '*';
			if (position.x == x && position.y == y) {
				symbol = 'o';
			}
			std::cout << symbol << " ";
		}
		std::cout << '\n';
	}
}

int Board::getRelicAmount() {
	return generatedRelics;
}

void Board::foundTile(Position position) {
	board[position.x][position.y].type = Field::EMPTY;
}