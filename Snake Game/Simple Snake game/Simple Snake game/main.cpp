#include<iostream>
#include<conio.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x = 0, y = 0, fruitX = 0, fruitY = 0, score;
enum eDirection{ STOP = 0, RIGHT , LEFT , UP , DOWN };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	
	//frist line
	for (int i = 0; i < width; i++)
	{
		 cout << "* ";
	}
	cout << endl;

	//from second to second last line
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "* ";

			if (j == x && i == y)
				cout << "O ";
			else if (j == fruitX && i == fruitY)
				cout << "F ";
			else
				cout << "  ";
		}
		cout << endl;
	}

	//last line
	for (int i = 0; i < width; i++)
	{
		cout << "* ";
	}
	cout << endl;
	cout << "score:- " << score << endl;
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
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'e':
			gameOver = true;
			break;
		}
	}
}

void Logic()
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

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}

	if (x < 0 || x >= width || y < 0 || y >= height)
		gameOver = true;
}
int main()
{
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}