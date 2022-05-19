//�����࣬������һ���ߵ������˵������Լ�������ɫ���ݣ�
//�̳�Shape��
//��װ�ĺ��������й��죬����getter��setter�Լ�����Ļ滭�����ĺ���
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