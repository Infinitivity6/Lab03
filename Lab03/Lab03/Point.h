//一个点的坐标类，包含x，y；以及设置，获取x，y，是每个图形类的必备内嵌对象

#pragma once
class Point {
private:
	int x{ 0 };
	int y{ 0 };
public:
	Point();
	Point(int, int);
	void setPoint(int, int);
	int getPoint_X() const;
	int getPoint_Y() const;
};