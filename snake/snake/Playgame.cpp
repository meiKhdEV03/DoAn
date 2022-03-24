#include "Playgame.h"
#include "Menu.h"
int direction = 2; //Huong di snake nhan vao
int tempDrt = -2; //Huong snake di
// 1: Di len 
// -1: Di xuong
// 2: Di qua trai
// -2: Di qua phai
int score = 0;
int speed = 70;
bool isStart = false;
struct  Snake
{
	int x = 0, y = 0;
	int x0 = 0, y0 = 0;
};
vector <Snake> snake;
struct Food
{
	int x = 0, y = 0;
};
Food food;
int randPoint(int Min, int Max) {
	srand((int)time(NULL));
	int temp = rand() % (Max - Min - 1) + Min + 1;
	return temp;
}
void createSnake()
{
	score = 0;
	snake.resize(6);
	snake[0].x = randPoint(length_CS1 / 2 - 10, length_CS1 / 2 + 10);
	snake[0].y = randPoint(width_CS / 2 - 4, width_CS / 2 + 4);
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].x = snake[0].x - i;
		snake[i].y = snake[0].y;
	}
}
bool isAlive(int x, int y)
{
	for (int i = 1; i < snake.size(); i++)
	{
		if (snake[i].x == x && snake[i].y == y)
			return false;
	}
	return true;
}
void drawSnake()
{
	setColor(12);
	for (int i = 0; i < snake.size(); i++)
	{
		gotoXY(snake[i].x, snake[i].y);
		if (i == 0)
		{
			cout << "0";
			gotoXY(110, 0);
		}
		else
		{
			cout << "o";
			gotoXY(110, 0);
		}
	}

}
bool isOutside(int x, int y)
{
	if (x <= 1 || x >= length_CS1 || y <= 1 || y >= width_CS)
		return true;
	return false;
}
void drawFood()
{
	setColor(12);
	food.x = randPoint(1, length_CS1);
	food.y = randPoint(1, width_CS);
	gotoXY(food.x, food.y);
	cout << "o";
}
bool isEat()
{
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		return true;
	}
	return false;
}

void getMove(bool* isOver)
{
	if (_kbhit())
	{
		char str = _getch();
		if (str == 'W' || str == 'w')
			direction = 1;
		else if (str == 'S' || str == 's')
			direction = -1;
		else if (str == 'A' || str == 'a')
			direction = 2;
		else if (str == 'D' || str == 'd')
			direction = -2;
	}
	if (!isStart && direction != 2)
		isStart = true;
	if (isStart) {
		if (tempDrt != -direction)
			tempDrt = direction;
		switch (tempDrt) {
		case 1: {
			goUp();
			break;
		}
		case -1: {
			goDown();
			break;
		}
		case 2: {
			goLeft();
			break;
		}
		case -2: goRight();
		}
		if (isOutside(snake[0].x, snake[0].y) || !isAlive(snake[0].x, snake[0].y))
		{
			gotoXY(45, 12);
			cout << "You Lose! ";
			*isOver = true;
			isStart = false;
		}
	}
}
void goRight()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].x += 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoXY(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	drawSnake();
	Sleep(speed / Level());
}
void goLeft()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].x -= 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoXY(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	drawSnake();
	Sleep(speed / Level());
}
void goUp()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].y -= 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoXY(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	drawSnake();
	Sleep(speed / Level());
}
void goDown()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].y += 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoXY(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	drawSnake();
	Sleep(speed / Level());
}

void addPoint()
{
	snake.resize(snake.size() + 1);
	snake[snake.size() - 1].x = snake[snake.size() - 2].x0;
	snake[snake.size() - 1].y = snake[snake.size() - 2].y0;
}
void writeScore()
{
	gotoXY(111, 5);
	cout << score;
	score++;
}
