#pragma once

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
void plusBody();
void writeScore();
bool isAlive(int x, int y);