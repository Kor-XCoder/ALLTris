#ifndef LOCATION_H
#define LOCATION_H

class Location {
public:
	int x, y;
	Location();
	Location(int _x, int _y);
	bool isOutOfRange() const;
private:
};

#endif // !Location_H
