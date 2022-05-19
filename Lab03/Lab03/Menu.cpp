#include "Menu.h"
Menu::Menu() = default;
Menu::~Menu() = default;
void Menu::Begin() {                //�Ƿ�ͼ������ѡ����룬���Ǽ������룬�Ժ�İ汾���ܻ�������
	cleardevice();
	setfont(50, 0, "����");
	setcolor(BLACK);
	outtextxy(30, 30, "��ʼ��ͼ��");
	setfillcolor(0xd3d7d4);
	setfont(30, 0, "����");
	outtextxy(30, 100, "Yes ");
	outtextxy(100, 100, "�밴��дY");
	outtextxy(30, 200, "No  ");
	outtextxy(100, 200, "�밴��дN");
	outtextxy(30, 300, "Quit");
	outtextxy(100, 300, "�밴���������");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 78) {                   //����дN�رջ������壨����δ�رգ�
		closegraph();
	}
	else if (key_msg == 89) {             //����дY����ѡ��ʲô
		ChooseShape();
	}
	else {
		Begin();                          //������������
	}
}
void Menu::ChooseShape() {
	cleardevice();
	setfont(50, 0, "����");
	setcolor(BLACK);
	outtextxy(30, 30, "��ʲô��");
	setfillcolor(0xd3d7d4);
	setfont(30, 0, "����");
	outtextxy(30, 100, "Բ   ");
	outtextxy(150, 100, "����дC");
	outtextxy(30, 150, "������");
	outtextxy(150, 150, "����дT");
	outtextxy(30, 200, "����  ");
	outtextxy(150, 200, "����дR");
	outtextxy(30, 250, "ֱ��  ");
	outtextxy(150, 250, "����дL");
	outtextxy(30, 300, "�˳�  ");
	outtextxy(150, 300, "�����������");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 67) {             //�������дC  ����һ��Բ����
		c1 = new Circle;
		ChooseBorderColor(c1);
	}
	else if (key_msg == 84) {        //�������дT  ����һ�������ζ���
		t1 = new Triangle;
		ChooseBorderColor(t1);
	}
	else if (key_msg == 82) {           //�������дR  ����һ�����ζ���
		r1 = new myRectangle;
		ChooseBorderColor(r1);
	}
	else if (key_msg == 76) {          //�������дL  ����һ��ֱ�߶���
		l1 = new Line;
		ChooseBorderColor(l1);
	}
	else {
		ChooseShape();              //��������ѡ��һ�λ�ʲô
	}

}


void Menu::Continue() {

}
void Menu::Quit() {

}
void Menu::ChooseBorderColor(Shape * s1) {
	cleardevice();
	setfont(50, 0, "����");
	outtextxy(30, 30, "��ѡ��������ɫ");
	setfont(30, 0, "����");
	outtextxy(30, 100, "��ɫ");
	outtextxy(120, 100, "����дB");
	outtextxy(30, 150, "��ɫ");
	outtextxy(120, 150, "����дR");
	outtextxy(30, 200, "��ɫ");
	outtextxy(120, 200, "����дL");
	outtextxy(30, 250, "��ɫ");
	outtextxy(120, 250, "����дG");
	outtextxy(30, 300, "��ɫ");
	outtextxy(120, 300, "����дW");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 66) {                      //�������дB��������ɫΪBLACK
		s1->setBorderColor(BLACK);
		ChooseFillColor(s1);
	}
	else if (key_msg == 82) {                //�������дR��������ɫΪRED
		s1->setBorderColor(RED);
		ChooseFillColor(s1);
	}
	else if (key_msg == 76) {                //�������дL��������ɫΪBLUE
		s1->setBorderColor(BLUE);
		ChooseFillColor(s1);
	}
	else if (key_msg == 71) {                //�������дG��������ɫΪGREEN
		s1->setBorderColor(GREEN);
		ChooseFillColor(s1);
	}
	else if (key_msg == 87) {                //�������дW��������ɫΪWHITE
		s1->setBorderColor(WHITE);
		ChooseFillColor(s1);
	}
	else {
		ChooseBorderColor(s1);                //��������ѡ��������ɫ
	}
}
void Menu::ChooseFillColor(Shape * s1) {
	cleardevice();
	setfont(50, 0, "����");
	outtextxy(30, 30, "��ѡ�������ɫ");
	setfont(30, 0, "����");
	outtextxy(30, 100, "��ɫ");
	outtextxy(120, 100, "����дB");
	outtextxy(30, 150, "��ɫ");
	outtextxy(120, 150, "����дR");
	outtextxy(30, 200, "��ɫ");
	outtextxy(120, 200, "����дL");
	outtextxy(30, 250, "��ɫ");
	outtextxy(120, 250, "����дG");
	outtextxy(30, 300, "��ɫ");
	outtextxy(120, 300, "����дW");
	outtextxy(30, 400, "����");
	outtextxy(120, 400, "����дN");
	int key_msg;
	key_msg = getch();
	delay(500);
	if (key_msg == 66) {                   //�������дB�������ɫΪBLACK
		s1->setFillColor(BLACK);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 82) {             //�������дR�������ɫΪRed
		s1->setFillColor(RED);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 76) {             //�������дL�������ɫΪBLUE
		s1->setFillColor(BLUE);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 71) {             //�������дG�������ɫΪGREEN
		s1->setFillColor(GREEN);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 87) {             //�������дW�������ɫΪWHITE
		s1->setFillColor(WHITE);
		s1->setisFilled(1);
		Draw(s1);
	}
	else if (key_msg == 78) {            //�������дN��������ɫΪ��������ɫ��
		s1->setisFilled(0);
		s1->setFillColor(0xf2eada);
		Draw(s1);
	}
	else {
		ChooseFillColor(s1);            //��������ѡ�������ɫ
	}
}
void Menu::Draw(Shape * s1) {            //�жϵ���Ҫ��ʲô��ָ�����Ҫ���ĺ���
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
	outtextxy(30, 100, "��Ҫ��ȡ�ļ���");
	outtextxy(30, 150, "��,����дY");
	outtextxy(30, 200, "����ȡֱ������������дN");
	int key_msg = getch();
	delay(300);
	if (key_msg == 78) {                   //����дNֱ�ӿ�ʼ��������ȡ�ļ�
		Begin();
	}
	else if (key_msg == 89) {             //����дY���ļ�
		f1.ReadFile();
		outtextxy(30, 30, "��ȡ�ɹ����ϴλ���ͼ������");
		outtextxy(30, 120, "���������밴Y,�˳��밴������");
		int key_msg = getch();
		if (key_msg == 89) {
			Begin();
		}
		else if(key_msg==78) {
			closegraph();
		}
	}
	else {
		ReadFile();                        //������������
	}
}



vector<Shape*> Menu::getShapes()const {
	return Shapes;
}


