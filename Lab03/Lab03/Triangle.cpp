#include "Triangle.h"
#include "Menu.h"
int Triangle::CountofTri = 0;
Triangle::Triangle() :Triangle(Point(0, 0), Point(0, 0), Point(0, 0), BLACK, WHITE, false) { CountofTri++; };
Triangle::Triangle(Point p1_, Point p2_, Point p3_, color_t c1_, color_t c2_, bool isFilled_) {
	p1 = p1_;
	p2 = p2_;
	p3 = p3_;
	borderColor = c1_;
	fillColor = c2_;
	isFilled = isFilled_;
}
int Triangle::getCountofTri() {
	return CountofTri;
}
vector<Point> Triangle::getTrianglePoint()const {
	vector<Point> point;
	point.push_back(this->p1);
	point.push_back(this->p2);
	point.push_back(this->p3);
	return point;
}
void Triangle::setTrianglePoint(Point p1_, Point p2_, Point p3_) {
	p1 = p1_;
	p2 = p2_;
	p3 = p3_;
}
void Triangle::Draw(Shape* s1) {
	cleardevice();
	setfont(50, 0, "楷体");
	outtextxy(30, 30, "按Y键开始作画");
	int key_msg = getch();
	if (key_msg == 89) {
		setfillcolor(s1->getFillColor());
		setcolor(s1->getBorderColor());
		int mouse_x{ 0 }, mouse_y{ 0 };
		int mouse_x_sec{ 0 }, mouse_y_sec{ 0 };
		int mouse_x_thd{ 0 }, mouse_y_thd{ 0 };
		int x{ 0 }, y{ 0 };
		int cnt{ 0 };
		bool upflag{ false };
		bool moveflag{ false };
		for (; is_run(); delay_fps(60)) {
			mouse_msg msg = { 0 };
			bool downflag{ false };
			while (mousemsg()) {
				msg = getmouse();
			}
			if (msg.is_move() && (!moveflag)) {
				cleardevice();
				line(msg.x, msg.y, msg.x - 20, msg.y);
				line(msg.x, msg.y, msg.x, msg.y + 20);
				line(msg.x - 20, msg.y, msg.x, msg.y + 20);
			}
			if (msg.is_down() && (cnt == 0)) {
				setfont(20, 0, "楷体");
				outtextxy(30, 30, "已确定其中一个端点");
				mousepos(&mouse_x, &mouse_y);
				downflag = !downflag;
				cnt++;
				moveflag = !moveflag;
			}
			if (msg.is_up() && (cnt == 1) && (!upflag)) {
				cleardevice();
				mousepos(&mouse_x_sec, &mouse_y_sec);
				line(mouse_x, mouse_y, mouse_x_sec, mouse_y_sec);
				setfont(20, 0, "楷体");
				outtextxy(30, 30, "已确定第二点，请点出第三点");
				upflag = !upflag;
			}
			if (msg.is_down() && (cnt == 1) && (upflag)) {
				mousepos(&mouse_x_thd, &mouse_y_thd);
				setTrianglePoint(Point(mouse_x, mouse_y), Point(mouse_x_sec, mouse_y_sec), Point(mouse_x_thd, mouse_y_thd));
				cleardevice();
				if(s1){
				line(dynamic_cast<Triangle*>(s1)->getTrianglePoint()[0].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[0].getPoint_Y(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[1].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[1].getPoint_Y());
				line(dynamic_cast<Triangle*>(s1)->getTrianglePoint()[0].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[0].getPoint_Y(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[2].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[2].getPoint_Y());
				line(dynamic_cast<Triangle*>(s1)->getTrianglePoint()[2].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[2].getPoint_Y(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[1].getPoint_X(), dynamic_cast<Triangle*>(s1)->getTrianglePoint()[1].getPoint_Y());
				floodfill((mouse_x + mouse_x_sec + mouse_x_thd) / 3, (mouse_y + mouse_y_sec + mouse_y_thd) / 3, s1->getBorderColor());
				}
				setfont(30, 0, "楷体");
				outtextxy(30, 30, "已完成，按Y继续画图，按M返回菜单，其他键退出");
				xyprintf(30, 200, "当前一共画了%d个三角形", getCountofTri());
				Write(output);
				int key_msg = getch();
				if (key_msg == 89) {
					                   //继续画
					CountofTri++;
					Draw(s1);
				}
				else if (key_msg == 77) { //返回菜单
					Menu menu;
					menu.Begin();
				}
				else {
					closegraph();
				}
				delete s1;
				s1 = nullptr;
			}
		}
	}
	else { Draw(s1); }
}
Triangle::Triangle(Triangle& t1) {
	this->p1 = t1.p1;
	this->p2 = t1.p2;
	this->p3 = t1.p3;
}
void Triangle::Write(ofstream& out){
	out << "3" << std::endl;
	out << this->getTrianglePoint()[0].getPoint_X() << " " << this->getTrianglePoint()[0].getPoint_Y() << " "
		<< this->getTrianglePoint()[1].getPoint_X() << " " << this->getTrianglePoint()[1].getPoint_Y() << " "
		<< this->getTrianglePoint()[2].getPoint_X() << " " << this->getTrianglePoint()[2].getPoint_Y() << std::endl;
	out << this->getFillColor() << " " <<this->getBorderColor()<<" "<< this->hasFilled() << std::endl;
}