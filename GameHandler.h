#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"

#pragma once
class GameHandler
{
public:
	GameHandler() = default;
	void startGame();
private:
	void renderScreen();
	char getInput();
	Board board;
	Player player;
	GameLog gameLog;
};

