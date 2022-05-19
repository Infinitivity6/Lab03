//�������࣬�����������࣬�߽���ɫ�������ɫ���Ƿ���䣬�������Լ�
//���ó�ʼ�����������꣬�߽磬�����ɫ���õ��������ȵȣ�
//�̳�Shape��
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