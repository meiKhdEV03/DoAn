#include "Menu.h"
#include "Playgame.h"
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
	boxMainMenu[0] = { (length_CS1 - length_Box) / 2,10,length_Box ,width_Box };
	boxMainMenu[1] = { (length_CS1 - length_Box) / 2,13,length_Box ,width_Box };
	boxMainMenu[2] = { (length_CS1 - length_Box) / 2,16,length_Box ,width_Box };
	boxMainMenu[3] = { (length_CS1 - length_Box) / 2,19,length_Box ,width_Box };
	boxMainMenu[4] = { (length_CS1 - length_Box) / 2,22,length_Box ,width_Box };
	boxMainMenu[5] = { (length_CS1 - length_Box) / 2,25,length_Box ,width_Box };

	boxLevelMenu[0] = { (length_CS1 - length_Box) / 2,13,length_Box,width_Box };
	boxLevelMenu[1] = { (length_CS1 - length_Box) / 2,16,length_Box,width_Box };
	boxLevelMenu[2] = { (length_CS1 - length_Box) / 2,19,length_Box,width_Box };
	boxLevelMenu[3] = { (length_CS1 - length_Box) / 2,22,length_Box,width_Box };

	boxSkinMenu[0] = { (length_CS1 - length_Box) / 2,13,length_Box ,width_Box };
	boxSkinMenu[1] = { (length_CS1 - length_Box) / 2,17,length_Box ,width_Box };
	boxSkinMenu[2] = { (length_CS1 - length_Box) / 2,20,length_Box ,width_Box };
	boxSkinMenu[3] = { (length_CS1 - length_Box) / 2,23,length_Box ,width_Box };
	boxSkinMenu[4] = { (length_CS1 - length_Box) / 2,27,length_Box ,width_Box };
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
	if (!isPlay) title1();
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
	Snake snakeMenu[6];
	snakeMenu[0] = { pointStart + 5,boxSkinMenu[0].y + 1,0,0 };
	snakeMenu[1] = { pointStart + 4,boxSkinMenu[0].y + 1,0,0 };
	snakeMenu[2] = { pointStart + 3,boxSkinMenu[0].y + 1,0,0 };
	snakeMenu[3] = { pointStart + 2,boxSkinMenu[0].y + 1,0,0 };
	snakeMenu[4] = { pointStart + 1,boxSkinMenu[0].y + 1,0,0 };
	snakeMenu[5] = { pointStart ,boxSkinMenu[0].y + 1,0,0 };
	while (1) {
		if (_kbhit()) return;
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				snakeMenu[i].x0 = snakeMenu[i].x;
				if (snakeMenu[i].x + 1 <= boxSkinMenu[1].x + boxSkinMenu[1].length - 3)
					snakeMenu[i].x++;
				else snakeMenu[i].x = boxSkinMenu[1].x + 1;
			}
			else {
				snakeMenu[i].x0 = snakeMenu[i].x;
				snakeMenu[i].x = snakeMenu[i - 1].x0;
			}
		}
		for (int i = 0; i < 6; i++) {
			gotoXY(snakeMenu[i].x, boxSkinMenu[cdt].y + 1);
			if (i == 0) cout << "0";
			else cout << "o";
		}
		gotoXY(snakeMenu[5].x0, boxSkinMenu[cdt].y + 1);
		cout << " ";
		Sleep(50);
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
						system("cls");
						setColor(134);
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
						setColor(134);
						system("cls");
						drawBoard(0);
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
	title2();
	gotoXY(60, 20);
	cout << "Do An: Snake-Game";
	gotoXY(60, 21);
	cout << "Nhom thuc hien: Nhom 17";
	gotoXY(60, 22);
	cout << "Giang vien: Truong Toan Thinh";
	gotoXY(20, 19);
	cout << "Danh sach thanh vien:";
	gotoXY(20, 20);
	cout << "21120473 - Tran Nguyen Gia Huy";
	gotoXY(20, 21);
	cout << "21120488 - Nguyen Dang Ba Kiet";
	gotoXY(20, 22);
	cout << "21120480 - Ta Ngoc Duy Khiem";
	gotoXY(20, 23);
	cout << "19120463 - Le Thanh Chau";
	gotoXY(20, 24);
	cout << "20120409 - Tran Thanh Tung";
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
void title1() {
	setColor(135);
	fstream fp;
	fp.open("titleSmall.txt", ios::in);
	string str = {};
	int i = 0;
	while (!fp.eof()) {
		getline(fp, str);
		gotoXY(20, 2 + i);
		i++;
		cout << str;
	}
}
void title2() {
	setColor(132);
	fstream fp;
	fp.open("titleBig.txt", ios::in);
	string str = {};
	int i = 0;
	while (!fp.eof()) {
		getline(fp, str);
		gotoXY(5, 2 + i);
		i++;
		cout << str;
	}
}



