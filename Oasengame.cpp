#include <iostream>
#include <vector>
#include <cstdlib>
#include "Board.h"
#include "Player.h"

int main()
{
    Board board = Board();
    Player player = Player();
    std::vector<std::string> gameLog;
    char input = 'x';

    //game-loop start
    do
    {
        std::system("cls");
        board.renderBoard(player.position);
        std::cout << "\nHealth: " << player.getHealth() << " | Relics: " << player.getRelics();
        std::cout << "\n";
        for (std::string m : gameLog) {
            std::cout << m << "\n";
        }

        std::cin >> input;
        gameLog.push_back("Pressed " + input);

    } while (input != 'x');
}