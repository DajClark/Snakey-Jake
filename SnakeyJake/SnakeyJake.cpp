// SnakeyJake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>  
#include <list>

bool gameOver;
int width;
int height;
int x, y, martinX, martinY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
std::list<int> tail;

void Setup()
{
	srand(time(NULL));
	gameOver = false;
	width = 50;
	height = 20;
	dir = STOP;
	score = 0;
	x = width / 2;
	y = height / 2;
	martinX = rand() % width - 1;
	martinY = rand() % height - 1;
}

void Draw() 
{
	system("cls");
	std::cout << "--------------------SNAKEY JAKE-------------------" << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
			{
				std::cout << "#";
			}
			else if (j == 0 || j == width - 1)
			{
				std::cout << "#";
			}
			else
			{
				if (j == x && i == y)
				{
					std::cout << "0";
				} 
				else if (j == martinX && i == martinY)
				{
					std::cout << "X";
				}
				else
				{
					std::cout << " ";
				}
			}
			
		}
		std::cout << "" << std::endl;
		
	}
		
	std::cout << "X = Martin ------------------------------ Score: " << score << std::endl;
}

void Input()
{
	if (_kbhit())
	{
		char input;
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		}
	}
}

void Logic()
{
	
	if (dir == UP)
	{
		y--;
	}
	if (dir == LEFT)
	{
		x--;
	}
	if (dir == DOWN)
	{
		y++;
	}
	if (dir == RIGHT)
	{
		x++;
	}

	if (x == martinX && y == martinY)
	{
		srand(time(NULL)); 
		score++;
		martinX = rand() % (width + 2);
		martinY = rand() % (height + 2);
		
		while (martinX >= width - 2 || martinY >= height - 2 || martinX <= 0 || martinY <= 0)
		{
			srand(time(NULL));
			martinX = rand() % (width + 2);
			martinY = rand() % (height + 2);
			printf("a  e  $  t  #  e  t  i  C!\n",martinX, martinY);
		}


	}

	if (x < 1)
	{
		x += width - 1;
	}
	if (x > width - 1)
	{
		x -= width - 1;
	}
	if (y < 1)
	{
		y += height - 1;
	}
	if (y > height - 1)
	{
		y -= height - 1;
	}
}

int main()
{
	int i = 0;
	Setup();
	while (!gameOver)
	{
		i++;
		if (i == 100000000)
		{
			Draw();
			Input();
			Logic();
			i = 0;
			std::cout << "Martin is at: X" << martinX << " Y" << martinY << "\n";
			std::cout << "Jake is at: X" << x << " Y" << y;

		}


	}
    return 0;
}

