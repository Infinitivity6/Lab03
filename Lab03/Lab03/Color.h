//颜色类，包含了一个颜色类型（int）的变量以及相应的构造，析构，getter，setter
#pragma once
#include <graphics.h>
class Color {
private:
	color_t color{ 0xf2eada };
public:
	Color();
	Color(color_t);
	void setColor(color_t);
	color_t getColor()const;
};