#include "stdafx.h"
#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
	Coordinate::x = x;
	Coordinate::y = y;
}

int Coordinate::getX() {
	return x;
}

int Coordinate::getY() {
	return y;
}
