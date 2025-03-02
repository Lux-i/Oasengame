#include <string>
#include "Board.h"
#include "Player.h"
#include "GameLog.h"
#include "Enemies.h"
#include <array>

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
	std::array<Enemy*, 2> enemies = { new Kacper(), new Nicolas() };
	void handleEvents();
	void advanceWorld();
	int difficulty = 0;
};