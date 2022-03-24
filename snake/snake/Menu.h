#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

#define length_CS1 90   // Phan game
#define length_CS2  26   // Phan huong dan
#define width_CS 28
#define width_Box 3
#define length_Box 22
using namespace std;
struct Box
{
	int x, y, length, width;     //x y la toa do goc tren ben trai cua box
};
void outFile();
void readFile();
void drawBoard(int speed);
void Nocursortype();
void FixConsoleWindow();
void setColor(int color);
void gotoXY(int x, int y);
void setBox();
void drawBox(int x, int y, int length, int width);
void writeText(int x, int y, int length, string txt);
void mainMenu();
void levelMenu();
void drawMenu(int bg, int ed, int cdt);
int Level();