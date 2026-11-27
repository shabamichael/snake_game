#include "snakeGame.h"
#include "utils.h"
#include <string>
using namespace snakeGame;

// Main function / game looping function
int main()
{
	static  std::string playerName;
	std::cout << "\nPlease enter your name:- ";
	std::cin >> playerName;

	std::cout << playerName << ", welcome to Snake Game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Loading... ";
	
	Game game;
	int dfc = game.setDifficuty();

	game.Setup();
	utils::SetCursorVisibility(false);
	while (!game.IsGameOver())
	{
		game.Draw(playerName);	//renderer
		game.Input();			//user input
		game.Logic();			//Game logic

		// creating a delay for according to the chosen
	   // difficulty
		Sleep(dfc);
	}
	utils::SetCursorVisibility(true);
	return 0;

	

}

