#pragma once
#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <string>

namespace snakeGame
{
	
	// height and width of the boundary
	static constexpr int WIDTH = 100;
	static constexpr int HEIGHT = 20;

	// for storing snake's moving snakesDirection
	enum class snakeDirection{STOP = 0, LEFT, RIGHT, UP, DOWN };

	class Game
	{
	public:
	    Game();
		void Setup();						//Initializing the Game
		void Draw(std::string playerName);	//Creating Game Board or Game rendering
		void Input();						// Function to handle user UserInput
		void Logic();						// Function for updating the game state
		int setDifficuty();					// Function to set the game difficulty level


		int getScore() const;
		bool IsGameOver() const;

	
		void setScore(int s);
		void setGameOver(bool gameOver);



	private:
	
		// Snake head coordinates of snake (x-axis, y-axis)
		int xPosition, yPosition; 
	
		// Food coordinates
		int fruitX, fruitY; 

		// variable to store the score of he player
		int score;

		// Array to store the coordinates of snake tail (x-axis, y-axis)
		int tailX[100], tailY[100];

		// variable to store the length of the sanke's tail
		int snakeTailLen;

		// boolean variable for checking game is over or not
		bool gameOver ;

		// snakesDirection variable
		snakeDirection dir;

	};
}


#endif // !defined(SNAKEGAME_H)





