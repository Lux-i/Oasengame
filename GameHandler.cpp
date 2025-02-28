#include <iostream>
#include <cstdlib>
#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"
#include "GameHandler.h"

/**
 * handles the main game loop and input
 */
void GameHandler::startGame() {

	constexpr char UP = 'w';
	constexpr char LEFT = 'a';
	constexpr char DOWN = 's';
	constexpr char RIGHT = 'd';
	constexpr char EXIT_COMMAND = 'x';

	char input;
	bool inputValid;

	//game-loop start
	do {
		//extra do while loop, in case given input is invalid (only rendering and asking for input again)
		do
		{
			renderScreen();

			input = getInput();

#pragma region handleInput

			if (input == EXIT_COMMAND) {
				std::cout << "You decide to end your journey and head back to your camp";
				break;
				inputValid = true;
			}
			else {
				inputValid = player.handleInput(input);
			}
#pragma endregion
		} while (inputValid == false);

		//gameLogic
		Field::Type fieldType = board.getTile(player.getPosition()).getType();
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
			board.foundTile(player.getPosition());
			break;
		case Field::WELL:
			player.heal(1);
			gameLog.addLog("After a long time of traveling you traverse a sand dune, hidden behind it is a small well. You rest and drink before you go on with your Journey. Healed 1HP.");
			board.foundTile(player.getPosition());
			break;
		case Field::RELIC:
			player.addRelic();
			gameLog.addLog("You see something glistening in the distance. You walk closer and find a relic lying in the sand.");
			board.foundTile(player.getPosition());
			break;
		}


	} while (input != EXIT_COMMAND);
}

void GameHandler::renderScreen() {
#ifdef _WIN32
	const char* CLEAR_SCREEN = "cls";
#else
	const char* CLEAR_SCREEN = "clear";
#endif

	std::system(CLEAR_SCREEN);
	board.renderBoard(player.getPosition());
	std::cout << "\nHealth: " << player.getHealth() << " | Relics: " << player.getRelics();
	std::cout << "\n\n";
	gameLog.printLog();

}

char GameHandler::getInput() {
	std::string inputStr;
	std::cout << "\nUse wasd to move, x to exit the game\nYour action: ";
	std::getline(std::cin, inputStr);
	if (!inputStr.empty()) {
		return inputStr[0];
	}
	else {
		//set input to a char that executes no action in case
		return 'o';
	}
}