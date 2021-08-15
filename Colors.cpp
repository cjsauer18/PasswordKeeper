
#include "Colors.h"

using namespace std;


void color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_ERROR_HANDLE), c);

}


void formatBox(string text, int startXPos, int startYPos) {

	gotoxy(startXPos, startYPos);
    cout << char(218);      for (int i = 0; i < 21; i++) { cout << char(196); }      cout << char(191) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(179) << "                     " << char(179) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(179) << "                     " << char(179) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(179) << text  << setw(22 - text.size())      << char(179) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(179) << "                     " << char(179) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(179) << "                     " << char(179) << endl;
	startYPos++;

	gotoxy(startXPos, startYPos);
	cout << char(192);      for (int i = 0; i < 21; i++) { cout << char(196); }      cout << char(217) << endl;

}

