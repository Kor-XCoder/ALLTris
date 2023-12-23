#include "Tetromino.h"
#include "Location.h"
#include "Window.h"
#include "Board.h"

Tetromino::Tetromino(int _type, Location _abs) {
	type = _type;
	absolute = _abs;
	deg = 0;
	
	blocks[0] = { 0, 0 };
	// 기본 모양 세팅
	switch (type) {
	case J:
		blocks[1] = { -1, 0 };
		blocks[2] = { 1, 0 };
		blocks[3] = { -1, -1 };
		break;
	case L:
		blocks[1] = { -1, 0 };
		blocks[2] = { 1, 0 };
		blocks[3] = { 1, -1 };
		break;
	case S:
		blocks[1] = { -1, 0 };
		blocks[2] = { 0, -1 };
		blocks[3] = { 1, -1 };
		break;
	case T:
		blocks[1] = { -1, 0 };
		blocks[2] = { 0, -1 };
		blocks[3] = { 1, 0 };
		break;
	case Z:
		blocks[1] = { -1, -1 };
		blocks[2] = { 0, -1 };
		blocks[3] = { 1, 0 };
		break;
	case O:
		blocks[1] = { -1, -1 };
		blocks[2] = { -1, 0 };
		blocks[3] = { 0, -1 };
		break;
	case I:
		blocks[1] = { -1, 0 };
		blocks[2] = { 1, 0 };
		blocks[3] = { 2, 0 };
		break;
	default:
		break;
	}
}

void Tetromino::render() {
	
}

void Tetromino::rotate90() {
	deg = (deg == 270 ? 0 : deg + 90);
	if (type == O) return;
	switch (deg) {
	case 0:
		switch (type) {
		case J:
			blocks[1] = { -1, 0 };
			blocks[2] = { 1, 0 };
			blocks[3] = { -1, -1 };
			break;
		case L:
			blocks[1] = { -1, 0 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 1, -1 };
			break;
		case S:
			blocks[1] = { -1, 0 };
			blocks[2] = { 0, -1 };
			blocks[3] = { 1, -1 };
			break;
		case T:
			blocks[1] = { -1, 0 };
			blocks[2] = { 0, -1 };
			blocks[3] = { 1, 0 };
			break;
		case Z:
			blocks[1] = { -1, -1 };
			blocks[2] = { 0, -1 };
			blocks[3] = { 1, 0 };
			break;
		case O:
			blocks[1] = { -1, -1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case I:
			blocks[0] = { 0, 0 };
			blocks[1] = { -1, 0 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 2, 0 };
			break;
		default:
			break;
		}
		break;
	case 90:
		switch (type) {
		case J:
			blocks[1] = { 0, -1 };
			blocks[2] = { 0, 1 };
			blocks[3] = { 1, -1 };
			break;
		case L:
			blocks[1] = { 0, -1 };
			blocks[2] = { 0, 1 };
			blocks[3] = { 1, 1 };
			break;
		case S:
			blocks[1] = { 0, -1 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 1, 1 };
			break;
		case T:
			blocks[1] = { 0, -1 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 0, 1 };
			break;
		case Z:
			blocks[1] = { 1, -1 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 0, 1 };
			break;
		case O:
			blocks[1] = { -1, -1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case I:
			blocks[0] = { 1, 0 };
			blocks[1] = { 1, -1 };
			blocks[2] = { 1, 1 };
			blocks[3] = { 1, 2 };
			break;
		default:
			break;
		}
		break;
	case 180:
		switch (type) {
		case J:
			blocks[1] = { -1, 0 };
			blocks[2] = { 1, 0 };
			blocks[3] = { 1, 1 };
			break;
		case L:
			blocks[1] = { 1, 0 };
			blocks[2] = { -1, 0 };
			blocks[3] = { -1, 1 };
			break;
		case S:
			blocks[1] = { 1, 0 };
			blocks[2] = { 0, 1 };
			blocks[3] = { -1, 1 };
			break;
		case T:
			blocks[1] = { 1, 0 };
			blocks[2] = { 0, 1 };
			blocks[3] = { -1, 0 };
			break;
		case Z:
			blocks[1] = { 1, 1 };
			blocks[2] = { 0, 1 };
			blocks[3] = { -1, 0 };
			break;
		case O:
			blocks[1] = { -1, -1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case I:
			blocks[0] = { 0, 1 };
			blocks[1] = { -1, 1 };
			blocks[2] = { 1, 1 };
			blocks[3] = { 2, 1 };
			break;
		default:
			break;
		}
		break;
	case 270:
		switch (type) {
		case J:
			blocks[1] = { 0, -1 };
			blocks[2] = { 0, 1 };
			blocks[3] = { -1, 1 };
			break;
		case L:
			blocks[1] = { 0, 1 };
			blocks[2] = { 0, -1 };
			blocks[3] = { -1, -1 };
			break;
		case S:
			blocks[1] = { 0, 1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { -1, -1 };
			break;
		case T:
			blocks[1] = { 0, 1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case Z:
			blocks[1] = { -1, 1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case O:
			blocks[1] = { -1, -1 };
			blocks[2] = { -1, 0 };
			blocks[3] = { 0, -1 };
			break;
		case I:
			blocks[0] = { 0, 0 };
			blocks[1] = { 0, -1 };
			blocks[2] = { 0, 1 };
			blocks[3] = { 0, 2 };
			break;
		default:
			break;
		}
		break;
	}
	
	if (type == I) {

	} else {

	}
}
