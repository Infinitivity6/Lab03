// �����࣬�����������࣬�߽���ɫ�������ɫ���Ƿ���䣬�Լ�
//���ó�ʼ�����������꣬�߽磬�����ɫ���õ��������ȵȣ�
//�̳�Shape��
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