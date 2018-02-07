// SnakeyJake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>  
#include <list>
#include "Coordinate.h"

bool gameOver;
int width;
int height;
int gameSpeed = 100000000;
int x, y, martinX, martinY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
std::list<Coordinate> tail;

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

void correctXY() {

	srand(time(NULL));
	martinX = rand() % 48 + 1;
	martinY = rand() % 18 + 1;
	//printf("a  e  $  t  #  e  t  i  C!\n", martinX, martinY);
	
	if (martinX >= 49 || martinY >= 19 || martinX <= 0 || martinY <= 0) {
		correctXY;
	}

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
					bool isBody = false;
					for (std::list<Coordinate>::iterator it = tail.begin(); it != tail.end(); ++it) {
						if (j == it->getX() && i == it->getY()) {
							std::cout << "0";
							isBody = true;
						}
					}
					if (isBody == false) {
						std::cout << " ";
					}
					
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
		
		correctXY();
		
		gameSpeed - 1000;
	
	}

	if (x < 1 || x > width - 1 || y < 1 || y > height - 1)
	{
		gameOver = true;
	}
	
	// Tail Coordinates

	Coordinate headPos = Coordinate(x, y);
	tail.push_front(headPos);
	while (tail.size() != score)
	{
		tail.pop_back();
	}

	
	
}

int main()
{
	int i = 0;
	Setup();
	while (!gameOver)
	{
		i++;
		if (i == gameSpeed)
		{
			Draw();
			Input();
			Logic();
			i = 0;
			std::cout << "Martin is at: X" << martinX << " Y" << martinY << "\n";
			std::cout << "Jake is at: X" << x << " Y" << y;

		}


	}
	while (gameOver)
	{ 
		system("cls");
		std::cout << "Game Over";
	}
    return 0;
}

