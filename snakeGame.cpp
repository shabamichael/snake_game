#include "snakeGame.h"
#include <cstdlib>
#include <iostream>
#include "utils.h"
#include <conio.h>

using namespace std;

using namespace snakeGame;

Game::Game()
{
}

void Game::Setup()
{
	utils::Loading();
	gameOver = false;
	eDirection dir = STOP;
	xPosition = WIDTH / 2;
	yPosition = HEIGHT / 2;
	fruitX = utils::randomGenerator(0, WIDTH - 1);
	fruitY = utils::randomGenerator(0, HEIGHT - 1);
	score = 0;
}

void Game::Draw()
{
	utils::ClearScreen();

	for(int i=0; i< WIDTH+2 ; i++)
		std::cout << "#";
	cout<<endl;


	for(int i=0; i<HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == yPosition && j == xPosition)
				cout << "O";

			else if(i==fruitY && j==fruitX)
				cout << "F";

			else
				cout << " ";

			if (j == WIDTH - 1)
				cout << "#" <<endl;	
		}
		cout << endl;

	}

	for (int i = 0; i < WIDTH+2; i++)
		std::cout << "#";

	cout << "\nScore: " << score << endl;

}

void Game::setGameOver(bool over=false)
{
	this->gameOver = over;
}

bool Game::IsGameOver() const
{
	return gameOver;
}

void Game::Input()
{
	if(_kbhit())
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
}

void Game::Logic()
{
	switch (dir)
	{
	case LEFT:
		xPosition--;
		break;
	case RIGHT:
		xPosition++;
		break;
	case UP:
		yPosition--;
		break;
	case DOWN:
		yPosition++;
		break;
	default:
		break;
	}
	if (xPosition == 0 || xPosition == WIDTH - 1 || yPosition == 0 || yPosition == HEIGHT - 1)
			{
		cout << "\nGame Over! Your score is: " << score << endl;
		gameOver = true;
	}

	if (xPosition == fruitX && yPosition == fruitY)
	{
		score += 10;
		fruitX = utils::randomGenerator(0, WIDTH - 1);
		fruitY = utils::randomGenerator(0, HEIGHT - 1);
	}
}
