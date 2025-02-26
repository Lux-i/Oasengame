#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Board.h"
#include "Player.h"

constexpr char EXIT_COMMAND = 'x';

#ifdef _WIN32
const char* CLEAR_SCREEN = "cls";
#else
const char* CLEAR_SCREEN = "clear";
#endif

int main()
{
    Board board;
    Player player;
    std::vector<std::string> gameLog;
    std::string inputStr;
    char input;

    //game-loop start
    do
    {
#pragma region renderScreen
        std::system(CLEAR_SCREEN);
        board.renderBoard(player.position);
        std::cout << "\nHealth: " << player.getHealth() << " | Relics: " << player.getRelics();
        std::cout << "\n";

        //show last 10 entries in the log
        int start = std::max(0, (int)gameLog.size() - 10);
        for (int i = start; i < gameLog.size(); ++i) {
            std::cout << gameLog[i] << "\n";
        }
#pragma endregion

        //get input
        std::getline(std::cin, inputStr);
        if (!inputStr.empty()) {
            input = inputStr[0];
            gameLog.push_back("Pressed " + std::string(1, input));
        } else {
            //set input to a char that executes no action in case
            input = 'o';
        }

        //handle Input

    } while (input != EXIT_COMMAND);
}