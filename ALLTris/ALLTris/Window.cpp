#include "Window.h"
#include <iostream>
#include <windows.h>
#include "Board.h"
#include "Location.h"
#include <vector>
#include <algorithm>
using namespace std;

#define stdHandle GetStdHandle(STD_OUTPUT_HANDLE)

void Window::gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(stdHandle, pos);
}

void Window::gotoScreenXY(int x, int y) {
	cout << "\x1b[" << y << ";" << (x*2+1) << "H";
}

void Window::setCursorState(bool state)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = state;
	SetConsoleCursorInfo(stdHandle, &cursorInfo);
}

void Window::setColor(int color) {
	// Default background/foreground colours as zero
	int bg = 0;

	switch (color)
	{
	case 0: {bg = 0; break; } // Black
	case 1: {bg = 41; break; } // Red
	case 2: {bg = 42; break; } // Green
	case 3: {bg = 43; break; } // Yellow
	case 4: {bg = 44; break; } // Blue
	case 5: {bg = 45; break; } // Magenta
	case 6: {bg = 46; break; } // Cyan
	case 7: {bg = 47; break; } // White
	case 8: {cout << "\033[48;2;255;165;0m"; return; } // Orange (RGB)
	}

	cout << "\033[0;" << bg << "m";
}


void Window::gotoBoardXY(int x, int y) {
	// 시작: (1, 1)
	int nx = 30 + x*2;
	int ny = 3 + y;
	Window::gotoXY(nx, ny);
}

void Window::clearScreen() {
	gotoXY(1, 1);
	cout << "\033[2J";
}

void Window::renderTetrisBorder() {
	gotoXY(5, 6);  cout << "┌─────HOLD────┐";
	gotoXY(5, 7);  cout << "│             │";
	gotoXY(5, 8);  cout << "│             │";
	gotoXY(5, 9);  cout << "│             │";
	gotoXY(5, 10); cout << "│             │";
	gotoXY(5, 11); cout << "└─────────────┘";

	gotoXY(30, 3); cout << "┌";
	gotoXY(52, 3); cout << "┐";
	gotoXY(30, 24); cout << "└";
	gotoXY(52, 24); cout << "┘";

	for (int i = 31; i <= 51; i++) {
		gotoXY(i, 3);
		cout << "─";
		gotoXY(i, 24);
		cout << "─";
	}

	for (int i = 4; i <= 23; i++) {
		gotoXY(30, i);
		cout << "│";
		gotoXY(52, i);
		cout << "│";
	}

	for (int i = 1; i <= 20; i++) {
		setColor(i % 8 + 1);
		for (int j = 1; j <= 10; j++) {
			Window::placeBlock(j, i);
		}
	}
	setColor(-1);
}

void Window::placeBlock(int x, int y)
{
	gotoBoardXY(x, y);
	cout << "  ";
}

void Window::placeBlock(int x, int y, int color)
{
	setColor(color);
	gotoBoardXY(x, y);
	cout << "  ";
	setColor(-1);
}

void Window::clearBoard() {
	for (int i = 1; i <= 20; i++) {
		setColor(-1);
		for (int j = 1; j <= 10; j++) {
			gotoBoardXY(j, i);
			cout << "  ";
		}
	}
}

void Window::updateBoard(Board Visual, Board Real) {
	// 바뀐 부분만 바꿔야 시간을 줄이고, 플리커 현상을 줄일 수 있음.
	
}

void Window::gotoHoldXY(int x, int y) {
	// (1, 1) ~ (6, 4)
	int nx = 5 + x*2;
	int ny = 6 + y;
	gotoXY(nx, ny);
}

void Window::placeHoldBlock(int x, int y) {
	gotoHoldXY(x, y);
	cout << "  ";
}

void Window::placeHoldBlock(int x, int y, int color) {
	setColor(color);
	gotoHoldXY(x, y);
	cout << "  ";
	setColor(Black);
}