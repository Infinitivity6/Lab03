//��ɫ�࣬������һ����ɫ���ͣ�int���ı����Լ���Ӧ�Ĺ��죬������getter��setter
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