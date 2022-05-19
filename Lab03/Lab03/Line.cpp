#include "Line.h"
#include "Menu.h"
int Line::CountofLine = 0;
Line::Line() :Line(Point(0, 0), Point(0, 0), BLACK) {  };
Line::Line(Point p1, Point p2, color_t c1) {
	this->p1 = p1;
	this->p2 = p2;
	this->borderColor = c1;
}
int Line::getCountofLine() {
	return CountofLine;
}
void Line::setLinePoint(Point p1, Point p2) {
	this->p1 = p1;
	this->p2 = p2;
}
vector<Point> Line::getLinePoint()const {
	vector<Point> point;
	point.push_back(this->p1);
	point.push_back(this->p2);
	return point;
}
void Line::Draw(Shape* s1) {
	cleardevice();
	setfont(50, 0, "楷体");
	outtextxy(30, 30, "按Y键开始作画");
	int key_msg = getch();
	if (key_msg == 89) {
		setfillcolor(s1->getFillColor());
		setcolor(s1->getBorderColor());
		int mouse_x{ 0 }, mouse_y{ 0 };
		int mouse_x_change{ 0 }, mouse_y_change{ 0 };
		for (; is_run(); delay_fps(60)) {
			mouse_msg msg = { 0 };
			bool downflag{ false };
			bool upflag{ false };
			while (mousemsg()) {
				msg = getmouse();
			}

			if (msg.is_move()) {
				cleardevice();
				line(msg.x, msg.y, msg.x + 20, msg.y);
			}
			if (msg.is_down() && (!downflag)) {
				outtextxy(30, 30, "已确定其中一个端点");
				mousepos(&mouse_x, &mouse_y);
				downflag = !downflag;
			}
			if (msg.is_up()) {
				cleardevice();
				mousepos(&mouse_x_change, &mouse_y_change);
				if(s1){
				dynamic_cast<Line*>(s1)->setLinePoint(Point(mouse_x, mouse_y), Point(mouse_x_change, mouse_y_change));
				line(dynamic_cast<Line*>(s1)->getLinePoint()[0].getPoint_X(), dynamic_cast<Line*>(s1)->getLinePoint()[0].getPoint_Y(), dynamic_cast<Line*>(s1)->getLinePoint()[1].getPoint_X(), dynamic_cast<Line*>(s1)->getLinePoint()[1].getPoint_Y());
				}
				setfont(30, 0, "楷体");
				outtextxy(30, 30, "绘画完成！继续画请按Y，返回菜单请按M，退出请按其他任意键");
				xyprintf(30, 200, "当前一共画了%d条线", getCountofLine());
				upflag = !upflag;
				int key_msg = getch();
				if (key_msg == 89) {
					CountofLine++;
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
Line::Line(Line& l1) {
	this->p1 = l1.p1;
	this->p2 = l1.p2;
}
void Line::Write(ofstream& out) {

}