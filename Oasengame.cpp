#include <iostream>
#include <cstdlib>
#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"
#include "GameHandler.h"

int main() {
	srand(time(nullptr));
	std::string inputStr;
	do {
		std::cout << "Press Enter to start playing (type h for info): ";
		std::getline(std::cin, inputStr);
		if (inputStr == "h") {
			std::cout << "\n";
			std::cout << "Use wasd to move\n";
			std::cout << "Illegal moves still progress the game, you just do not move\n";
			std::cout << "\n";
			std::cout << "Enemies do not block each other, so watch out\n";
			std::cout << "The enemy 'x' moves 1 field straight and diagonal every 3rd round and follows you\n";
			std::cout << "The enemy 'v' moves 1 field straight every 2nd round randomly\n";
			std::cout << "An enemy will attack you when you are next to it (not diagonally) and deal 1hp";
			std::cout << "\n";
			std::cout << "There are 3 types of special fields: danger, relic and well fields\n";
			std::cout << "Danger fields have a chance of damaging you. If they do, they deal 1hp damage\n";
			std::cout << "Relic fields are needed to progress the game. Collect all relics on the board and get to the next difficulty\n";
			std::cout << "Well fields will heal you by 1hp\n";
			std::cout << "\n";
			std::cout << "As the game grows in difficulty, danger fields will spawn more often and will have a greater chance to damage you\n";
			std::cout << "\n";
		}
	} while (inputStr == "h");
	GameHandler game;
	game.startGame();
}