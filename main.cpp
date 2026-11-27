#include "snakeGame.h"
#include "utils.h"
#include <string>
using namespace snakeGame;


int main()
{
	static  std::string playerName;
	std::cout << "Please enter your name: ";
	std::cin >> playerName;

	std::cout << playerName << " Welcome to Snake Game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Loading... ";

	Game game;

	game.Setup();
	while (!game.IsGameOver())
	{
		game.Draw(playerName);
		game.Input();
		game.Logic();
		Sleep(75);
	}
	return 0;

	

}

