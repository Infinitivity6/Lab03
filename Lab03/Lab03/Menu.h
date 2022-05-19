//Menu�࣬�������˻�������ʵ�ַ��������Լ���������Ĳ˵�����˳�򣬲�������Ӧ��Draw_xxx��������
#pragma once
#include <graphics.h>
#include <vector>
#include "Shape.h"
#include"Circle.h"
#include "Line.h"
#include "myRectangle.h"
#include "Triangle.h"
#include "Point.h"
#include "ReadFromFile.h"
using std::vector;
class Menu {
private:
	Shape* s1{ nullptr };
	Circle* c1{ nullptr };
	Line* l1{ nullptr };
	myRectangle* r1{ nullptr };
	Triangle* t1{ nullptr };
	ReadFromFile f1;
public:
	vector<Shape*> Shapes;
	Menu();
	~Menu();
	void ReadFile();
	void Begin();
	void ChooseShape();
	void ChooseBorderColor(Shape*);
	void ChooseFillColor(Shape*);
	void Draw(Shape*);
	void Continue();
	void Quit();
	vector<Shape*> getShapes()const;
};