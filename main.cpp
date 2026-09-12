#include "snakeGame.h"
#include "utils.h"
using namespace snakeGame;

int main()
{
	Game game;

	game.Setup();
	while (!game.IsGameOver())
	{
		game.Draw();
		game.Input();
		game.Logic();
	}
	return 0;

	

}

