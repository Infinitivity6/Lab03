// 矩形类，包含两个点类，边界颜色，填充颜色，是否填充，以及
//设置初始化三个点坐标，边界，填充颜色，得到点的坐标等等；
//继承Shape类
#pragma once
#include "Color.h"
#include "Point.h"
#include "Shape.h"
#include <vector>
using std::vector;
class myRectangle :public Shape {
private:
	Point p1;
	Point p2;
	static int CountofRec;
public:
	myRectangle();
	myRectangle(Point, Point, color_t, color_t, bool);
	myRectangle(myRectangle&);
	static int getCountofRec();
	void setRectanglePoint(Point, Point);
	vector<Point> getRectanglePoint()const;
	//void Draw_Rectangle(myRectangle&,Shape*);
	void Draw(Shape*)override;
	void Write(ofstream&)override;
	~myRectangle();
};