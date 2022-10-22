#include <iostream>
#include <conio.h>
#include <windows.h>

class Map 
{
public :
	const int width = 32;
	const int height = 20;
	const char wallSymbol = '#';
	// Later would like to make it that the map class itself is responsible for its border logic. Likw whether to wrap around the map or kill the snake
	/*void borderLogic() 
	{

	}*/
};

enum Direction 
{
	LEFT, 
	RIGHT, 
	UP, 
	DOWN
};

class Snake 
{
private:
	int bodyX[100], bodyY[100];
	int nBody = 0;
	const char headSymbol = 'O';
	const char bodySymbol = 'o';

public:
	Direction dir;
	int x, y;
	void expandBody() 
	{
		int prevX = x;
		int prevY = y;

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
	}

	bool checkForBodyCollision()
	{
		for (int i = 0; i < nBody; i++)
		{
			return x == bodyX[i] && y == bodyY[i];
		}
	}

	void elongate()
	{
		nBody++;
	}

	void move()
	{
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}
	}
};

class Fruit 
{
public:
	int x, y;

private:
	const char fruitSymbol = 'F';
};

class Game
{
public:
	bool gameEnded = false;
	Snake snake;
	Fruit fruit;
	Map map;
	void Logic();
	void Draw();
	void Input();

private:

};


void Game::Draw() 
{
	system("cls");

	for (int i = 0; i < map.height; i++)
	{
		for (int u = 0; u < map.width; u++)
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

void Game::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			snake.dir = LEFT;
			break;
		case 's':
			snake.dir = DOWN;
			break;
		case 'd':
			snake.dir = RIGHT;
			break;
		case 'w':
			snake.dir = UP;
			break;
		default:
			break;
		}
	}
}

void Game::Logic()
{
	snake.expandBody();
	snake.move();

	if (snake.x < 1) {snake.x = map.width - 2;}
	else if (snake.x > map.width - 2) { snake.x = 1; }

	if (snake.y < 1) { snake.y = map.height - 2; }
	else if (snake.y > map.height - 2) { snake.y = 1; }

	gameEnded = snake.checkForBodyCollision();

	// Fruit spawing. NOTE: should check that the fruits coords are not on the snake
	if (snake.x == fruit.x && snake.y == fruit.y)
	{
		fruit.x = (rand() % (map.width - 2)) + 1;
		fruit.y = (rand() % (map.height - 2)) + 1;
		
		/*bodyX[nBody] = snakeX;
		bodyY[nBody] = snakeY;*/
		snake.elongate();
	}
}

int main()
{
	Game game;
	game.snake.x = 15;
	game.snake.y = 10;
	game.fruit.x = (rand() % (game.map.width - 2)) + 1;
	game.fruit.y = (rand() % (game.map.height - 2)) + 1;

	while (!game.gameEnded)
	{
		game.Draw();
		game.Input();
		game.Logic();
		Sleep(300);
	}

	std::cout << "Game Over" << std::endl;
}