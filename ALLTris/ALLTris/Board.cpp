#include "Board.h"
#include <vector>
#include <algorithm>
#include "Location.h"

Board::Board() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			board[i][j] = 0; // 모두 검은색으로 설정
		}
	}
}

