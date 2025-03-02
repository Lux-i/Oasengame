#include <iostream>
#include <cstdlib>
#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"
#include "GameHandler.h"
#include <array>

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
				std::cout << "You decide to end your journey for now and head back to your camp";
				inputValid = true;
			}
			else {
				std::array<Position, 2> enemyPositions;
				int i = 0;
				for (Enemy* enemy : enemies) {
					enemyPositions[i] = enemy->getPosition();
					i++;
				}
				inputValid = player.handleInput(input, enemyPositions);
			}

#pragma endregion
		} while (inputValid == false);

		handleEvents();

		//ends the loop and the game
		if (player.getHealth() == 0) {
			input = EXIT_COMMAND;
			gameLog.addLog("You feel week and decide to head back to camp. You are disappointed you didn't find what you were looking for.");
			renderScreen();
		}

	} while (input != EXIT_COMMAND);
	for (Enemy* enemy : enemies) {
		delete enemy;
	}
}

void GameHandler::renderScreen() {
#ifdef _WIN32
	const char* CLEAR_SCREEN = "cls";
#else
	const char* CLEAR_SCREEN = "clear";
#endif

	std::system(CLEAR_SCREEN);
	board.renderBoard(player, enemies);
	std::cout << "\nHealth: " << player.getHealth() << " | Relics: " << player.relics;
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

//gameLogic
void GameHandler::handleEvents() {
	Field::Type fieldType = board.getTile(player.getPosition()).getType();
	switch (fieldType) {
		//not calling foundTile() outside of cases so already empty fields won't be unnecessary reassigned as empty
	case Field::DANGER:
		if (rand() % 6 + 1 <= std::min(1 + (difficulty / 10), 3)) {
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
		player.relics++;
		gameLog.addLog("You see something glistening in the distance. You walk closer and find a relic lying in the sand.");
		board.foundTile(player.getPosition());
		break;
	}
	if (player.relics == board.getRelicAmount()) advanceWorld();
	for (Enemy* enemy : enemies) {
		enemy->action(player);
	}
}

void GameHandler::advanceWorld() {
	difficulty++;
	player.relics = 0;
	gameLog.resetEntries();
	Position playerPos = player.getPosition();
	board.generateBoard(playerPos.x, playerPos.y, difficulty);
	//copy of relicFound message, as the log of the last relic being found never gets rendered
	gameLog.addLog("You see something glistening in the distance. You walk closer and find a relic lying in the sand. Multiple minutes pass by. You notice a strange glow inside of your bag. You look and see the relics combine together into a single sphere of energy. Suddenly a flash of light blinds you and you find yourself in another location. After a moment of panic you find relieve in seeing the mountain where your camp is located. You decide to continue your Journey");
}