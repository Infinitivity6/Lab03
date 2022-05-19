#include "Color.h"
Color::Color() :Color(0xffffff) {};
Color::Color(color_t c1) { color = c1; };
void Color::setColor(color_t c1) { color = c1; };
color_t Color::getColor()const { return color; };