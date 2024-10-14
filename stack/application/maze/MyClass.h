#pragma once
class Direction{
public:
	int incX, incY;
	Direction(int incX, int incY) {
		this->incX = incX;
		this->incY = incY;
	}
};
Direction d1(1, 0);
Direction d2(0, 1);
Direction d3(-1, 0);
Direction d4(0, -1);
Direction direct[4] = { d1,d2,d3,d4 };
class Pos {
public:
	int x, y;
	Pos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
class Box {
public:
	int x, y;
	int di;
	Box() {
		this->x = -1;
		this->y = -1;
		this->di = -1;
	}
	Box(int x, int y, int di) {
		this->x = x;
		this->y = y;
		this->di = di;
	}
};



