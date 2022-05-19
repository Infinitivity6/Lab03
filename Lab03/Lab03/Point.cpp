#include "Point.h"
Point::Point() = default;
Point::Point(int x_, int y_) {
	x = x_;
	y = y_;
}
void Point::setPoint(int x_, int y_) {
	x = x_;
	y = y_;
}
int Point::getPoint_X()const {
	return x;
}
int Point::getPoint_Y() const {
	return y;
}
