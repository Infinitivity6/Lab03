//三角形类，包含三个点类，边界颜色，填充颜色，是否填充，数量，以及
//设置初始化三个点坐标，边界，填充颜色，得到点的坐标等等；
//继承Shape类
#pragma once
#include <vector>
#include "Color.h"
#include "Point.h"
#include "Shape.h"
#include <graphics.h>
using std::vector;
class Triangle :public Shape {
private:
	Point p1;
	Point p2;
	Point p3;
	static int CountofTri;
public:
	Triangle();
	Triangle(Point, Point, Point, color_t, color_t, bool);
	Triangle(Triangle&);
	static int getCountofTri();
	void setTrianglePoint(Point, Point, Point);
	vector<Point> getTrianglePoint()const;
	//void Draw_Triangle(Triangle&,Shape*);
	void Draw(Shape*)override;
	void Write(ofstream&)override;
	~Triangle();
};