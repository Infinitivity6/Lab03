#include "Menu.h"
Menu::Menu() = default;
Menu::~Menu() = default;
void Menu::Begin() {                //是否画图？键盘选择进入，都是键盘输入，以后的版本可能会采用鼠标
	cleardevice();
	setfont(50, 0, "楷体");
	setcolor(BLACK);
	outtextxy(30, 30, "开始画图？");
	setfillcolor(0xd3d7d4);
	setfont(30, 0, "楷体");
	outtextxy(30, 100, "Yes ");
	outtextxy(100, 100, "请按大写Y");
	outtextxy(30, 200, "No  ");
	outtextxy(100, 200, "请按大写N");
	outtextxy(30, 300, "Quit");
	outtextxy(100, 300, "请按其他任意键");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 78) {                   //按大写N关闭画板的面板（进程未关闭）
		closegraph();
	}
	else if (key_msg == 89) {             //按大写Y继续选择画什么
		ChooseShape();
	}
	else {
		Begin();                          //否则重新输入
	}
}
void Menu::ChooseShape() {
	cleardevice();
	setfont(50, 0, "楷体");
	setcolor(BLACK);
	outtextxy(30, 30, "画什么？");
	setfillcolor(0xd3d7d4);
	setfont(30, 0, "楷体");
	outtextxy(30, 100, "圆   ");
	outtextxy(150, 100, "按大写C");
	outtextxy(30, 150, "三角形");
	outtextxy(150, 150, "按大写T");
	outtextxy(30, 200, "矩形  ");
	outtextxy(150, 200, "按大写R");
	outtextxy(30, 250, "直线  ");
	outtextxy(150, 250, "按大写L");
	outtextxy(30, 300, "退出  ");
	outtextxy(150, 300, "按其他任意键");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 67) {             //如果按大写C  创建一个圆对象
		c1 = new Circle;
		ChooseBorderColor(c1);
	}
	else if (key_msg == 84) {        //如果按大写T  创建一个三角形对象
		t1 = new Triangle;
		ChooseBorderColor(t1);
	}
	else if (key_msg == 82) {           //如果按大写R  创建一个矩形对象
		r1 = new myRectangle;
		ChooseBorderColor(r1);
	}
	else if (key_msg == 76) {          //如果按大写L  创建一个直线对象
		l1 = new Line;
		ChooseBorderColor(l1);
	}
	else {
		ChooseShape();              //否则重新选择一次画什么
	}

}


void Menu::Continue() {

}
void Menu::Quit() {

}
void Menu::ChooseBorderColor(Shape * s1) {
	cleardevice();
	setfont(50, 0, "楷体");
	outtextxy(30, 30, "请选择线条颜色");
	setfont(30, 0, "楷体");
	outtextxy(30, 100, "黑色");
	outtextxy(120, 100, "按大写B");
	outtextxy(30, 150, "红色");
	outtextxy(120, 150, "按大写R");
	outtextxy(30, 200, "蓝色");
	outtextxy(120, 200, "按大写L");
	outtextxy(30, 250, "绿色");
	outtextxy(120, 250, "按大写G");
	outtextxy(30, 300, "白色");
	outtextxy(120, 300, "按大写W");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 66) {                      //如果按大写B，线条颜色为BLACK
		s1->setBorderColor(BLACK);
		ChooseFillColor(s1);
	}
	else if (key_msg == 82) {                //如果按大写R，线条颜色为RED
		s1->setBorderColor(RED);
		ChooseFillColor(s1);
	}
	else if (key_msg == 76) {                //如果按大写L，线条颜色为BLUE
		s1->setBorderColor(BLUE);
		ChooseFillColor(s1);
	}
	else if (key_msg == 71) {                //如果按大写G，线条颜色为GREEN
		s1->setBorderColor(GREEN);
		ChooseFillColor(s1);
	}
	else if (key_msg == 87) {                //如果按大写W，线条颜色为WHITE
		s1->setBorderColor(WHITE);
		ChooseFillColor(s1);
	}
	else {
		ChooseBorderColor(s1);                //否则重新选择线条颜色
	}
}
void Menu::ChooseFillColor(Shape * s1) {
	cleardevice();
	setfont(50, 0, "楷体");
	outtextxy(30, 30, "请选择填充颜色");
	setfont(30, 0, "楷体");
	outtextxy(30, 100, "黑色");
	outtextxy(120, 100, "按大写B");
	outtextxy(30, 150, "红色");
	outtextxy(120, 150, "按大写R");
	outtextxy(30, 200, "蓝色");
	outtextxy(120, 200, "按大写L");
	outtextxy(30, 250, "绿色");
	outtextxy(120, 250, "按大写G");
	outtextxy(30, 300, "白色");
	outtextxy(120, 300, "按大写W");
	outtextxy(30, 400, "不填");
	outtextxy(120, 400, "按大写N");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 66) {                   //如果按大写B，填充颜色为BLACK
		s1->setFillColor(BLACK);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 82) {             //如果按大写R，填充颜色为Red
		s1->setFillColor(RED);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 76) {             //如果按大写L，填充颜色为BLUE
		s1->setFillColor(BLUE);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 71) {             //如果按大写G，填充颜色为GREEN
		s1->setFillColor(GREEN);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 87) {             //如果按大写W，填充颜色为WHITE
		s1->setFillColor(WHITE);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 78) {            //如果按大写N，则不填（填充色为本来背景色）
		s1->setisFilled(0);
		s1->setFillColor(0xf2eada);
		Draw(s1);
	}
	else {
		ChooseFillColor(s1);            //否则重新选择填充颜色
	}
}
void Menu::Draw(Shape * s1) {            //判断到底要画什么并指向具体要画的函数
	cleardevice();
	if (s1 == c1) {
		s1->Draw(s1);
	}
	else if (s1 == t1) {
		s1->Draw(s1);
	}
	else if (s1 == r1) {
		s1->Draw(s1);
	}
	else if (s1 == l1) {
		s1->Draw(s1);
	}
}
void Menu::ReadFile() {
	outtextxy(30, 100, "你要读取文件吗？");
	outtextxy(30, 150, "是,按大写Y");
	outtextxy(30, 200, "不读取直接作画，按大写N");
	int key_msg = getch();
	delay(300);
	if (key_msg == 78) {                   //按大写N直接开始作画不读取文件
		Begin();
	}
	else if (key_msg == 89) {             //按大写Y读文件
		f1.ReadFile();
		outtextxy(30, 30, "读取成功，上次画的图形如下");
		outtextxy(30, 120, "继续作画请按Y,退出请按其他键");
		int key_msg = getch();
		if (key_msg == 89) {
			Begin();
		}
		else if(key_msg==78) {
			closegraph();
		}
	}
	else {
		ReadFile();                        //否则重新输入
	}
}



vector<Shape*> Menu::getShapes()const {
	return Shapes;
}


