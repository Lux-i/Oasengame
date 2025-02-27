#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"

constexpr char UP = 'w';
constexpr char LEFT = 'a';
constexpr char DOWN = 's';
constexpr char RIGHT = 'd';
constexpr char EXIT_COMMAND = 'x';

#ifdef _WIN32
const char* CLEAR_SCREEN = "cls";
#else
const char* CLEAR_SCREEN = "clear";
#endif

int main() {
	Board board;
	Player player;
	GameLog gameLog;

	std::string inputStr;
	char input;
	bool inputValid;

	//game-loop start
	do {
		//extra do while loop, in case given input is invalid (only rendering and asking for input again)
		do
		{
			inputValid = true;
#pragma region renderScreen
			std::system(CLEAR_SCREEN);
			board.renderBoard(player.position);
			std::cout << "\nHealth: " << player.getHealth() << " | Relics: " << player.getRelics();
			std::cout << "\n\n";
			gameLog.printLog();
#pragma endregion

			//get input
			std::cout << "\nUse wasd to move, x to exit the game\nYour action: ";
			std::getline(std::cin, inputStr);
			if (!inputStr.empty()) {
				input = inputStr[0];
			}
			else {
				//set input to a char that executes no action in case
				input = 'o';
			}

			//handle Input
			switch (input) {
				//movement cases
				//if player tries to make an illegal movement, just don't move
			case UP:
				if (player.position.x != 0) player.position.x--;
				break;
			case LEFT:
				if (player.position.y != 0) player.position.y--;
				break;
			case DOWN:
				if (player.position.x != 4) player.position.x++;
				break;
			case RIGHT:
				if (player.position.y != 4) player.position.y++;
				break;
				//ending case (premature)
			case EXIT_COMMAND:
				std::cout << "Prematurely ended game";
				break;
			default:
				//no case matched earlier => input invalid, receive loop
				inputValid = false;
			}
		} while (inputValid == false);

		//gameLogic
		Field::Type fieldType = board.getTile(player.position).getType();
		switch (fieldType) {
			//not calling foundTile() outside of cases so already empty fields won't be unnecessary reassigned as empty
		case Field::DANGER:
			if (rand() % 6 + 1 <= 1) {
				player.takeDamage(1);
				gameLog.addLog("You enter a dangerous zone. You are clumsy and receive 1HP damage.");
			}
			else {
				gameLog.addLog("You enter a dangerous zone. You sneak around all dangers and move forward with your journey.");
			}
			board.foundTile(player.position);
			break;
		case Field::WELL:
			player.heal(1);
			gameLog.addLog("After a long time of traveling you traverse a sand dune, hidden behind it is a small well. You rest and drink before you go on with your Journey. Healed 1HP.");
			board.foundTile(player.position);
			break;
		case Field::RELIC:
			player.addRelic();
			gameLog.addLog("You see something glistening in the distance. You walk closer and find a relic lying in the sand.");
			board.foundTile(player.position);
			break;
		}


	} while (input != EXIT_COMMAND);
}