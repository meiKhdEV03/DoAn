#include "Menu.h"

string str[10];
Box box[10];
int Lv = 1;
bool isPlay = false;
vector<string> lines;
vector<int> diem;
bool inMainMenu = true, inLevelMenu = false, inHighscore = false, inIntroduction = false;
int idMainMenu = 0, idLevelMenu = 4;    //id cac hang
void drawBoard(int speed) // thoi gian Sleep
{
	setColor(34);
	for (int i = length_CS1; i > 0; i--)
	{
		gotoXY(i, 1);
		printf("%c", 196);
		Sleep(speed);
	}
	for (int i = 2; i <= width_CS; i++)
	{
		gotoXY(1, i);
		printf("%c", 179);
		Sleep(speed);
	}
	for (int i = 2; i <= length_CS1; i++)
	{
		gotoXY(i, width_CS);
		printf("%c", 196);
		Sleep(speed);
	}
	for (int i = width_CS; i >= 2; i--)
	{
		gotoXY(length_CS1, i);
		printf("%c", 179);
		Sleep(speed);
	}

	for (int i = length_CS1 + 2; i <= length_CS1 + length_CS2 + 2; i++)
	{
		gotoXY(i, 1);
		printf("%c", 196);
		Sleep(speed);
	}
	for (int i = 2; i <= width_CS; i++)
	{
		gotoXY(length_CS1 + length_CS2 + 2, i);
		printf("%c", 179);
		Sleep(speed);
	}
	for (int i = length_CS1 + length_CS2 + 1; i >= length_CS1 + 2; i--)
	{
		gotoXY(i, width_CS);
		printf("%c", 196);
		Sleep(speed);
	}
	for (int i = width_CS - 1; i >= 2; i--)
	{
		gotoXY(length_CS1 + 2, i);
		printf("%c", 179);
		Sleep(speed);
	}
	setColor(33);
	for (int i = width_CS; i >= 1; i--)
	{
		gotoXY(length_CS1 + 1, i);
		printf("%c", 179);
		Sleep(speed);
	}
}
void readFile()
{
	fstream fp;
	fp.open("highscore.txt", ios::in);
	string line;
	int i = 1;
	int D;
	while (!fp.eof())
	{
		getline(fp, line);
		if (i % 2 == 0) {
			D = stoi(line);
			diem.push_back(D);
		}
		else
			lines.push_back(line);
		i++;
	}
	fp.close();
}
void outFile()
{
	for (int i = 0; i < 5; i++)
		cout << lines[i] << "  " << diem[i] << endl;
}
void setStringBox()
{
	str[0] = "START";
	str[1] = "LEVEL";
	str[2] = "HIGHSCORE";
	str[3] = "INTRODUCTION";
	str[4] = "EAZY";
	str[5] = "MEDIUM";
	str[6] = "HARD";
}
void setBox()
{
	box[0] = { (length_CS1 - length_Box) / 2,6,length_Box,width_Box };
	box[1] = { (length_CS1 - length_Box) / 2,9,length_Box,width_Box };
	box[2] = { (length_CS1 - length_Box) / 2,12,length_Box,width_Box };
	box[3] = { (length_CS1 - length_Box) / 2,15,length_Box,width_Box };
	box[4] = { (length_CS1 - length_Box) / 2 + 3,12,length_Box - 6,width_Box };
	box[5] = { (length_CS1 - length_Box) / 2 + 3,15,length_Box - 6,width_Box };
	box[6] = { (length_CS1 - length_Box) / 2 + 3,18,length_Box - 6,width_Box };
}
void drawBox(int x, int y, int length, int width)
{
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + length - 1, y);
	cout << char(191);
	gotoXY(x, y + width - 1);
	cout << char(192);
	gotoXY(x + length - 1, y + width - 1);
	cout << char(217);
	for (int i = 1; i < length - 1; i++)
	{
		gotoXY(x + i, y);
		cout << char(196);
		gotoXY(x + i, y + width - 1);
		cout << char(196);
	}
	gotoXY(x + length - 1, y);
	cout << char(191);

	for (int i = 1; i < width - 1; i++)
	{
		gotoXY(x, y + i);
		cout << char(179);
		gotoXY(x + length - 1, y + i);
		cout << char(179);
	}
}  // Ve box
void drawMenu(int bg, int ed, int cdt) // Ve tu` o bg den' o ed nhung to dam. o cdt
{
	for (int i = bg; i < ed; i++) {
		setColor(12);
		drawBox(box[i].x, box[i].y, box[i].length, box[i].width);
		if (i == cdt)
			setColor(140);
		writeText(box[i].x, box[i].y, box[i].length, str[i]);
	}
	setColor(12);
}
void mainMenu()
{
	lines.resize(0);
	diem.resize(0);
	readFile();
	setBox();
	setStringBox();
	drawMenu(0, 4, idMainMenu);
	while (!isPlay) {
		if (_kbhit())
		{
			char c = _getch();
			if (inMainMenu) {
				if (c == 'w' || c == 'W') {
					if (idMainMenu != 0) {
						idMainMenu--;
						drawMenu(0, 4, idMainMenu);
					}
				}
				else if (c == 's' || c == 'S') {
					if (idMainMenu != 3) {
						idMainMenu++;
						drawMenu(0, 4, idMainMenu);
					}
				}
				else if (c == 27) {
					drawMenu(0, 4, 0);
					idMainMenu = 0;
				}
				else if (c == 13) {
					if (idMainMenu == 0) {
						isPlay = true;
					}
					if (idMainMenu == 1) {
						inLevelMenu = true;
						system("cls");
						drawBoard(0);
						box[2].y += 9;
						box[3].y += 9;
						drawMenu(0, 7, 4);
					}
					if (idMainMenu == 2) {
						inHighscore = true;
						system("cls");
						drawBoard(0);
						outFile();
					}
					if (idMainMenu == 3) {
						inIntroduction = true;
						system("cls");
						drawBoard(0);
					}
					inMainMenu = false;
				}
			}
			else if (inLevelMenu) {
				if (c == 'w' || c == 'W') {
					if (idLevelMenu != 4) {
						idLevelMenu--;
						drawMenu(0, 7, idLevelMenu);
					}
				}
				else if (c == 's' || c == 'S') {
					if (idLevelMenu != 6) {
						idLevelMenu++;
						drawMenu(0, 7, idLevelMenu);
					}
				}
				else if (c == 13) {
					Lv = idLevelMenu - 3;
				}
				if (c == 27) {
					idLevelMenu = 4;
					inMainMenu = true;
					inLevelMenu = false;
					system("cls");
					drawBoard(0);
					box[2].y -= 9;
					box[3].y -= 9;
					drawMenu(0, 4, idMainMenu);
				}
			}
			else if (inHighscore) {
				if (c == 27) {
					inMainMenu = true;
					inHighscore = false;
					system("cls");
					drawBoard(0);
					drawMenu(0, 4, idMainMenu);
				}
			}
			else if (inIntroduction) {
				if (c == 27) {
					inMainMenu = true;
					inIntroduction = false;
					system("cls");
					drawBoard(0);
					drawMenu(0, 4, idMainMenu);
				}
			}
		}
	}
}
void levelMenu()
{
	box[2].y += 9;
	box[3].y += 9;
	for (int i = 0; i < 7; i++)
		box[2].y -= 9;
	box[3].y -= 9;
}
void gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void FixConsoleWindow() {

	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void setColor(int id)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, id);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void writeText(int x, int y, int length, string txt)
{
	int size = txt.length();
	int bien = (length - 2 - size) / 2;
	int i = 1;
	while (i < length - 1)
	{
		if (i <= bien || x > bien + size)
		{
			gotoXY(x + i, y + 1);
			cout << " ";
		}
		i++;
	}
	gotoXY(x + bien + 1, y + 1);
	cout << txt;
}
int Level() {
	return Lv;
}

