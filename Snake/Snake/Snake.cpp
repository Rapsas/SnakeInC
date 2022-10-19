#include <iostream>
#include <conio.h>
#include <windows.h>

const int width = 32;
const int height = 20;
const char wallSymbol = '#';

int snakeX, snakeY;
int bodyX[100], bodyY[100];
int nBody = 0;
const char snakeHead = 'O';
const char snakeBody = 'o';

int fruitX, fruitY;
const char fruitSymbol = 'F';

enum Direction 
{
	LEFT, 
	RIGHT, 
	UP, 
	DOWN
};

Direction dir;

bool gameEnded = false;

void Draw() 
{
	system("cls");

	for (int i = 0; i < height; i++)
	{
		for (int u = 0; u < width; u++)
		{
			bool isTailSquare = false;
			for (int j = 0; j < nBody; j++)
			{
				if (bodyX[j] == u && bodyY[j] == i)
				{
					isTailSquare = true;
					break;
				}
			}

			if (i == 0 || u == 0 || i == height - 1 || u == width - 1)
			{
				std::cout << wallSymbol;
			}
			else if (snakeX == u && snakeY == i)
			{
				std::cout << snakeHead;
			}
			else if (fruitX == u && fruitY == i)
			{
				std::cout << fruitSymbol;
			}
			else if (isTailSquare)
			{
				std::cout << snakeBody;
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Fruit coords: " << fruitX << "; " << fruitY << std::endl;
	std::cout << "Snake coords: " << snakeX << "; " << snakeY << std::endl;
	std::cout << "Body length: " << nBody << std::endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		default:
			break;
		}
	}
}

void Logic()
{
	int prevX = snakeX;
	int prevY = snakeY;

	int prev2X;
	int prev2Y;

	for (int i = 0; i < nBody; i++)
	{
		prev2X = bodyX[i];
		prev2Y = bodyY[i];
		bodyX[i] = prevX;
		bodyY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	default:
		break;
	}

	if (snakeX < 1) {snakeX = width - 2;}
	else if (snakeX > width - 2) { snakeX = 1; }

	if (snakeY < 1) { snakeY = height - 2; }
	else if (snakeY > height - 2) { snakeY = 1; }

	for (int i = 0; i < nBody; i++)
	{
		if (snakeX == bodyX[i] && snakeY == bodyY[i])
		{
			gameEnded = true;
			return;
		}
	}

	// Fruit spawing. NOTE: should check that the fruits coords are not on the snake
	if (snakeX == fruitX && snakeY == fruitY)
	{
		fruitX = (rand() % (width - 2)) + 1;
		fruitY = (rand() % (height - 2)) + 1;
		
		bodyX[nBody] = snakeX;
		bodyY[nBody] = snakeY;
		nBody++;
	}
}

int main()
{
	snakeX = 15;
	snakeY = 10;
	fruitX = (rand() % (width - 2)) + 1;
	fruitY = (rand() % (height - 2)) + 1;

	while (!gameEnded)
	{
		Draw();
		Input();
		Logic();
		Sleep(300);
	}

	std::cout << "Game Over" << std::endl;
}