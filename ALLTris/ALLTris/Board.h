#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>
#include "Location.h"

class Board {
public:
	int board[21][11];
	Board();

	static const int N = 20;
	static const int M = 10;
private:
};

#endif // !BOARD_H
