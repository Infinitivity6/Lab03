// Բ�࣬����һ�����࣬�߽���ɫ�������ɫ���Ƿ���䣬�Լ�
//���ó�ʼ�����������꣬�߽磬�����ɫ���õ��������ȵȣ�
//�̳���Shape��
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
