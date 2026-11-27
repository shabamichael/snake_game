#include "snakeGame.h"
#include <cstdlib>
#include <iostream>
#include "utils.h"
#include <conio.h>
#include <string>

using namespace std;

using namespace snakeGame;

Game::Game()
{
	utils::Loading();
}

//Initializing the game variables
void Game::Setup()
{
	gameOver = false;
	dir = snakeDirection::STOP;
	snakeTailLen = 0;
	//To start the game at  the center of the screen
	xPosition = WIDTH/2;  //position when the game initializes , the mid position of the width
	yPosition = HEIGHT/2; //position when the game initializes , the mid position of the height

	//Use random generator to generate the position of fruits coordinates
	fruitX = utils::randomGenerator(0, WIDTH - 1); //generates a random horizontal position for the fruit
	fruitY = utils::randomGenerator(0, HEIGHT - 1); //generates a random vertical position for the fruit
	score = 0;
}

// Function for creating the game board & rendering
void Game::Draw(std::string playerName)
{
	utils::ClearScreen(); //clear the console
	
	// Creating top walls with '-'
	for(int i=0; i< WIDTH+2 ; i++)
		std::cout << "-";
	cout<<endl;

	for(int i=0; i<HEIGHT; i++){
		for (int j = 0; j <= WIDTH ; j++){
			// Creating side walls with '|'
			if (j == 0 || j==WIDTH )
				cout << "|";
			// Creating snake's head with 'O'
			if (i == yPosition && j == xPosition)
				cout << "O";
			// Creating the snake's food with '#'
			else if(i==fruitY && j==fruitX)
				cout << "#";
			// Creating snake's head with 'O'
			else {
				bool prTail = false;
				for (int k = 0; k < snakeTailLen; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						std::cout << "o";
						prTail = true;
					}
				}
				if (!prTail)
					cout << " ";
			}
			
		}
		cout << endl;

	}
	// Creating bottom walls with '-'
	for (int i = 0; i < WIDTH+2; i++)
		std::cout << "-";
	cout << endl;

	// Display player's score
	cout << playerName << " Score: " << score << endl;
}

void Game::setGameOver(bool over=false)
{
	this->gameOver = over;
}

bool Game::IsGameOver() const
{
	return gameOver;
}

// Function to handle user UserInput
void Game::Input() {
	// Checks if a key is pressed or not
	if (_kbhit())
	{
		switch (_getch()) {
		case 'a':
			dir = snakeDirection::LEFT;
			break;
		case 'd':
			dir = snakeDirection::RIGHT;
			break;
		case 'w':
			dir = snakeDirection::UP;
			break;
		case 's':
			dir = snakeDirection::DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}
	}
}

//Updating the Game State after each move
void Game::Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = xPosition;
	tailY[0] = yPosition;
	
	for (int i = 1; i < snakeTailLen; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case snakeDirection::LEFT:
		xPosition--;
		break;
	case snakeDirection::RIGHT:
		xPosition++;
		break;
	case snakeDirection::UP:
		yPosition--;
		break;
	case snakeDirection::DOWN:
		yPosition++;
		break;
	}
	// Checks for snake's collision with the wall (|)
	if (xPosition == 0 || xPosition >= WIDTH - 1 || yPosition == 0 || yPosition == HEIGHT - 1){
		cout << "\nGame Over! Your score is: " << score << endl;
		gameOver = true;
	}
	// Checks for collision with the tail (o)
	for (int i = 0; i < snakeTailLen; i++) {
		if (tailX[i] == xPosition && tailY[i] == yPosition)
			gameOver = true;
	}
	// Checks for snake's collision with the food (#)
	if (xPosition == fruitX && yPosition == fruitY){
		score += 10;
		fruitX = utils::randomGenerator(0, WIDTH - 1);
		fruitY = utils::randomGenerator(0, HEIGHT - 1);
	}
}

int Game::setDifficuty() {
	int dfc, choice;
	cout << "\n\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: hard "
		"\n\nNOTE: if not chosen or pressed any other "
		"key, the difficulty will be automatically set "
		"to medium\nChoose difficulty level: ";
	cin >> choice;
	switch (choice) {
	case '1':
		dfc = 50;
		break;
	case '2':
		dfc = 100;
		break;
	case '3':
		dfc = 150;
		break;
	default:
		dfc = 100;
	}
	return dfc;
}