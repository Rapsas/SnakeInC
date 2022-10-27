#include <iostream>
#include <conio.h>
#include <windows.h>

class Map 
{
public :
	const int width = 32;
	const int height = 20;
	const char wallSymbol = '#';
	
	void DrawWall()
	{
		std::cout << wallSymbol;
	}
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
	const char headSymbol = 'O';
	const char bodySymbol = 'o';

	void moveBody()
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

	void elongate()
	{
		nBody++;
	}

public:
	Direction dir;
	int x;
	int y;
	int bodyX[100];
	int bodyY[100];
	int nBody;

	Snake()
	{
		x = 15;
		y = 10;
		nBody = 0;
	}

	bool checkForBodyCollision()
	{
		for (int i = 0; i < nBody; i++)
		{
			if (x == bodyX[i] && y == bodyY[i])
			{
				return true;
			}
		}

		return false;
	}

	void Consume()
	{
		//Different food types will have different effects maybe one day in the future
		elongate();
	}

	void move()
	{
		moveBody();

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

	void DrawHead() 
	{
		std::cout << headSymbol;
	}

	void DrawBody()
	{
		std::cout << bodySymbol;
	}
};

class Fruit 
{
private:
	const char fruitSymbol = 'F';

public:
	int x;
	int y;

	Fruit()
	{

	}

	void Draw()
	{
		std::cout << fruitSymbol;
	}
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

	Game()
	{
		fruit.x = (rand() % (map.width - 2)) + 1;
		fruit.y = (rand() % (map.height - 2)) + 1;
	}
};


void Game::Draw() 
{
	system("cls");

	for (int i = 0; i < map.height; i++)
	{
		for (int u = 0; u < map.width; u++)
		{
			bool isTailSquare = false;
			for (int j = 0; j < snake.nBody; j++)
			{
				if (snake.bodyX[j] == u && snake.bodyY[j] == i)
				{
					isTailSquare = true;
					break;
				}
			}

			if (i == 0 || u == 0 || i == map.height - 1 || u == map.width - 1)
			{
				map.DrawWall();
			}
			else if (snake.x == u && snake.y == i)
			{
				snake.DrawHead();
			}
			else if (fruit.x == u && fruit.y == i)
			{
				fruit.Draw();
			}
			else if (isTailSquare)
			{
				snake.DrawBody();
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Fruit coords: " << fruit.x << "; " << fruit.y << std::endl;
	std::cout << "Snake coords: " << snake.x << "; " << snake.y << std::endl;
	std::cout << "Body length: " << snake.nBody << std::endl;
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
	snake.move();

	if (snake.x < 1) {snake.x = map.width - 2;}
	else if (snake.x > map.width - 2) { snake.x = 1; }

	if (snake.y < 1) { snake.y = map.height - 2; }
	else if (snake.y > map.height - 2) { snake.y = 1; }

	gameEnded = snake.checkForBodyCollision();

	// Fruit spawing. NOTE: should check that the fruits coords are not on the snake
	if (snake.x == fruit.x && snake.y == fruit.y)
	{
		snake.Consume();

		fruit.x = (rand() % (map.width - 2)) + 1;
		fruit.y = (rand() % (map.height - 2)) + 1;
	}
}

int main()
{
	Game game;

	while (!game.gameEnded)
	{
		game.Draw();
		game.Input();
		game.Logic();
		Sleep(300);
	}

	std::cout << "Game Over" << std::endl;
}