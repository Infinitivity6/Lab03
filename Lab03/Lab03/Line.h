//线条类，包含了一条线的两个端点数据以及线条颜色数据，
//继承Shape类
//封装的函数方法有构造，析构getter，setter以及具体的绘画线条的函数
#pragma once
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include <cmath>
#include <vector>

using std::vector;
class Line :public Shape {
private:
	Point p1;
	Point p2;
	static int CountofLine;
public:
	Line();
	Line(Point, Point, color_t);
	Line(Line&);
	vector<Point> getLinePoint()const;
	void setLinePoint(Point, Point);
	static int getCountofLine();
	//void Draw_Line(Line&,Shape*);
	void Draw(Shape*)override;
	~Line();
	void Write(ofstream&)override;
};