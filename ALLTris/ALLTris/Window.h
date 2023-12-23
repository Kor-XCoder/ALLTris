#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
	static void gotoXY(int x, int y);
	static void gotoScreenXY(int x, int y);
	static void gotoBoardXY(int x, int y);
	static void gotoHoldXY(int x, int y);
	static void setColor(int color);
	static void setCursorState(bool state);
	static void clearScreen();
	static void renderTetrisBorder();
	static void placeBlock(int x, int y);
	static void placeBlock(int x, int y, int color);
	static void placeHoldBlock(int x, int y);
	static void placeHoldBlock(int x, int y, int color);
	static void clearBoard();
	static void updateBoard(Board Visual, Board Real);

	static const int Black = 0;
	static const int Red = 1;
	static const int Green = 2;
	static const int Yellow = 3;
	static const int Blue = 4;
	static const int Magenta = 5;
	static const int Cyan = 6;
	static const int White = 7;
	static const int Orange = 8;
private:
};

#endif // !WINDOW_H
