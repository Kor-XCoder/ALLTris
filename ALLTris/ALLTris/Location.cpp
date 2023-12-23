#include "Location.h"

Location::Location(int _x, int _y) {
	x = _x;
	y = _y;
}

Location::Location() {
	x = 0; y = 0;
}

bool Location::isOutOfRange() const {
	return (x < 1 || y < 1 || x > 10 || y > 20);
}