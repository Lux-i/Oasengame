#include "Board.h"
#include <iostream>

Board::Board() {
	generatedRelics = 0;
	generateBoard();
}

Field Board::getTile(int x, int y) {
	return board[x][y];
}

Field Board::getTile(Position position) {
	return board[position.x][position.y];
}

void Board::generateBoard() {
	srand(time(NULL));
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			//generate Field-type randomly
			Field::Type type = Field::EMPTY;
			int r = rand() % 10 + 1; //1 - 10
			//allocate type
			if (r <= 4) {
				//first 40%
				//field already empty, do nothing
			} else if (r <= 8) {
				//next 40%
				type = Field::DANGER;
			} else if (r <= 9) {
				type = Field::WELL;
			} else {
				type = Field::RELIC;
				generatedRelics++;
			}
			board[x][y] = type;
		}
	}
	if (generatedRelics == 0) {
		//spawn relic if not generated
		board[rand() % 5][rand() % 5] = Field::RELIC;
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