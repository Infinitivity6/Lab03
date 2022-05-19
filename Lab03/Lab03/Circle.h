// 圆类，包含一个点类，边界颜色，填充颜色，是否填充，以及
//设置初始化三个点坐标，边界，填充颜色，得到点的坐标等等；
//继承了Shape类
#pragma once
#include "Color.h"
#include "Point.h"
#include <graphics.h>
#include "Shape.h"
#include <cmath>
class Circle :public Shape {
private:
	Point p1;
	int radius;
	static int CountofCircle;
public:
	Circle();
	Circle(Point, int, color_t, color_t, bool);
	Circle(Circle&);
	void setCirclePoint(Point);
	void setCircleRadius(int);
	Point getCirclePoint()const;
	int getRadius()const;
	static int getCountofCircle();
	void Draw(Shape*)override;
	~Circle();
	void Write(ofstream&)override;
};
