//Menu类，包含了人机交互的实现方法函数以及整个程序的菜单运行顺序，并调用相应的Draw_xxx（）函数
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