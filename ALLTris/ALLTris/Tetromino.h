#ifndef TETROMINO_H
#define TETROMINO_H

#include "Location.h"

class Tetromino {
public:
	static const int J = 1;
	static const int L = 2;
	static const int S = 3;
	static const int T = 4;
	static const int Z = 5;
	static const int O = 6;
	static const int I = 7;

	Location blocks[4]; // 상대 좌표로 저장
	Location absolute; // 상대 좌표 기준 (0, 0)을 절대 죄표로 저장
	int type;
	int deg;
	Tetromino(int _type, Location _abs);
	void render();
	void rotate90();
	bool applyGravity();
	void moveHorizontal(int move);
private:
};

#endif // !Tetromino_H
