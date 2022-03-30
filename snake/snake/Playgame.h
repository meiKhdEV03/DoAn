#pragma once

struct  Snake
{
	int x = 0, y = 0;
	int x0 = 0, y0 = 0;
};
void createSnake();
void drawSnake();
bool isOutside(int x, int y);
void drawFood();
void getMove(bool* check);
void goLeft();
void goRight();
void goUp();
void goDown();
bool isEat();
void addPoint();
void writeScore();
bool isAlive(int x, int y);
int randPoint(int Min, int Max); // random trong khoang Min Max