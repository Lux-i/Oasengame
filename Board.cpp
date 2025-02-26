#include "Board.h"
#include <iostream>

Board::Board() {
	this->generatedRelics = 0;
	generateBoard();
}

Field Board::getTile(int x, int y) {
	return board[x][y];
}

void Board::generateBoard() {
	srand(time(NULL));
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			//generate Field-type randomly
			Field::Type type = Field::EMPTY;
			int r = rand() % 100 + 1; //1 - 100
			//allocate type
			if (r <= 40) {
				//first 40%
				//field already empty, do nothing
			} else if (r <= 80) {
				//next 40%
				type = Field::DANGER;
			} else if (r <= 90) {
				type = Field::WELL;
			} else {
				type = Field::RELIC;
				this->generatedRelics++;
			}
			this->board[x][y] = type;
		}
	}
	if (this->generatedRelics == 0) {
		//spawn relic if not generated
		this->board[rand() % 5][rand() % 5] = Field::RELIC;
		this->generatedRelics++;
	}
}

void Board::renderBoard(Position playerPosition) {
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			Field field = board[x][y];
			char symbol = '*';
			if (playerPosition.x == x && playerPosition.y == y) {
				symbol = 'o';
			}
			std::cout << symbol << " ";
		}
		std::cout << '\n';
	}
}