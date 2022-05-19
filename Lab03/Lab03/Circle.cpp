#include "Circle.h"
#include "Menu.h"
int Circle::CountofCircle = 0;
Circle::Circle() :Circle(Point(0, 0), 0, BLACK, WHITE, 0) { CountofCircle++; };
Circle::Circle(Point p1, int r, color_t c1, color_t c2, bool b1) {
	this->p1 = p1;
	radius = r;
	borderColor = c1;
	fillColor = c2;
	isFilled = b1;
}
int Circle::getCountofCircle() {
	return CountofCircle;
}
void Circle::setCirclePoint(Point p1) {
	this->p1 = p1;
}
void Circle::setCircleRadius(int r) {
	radius = r;
}
int Circle::getRadius()const {
	return radius;
}
Point Circle::getCirclePoint() const {
	return p1;
}
void Circle::Draw(Shape* s1) {
	cleardevice();
	setfont(50, 0, "����");
	outtextxy(30, 30, "��Y����ʼ����");
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
				dynamic_cast<Circle*>(s1)->setCirclePoint(Point(msg.x, msg.y));
				if(s1){
				circle(dynamic_cast<Circle*>(s1)->getCirclePoint().getPoint_X(), dynamic_cast<Circle*>(s1)->getCirclePoint().getPoint_Y(), 15);
				}
				}
			if (msg.is_down() && (!downflag)) {
				setfont(30, 0, "����");
				outtextxy(30, 30, "��ȷ��Բ��");
				mousepos(&mouse_x, &mouse_y);
				this->setCirclePoint(Point(mouse_x, mouse_y));
				downflag = !downflag;
			}
			if (msg.is_up() && (!upflag)) {
				cleardevice();
				mousepos(&mouse_x_change, &mouse_y_change);
				x = mouse_x_change - mouse_x;
				y = mouse_y_change - mouse_y;
				int radius = static_cast<int>(sqrt(x * x + y * y));
				this->setCircleRadius(radius);
				circle(mouse_x, mouse_y, radius);
				if(s1){
				floodfill(mouse_x, mouse_y, s1->getBorderColor());
				}
				setfont(30, 0, "����");
				outtextxy(30, 30, "�滭��ɣ�������Բ�밴Y���������ػ��밴M���˳��밴������");
				xyprintf(30, 200, "��ǰһ������%d��Բ��", getCountofCircle());
				Write(output);
				upflag = !upflag;
				int key_msg = getch();
				if (key_msg == 89) {
					CountofCircle++;
					Draw(s1);
				}
				else if (key_msg == 77) {
					Menu menu;
					menu.Begin();
				}
				else {
					closegraph();
				}

			}
		}

		/*  cleardevice();                                   //֮ǰ�������ô���
		bool clickflag{ false };
		bool downflag{ false };
		getmouse();
			int one_x, one_y;
			mousepos(&one_x, &one_y);
			int one_x1 = one_x, one_y1 = one_y;
			c1.setCirclePoint(Point(one_x, one_y));
			outtextxy(30, 30, "��ȷ��Բ�ģ�������ƶ������ȷ���뾶,�ڼ������Ҫ�ɿ�");
			delay(5000);
			cleardevice();
			setfillcolor(c1.fillColor);
			setBordercolor(c1.BorderColor);
			mousepos(&one_x, &one_y);
			int x = one_x - one_x1, y = one_y - one_y1;
			c1.setCircleRadius(static_cast<int>(sqrt(x*x+y*y)));
			circle(c1.getCirclePoint().getPoint_X(), c1.getCirclePoint().getPoint_Y(), radius);*/
	}
	else { Draw(s1); }

}
Circle::Circle(Circle& c1) {
	this->radius = c1.radius;
	this->p1 = c1.p1;
}
void Circle::Write(ofstream& out) {
	out << "1" << std::endl;
	out << this->getCirclePoint().getPoint_X() << " " << this->getCirclePoint().getPoint_Y() << " "
		<< this->getRadius() << std::endl;
	out << this->getFillColor() <<" "<<this->getBorderColor()<<" "<<this->hasFilled() << std::endl;
}
Circle::~Circle() {
	CountofCircle--;
}