#include "myRectangle.h"
#include "Menu.h"
int myRectangle::CountofRec = 0;
myRectangle::myRectangle() :myRectangle(Point(0, 0), Point(0, 0), BLACK, WHITE, false) { CountofRec++; };
myRectangle::myRectangle(Point p1, Point p2, color_t c1, color_t c2, bool b1) {
	this->p1 = p1;
	this->p2 = p2;
	this->borderColor = c1;
	this->fillColor = c2;
}
int myRectangle::getCountofRec() {
	return CountofRec;
}
void myRectangle::setRectanglePoint(Point p1, Point p2) {
	this->p1 = p1;
	this->p2 = p2;
}

vector <Point> myRectangle::getRectanglePoint() const {
	vector<Point> point;
	point.push_back(p1);
	point.push_back(p2);
	return point;
}

void myRectangle::Draw(Shape* s1) {
	cleardevice();
	setfont(50, 0, "楷体");
	outtextxy(30, 30, "按Y键开始作画");
	int key_msg = getch();
	if (key_msg == 89) {
		setfillcolor(s1->getFillColor());
		setcolor(s1->getBorderColor());
		int mouse_x{ 0 }, mouse_y{ 0 };
		int mouse_x_change{ 0 }, mouse_y_change{ 0 };
		int x{ 0 }, y{ 0 };
		for (; is_run(); delay_fps(60)) {
			mouse_msg msg = { 0 };
			bool downflag{ false };
			bool upflag{ false };
			while (mousemsg()) {
				msg = getmouse();
			}

			if (msg.is_move()) {
				cleardevice();
				rectangle(msg.x, msg.y, msg.x + 15, msg.y + 10);
			}
			if (msg.is_down() && (!downflag)) {
				setfont(30, 0, "楷体");
				outtextxy(30, 30, "已确定左上端点");
				mousepos(&mouse_x, &mouse_y);
				downflag = !downflag;
			}
			if (msg.is_up()) {
				cleardevice();
				mousepos(&mouse_x_change, &mouse_y_change);
				if(s1){
				dynamic_cast<myRectangle*>(s1)->setRectanglePoint(Point(mouse_x, mouse_y), Point(mouse_x_change, mouse_y_change));
				rectangle(dynamic_cast<myRectangle*>(s1)->getRectanglePoint()[0].getPoint_X(), dynamic_cast<myRectangle*>(s1)->getRectanglePoint()[0].getPoint_Y(), dynamic_cast<myRectangle*>(s1)->getRectanglePoint()[1].getPoint_X(), dynamic_cast<myRectangle*>(s1)->getRectanglePoint()[1].getPoint_Y());
				floodfill((mouse_x + mouse_x_change) / 2, (mouse_y + mouse_y_change) / 2, s1->getBorderColor());
				}
				setfont(30, 0, "楷体");
				outtextxy(30, 30, "绘画完成！继续画请按Y，按M返回菜单，退出请按其他任意键");
				xyprintf(30, 200, "当前一共画了%d个矩形", getCountofRec());
				Write(output);
				upflag = !upflag;
				int key_msg = getch();
				if (key_msg == 89) {
					CountofRec++;
					Draw(s1);
				}
				else if (key_msg == 77) {
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
myRectangle::myRectangle(myRectangle& r1) {
	this->p1 = r1.p1;
	this->p2 = r1.p2;
}
void myRectangle::Write(ofstream& out) {
	out << "2" << std::endl;
	out << this->getRectanglePoint()[0].getPoint_X() << " " << this->getRectanglePoint()[0].getPoint_Y()
	 <<" "<< this->getRectanglePoint()[1].getPoint_X() << " " << this->getRectanglePoint()[1].getPoint_Y() << std::endl;
	out << this->getFillColor() << " " <<this->getBorderColor()<<" "<< this->hasFilled() << std::endl;
}
