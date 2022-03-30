#include "Menu.h"
// boxColor 140
// test1Color 228
// test2Color 134
string strMainMenu[6];
string strLevelMenu[4];
string strSkinMenu[5];
string tempStr = "Audio: OFF";
Box boxMainMenu[6];
Box boxLevelMenu[4];
Box boxSkinMenu[5];
int Lv = 1;
int skin = 0;
bool isPlay = false;
vector<string> lines;
vector<int> diem;
bool inMainMenu = true, inLevelMenu = false, inHighscore = false, inIntroduction = false, inSkin = false;
int idMainMenu = 0;
// 0 <= idMainMenu < 5
int idLevelMenu = 0;    //  0 <= idLevelMenu < 4
int idSkinMenu = 0;

void readFile()
{
	lines.resize(0);
	diem.resize(0);
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

void setStringBox()
{
	strMainMenu[0] = "Start";
	strMainMenu[1] = "Level";
	strMainMenu[2] = "Skin";
	strMainMenu[3] = "Highscore";
	strMainMenu[4] = "Audio: ON";
	strMainMenu[5] = "Introduction";

	strLevelMenu[0] = "Eazy";
	strLevelMenu[1] = "Medium";
	strLevelMenu[2] = "Hard";
	strLevelMenu[3] = "Expert";

	strSkinMenu[0] = "ooooo0";
	strSkinMenu[1] = "ooooo0";
	strSkinMenu[2] = "ooooo0";
	strSkinMenu[3] = "ooooo0";
	strSkinMenu[4] = "ooooo0";
}
void setBox()
{
	boxMainMenu[0] = { (length_CS1 - length_Box) / 2,5,length_Box ,width_Box };
	boxMainMenu[1] = { (length_CS1 - length_Box) / 2,8,length_Box ,width_Box };
	boxMainMenu[2] = { (length_CS1 - length_Box) / 2,11,length_Box ,width_Box };
	boxMainMenu[3] = { (length_CS1 - length_Box) / 2,14,length_Box ,width_Box };
	boxMainMenu[4] = { (length_CS1 - length_Box) / 2,17,length_Box ,width_Box };
	boxMainMenu[5] = { (length_CS1 - length_Box) / 2,20,length_Box ,width_Box };

	boxLevelMenu[0] = { (length_CS1 - length_Box) / 2,8,length_Box,width_Box };
	boxLevelMenu[1] = { (length_CS1 - length_Box) / 2,11,length_Box,width_Box };
	boxLevelMenu[2] = { (length_CS1 - length_Box) / 2,14,length_Box,width_Box };
	boxLevelMenu[3] = { (length_CS1 - length_Box) / 2,17,length_Box,width_Box };

	boxSkinMenu[0] = { (length_CS1 - length_Box) / 2,8,length_Box ,width_Box };
	boxSkinMenu[1] = { (length_CS1 - length_Box) / 2,11,length_Box ,width_Box };
	boxSkinMenu[2] = { (length_CS1 - length_Box) / 2,14,length_Box ,width_Box };
	boxSkinMenu[3] = { (length_CS1 - length_Box) / 2,17,length_Box ,width_Box };
	boxSkinMenu[4] = { (length_CS1 - length_Box) / 2,20,length_Box ,width_Box };
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
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

int Level() {
	return Lv;
}

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
	for (int i = 1; i <= width_CS / 2; i++)
	{
		gotoXY(length_CS1 + 1, i);
		printf("%c", 179);
		gotoXY(length_CS1 + 1, width_CS + 1 - i);
		printf("%c", 179);
		Sleep(speed);
	}
}
void drawBox(int x, int y, int length, int width)
{
	setColor(136);
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
void drawMainMenu(int cdt) // Ve tu` o bg den' o ed nhung to dam. o cdt
{
	for (int i = 0; i < 6; i++) {
		if (i == cdt)
			writeText(boxMainMenu[i].x, boxMainMenu[i].y, boxMainMenu[i].length, strMainMenu[i], 228);
		else
			writeText(boxMainMenu[i].x, boxMainMenu[i].y, boxMainMenu[i].length, strMainMenu[i], 134);
	}
}
void drawLevelMenu(int cdt) // Ve tu` o bg den' o ed nhung to dam. o cdt
{
	for (int i = 0; i < 4; i++) {
		if (i == cdt)
			writeText(boxLevelMenu[i].x, boxLevelMenu[i].y, boxLevelMenu[i].length, strLevelMenu[i], 228);
		else
			writeText(boxLevelMenu[i].x, boxLevelMenu[i].y, boxLevelMenu[i].length, strLevelMenu[i], 134);
	};
}
void drawSkinMenu(int cdt) // Ve tu` o bg den' o ed nhung to dam. o cdt
{
	int color = 0;
	int color_cdt = 0;
	for (int i = 0; i < 5; i++) {
		if (i == cdt) {
			if (i == 0) color = 225;
			else if (i == 1) color = 228;
			else if (i == 2) color = 229;
			else if (i == 3) color = 230;
			else color = 237;
			color_cdt = color;
		}
		else {
			if (i == 0) color = 129;
			else if (i == 1) color = 132;
			else if (i == 2) color = 133;
			else if (i == 3) color = 134;
			else color = 141;
		}
		writeText(boxSkinMenu[i].x, boxSkinMenu[i].y, boxSkinMenu[i].length, strSkinMenu[i], color);
	}
	setColor(color_cdt);
	int pointStart = boxSkinMenu[cdt].x + (boxSkinMenu[1].length - 6) / 2;
	int tail = 0;
	while (1) {
		if (pointStart < boxSkinMenu[cdt].x + boxSkinMenu[1].length - 3) {
			if (_kbhit()) return;
			int a = 0;
			int bien;
			for (int i = 0; i < 6; i++) {
				bien = 1;
				if (pointStart + i < boxSkinMenu[cdt].x + boxSkinMenu[1].length - 3)
					gotoXY(pointStart + i, boxSkinMenu[cdt].y + 1);
				else {
					gotoXY(boxSkinMenu[cdt].x + bien + a, boxSkinMenu[cdt].y + 1);
					bien++;
				}
				if (i == 5) cout << "0";
				else cout << "o";
			}
			if (bien != 1) a++;
			if (pointStart == boxSkinMenu[cdt].x + 1)
				gotoXY(boxSkinMenu[cdt].x + boxSkinMenu[1].length - 6, boxSkinMenu[cdt].y + 1);
			else
				gotoXY(pointStart - 1, boxSkinMenu[cdt].y + 1);
			cout << " ";
			Sleep(100);
			pointStart++;
		}
		else pointStart = boxSkinMenu[cdt].x + 1;
	}
}

void mainMenu()
{
	readFile();
	setBox();
	setStringBox();
	drawMainMenu(0);
	while (!isPlay) {
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'w' || c == 'W') {
				if (inMainMenu) {
					if (idMainMenu > 0) idMainMenu--;
					else idMainMenu = 5;
					drawMainMenu(idMainMenu);
				}
				else if (inLevelMenu) {
					if (idLevelMenu > 0) idLevelMenu--;
					else idLevelMenu = 3;
					drawLevelMenu(idLevelMenu);
				}
				else if (inSkin) {
					if (idSkinMenu > 0) idSkinMenu--;
					else idSkinMenu = 4;
					drawSkinMenu(idSkinMenu);
				}
			}
			else if (c == 's' || c == 'S') {
				if (inMainMenu) {
					if (idMainMenu < 5) idMainMenu++;
					else idMainMenu = 0;
					drawMainMenu(idMainMenu);
				}
				else if (inLevelMenu) {
					if (idLevelMenu < 3)idLevelMenu++;
					else idLevelMenu = 0;
					drawLevelMenu(idLevelMenu);
				}
				else if (inSkin) {
					if (idSkinMenu < 4) idSkinMenu++;
					else idSkinMenu = 0;
					drawSkinMenu(idSkinMenu);
				}
			}
			else if (c == 13) {
				if (inMainMenu) {
					inMainMenu = false;
					if (idMainMenu == 0) isPlay = true;
					else if (idMainMenu == 1) {
						inLevelMenu = true;
						clrscr();
						drawBoard(0);
						writeText(boxMainMenu[1].x - 3, boxMainMenu[1].y - 3, boxMainMenu[1].length + 6, strMainMenu[1], 228);
						drawLevelMenu(0);
					}
					else if (idMainMenu == 2) {
						inSkin = true;
						clrscr();
						drawBoard(0);
						writeText(boxMainMenu[2].x - 3, boxMainMenu[2].y - 6, boxMainMenu[2].length + 6, strMainMenu[2], 228);
						drawSkinMenu(0);
					}
					else if (idMainMenu == 3)
					{
						inHighscore = true;
						system("cls");
						drawBoard(0);
						highscoreMenu();
					}
					else if (idMainMenu == 4) {
						strMainMenu[4].swap(tempStr);
						drawMainMenu(4);
						inMainMenu = true;
					}
					else {
						inIntroduction = true;
						introductionMenu();
					}
				}
				else if (inLevelMenu) Lv = idLevelMenu;
				else if (inSkin) skin = idSkinMenu;
			}
			else if (c == 27) {
				if (inMainMenu) idMainMenu = 0;
				else if (inLevelMenu) inLevelMenu = false;
				else if (inSkin) inSkin = false;
				else if (inHighscore) inHighscore = false;
				else inIntroduction = false;

				inMainMenu = true;
				setColor(134);
				system("cls");
				drawBoard(0);
				drawMainMenu(idMainMenu);
			}
		}
	}
}
void highscoreMenu() {
	setColor(246);
	gotoXY(length_CS1 / 2 - 8, 9);
	cout << "Player";
	gotoXY(length_CS1 / 2 + 8, 9);
	cout << "Score";
	setColor(134);
	for (int i = 0; i < 5; i++) {
		gotoXY(length_CS1 / 2 - 8, 12 + 2 * i);
		cout << lines[i];
		gotoXY(length_CS1 / 2 + 8, 12 + 2 * i);
		cout << diem[i];
	}
}
void introductionMenu() {

}
void writeText(int x, int y, int length, string txt, int color)
{
	setColor(color);
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

void writeTextSnake(int x, int y, int color, int pointStart) {
	int length = boxLevelMenu[1].length;
	int bien = 1;
	for (int i = 1; i < 7; i++) {
		if (pointStart + i < length) gotoXY(pointStart + i, y + 1);
		else {
			gotoXY(x + bien, y + 1);
			bien++;
		}
		if (i != 6)
			cout << "o";
		else cout << "0";
	}
	gotoXY(pointStart, y + 1);
	cout << " ";
}

