#pragma once
#ifndef SNAKEGAME_H
#define SNAKEGAME_H

namespace snakeGame
{
	
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

	class Game
	{
	public:
		static constexpr int WIDTH = 20;
		static constexpr int HEIGHT = 20;


		Game();

		// Add public members and methods here
		void Setup();
		void Draw();
		void Input();
		void Logic();

	
		int getScore() const;
		bool IsGameOver() const;

	
		void setScore(int s);
		void setGameOver(bool gameOver);



	private:
		// Add private members and methods here
	
		int xPosition, yPosition, fruitX, fruitY, score;
		int tailX[100], tailY[100];
		bool gameOver ;
		eDirection dir;


	};
}


#endif // !defined(SNAKEGAME_H)





