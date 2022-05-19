
#include "Shape.h"
Shape::Shape() {

};
Shape::~Shape() {

};
void Shape::setBorderColor(color_t c1) {
	borderColor = c1;
}
void Shape::setFillColor(color_t c1) {
	fillColor = c1;
}
color_t Shape::getBorderColor()const {
	return borderColor;
}
color_t Shape::getFillColor()const {
	return fillColor;
}
void Shape::setisFilled(bool b1) {
	isFilled = b1;
}

bool Shape::hasFilled()const {
	return isFilled;
}