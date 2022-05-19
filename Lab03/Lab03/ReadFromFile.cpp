#include "ReadFromFile.h"
void ReadFromFile::ReadFile() {
	fs::path p1{ "Data of Shapes.txt" };
	try {
		if (!fs::exists(p1)) {
			throw p1;
		}
	}
	catch (fs::path) {
		cleardevice();
		outtextxy(30, 120, "无文件可读");
	}
	if (fs::exists(p1)) {
		cleardevice();
		ifstream in{ p1,std::ios::in };
		while (!in.eof()) {
			string l1, l2, l3;
			getline(in, l1);
			getline(in, l2);
			getline(in, l3);
			try {
			if (l1 == "1") {
				string x, y, radius, fillColor, borderColor, isFilled;
				size_t pos_21 = l2.find(" ", 0);           //pos_21表示第二行第一个空格的索引，以此类推
				size_t pos_22 = l2.find(" ", pos_21 + 1);
				size_t pos_23 = l3.find(" ", pos_22 + 1);
				x = l2.substr(0, pos_21);                 //x此时为一个string对象，只需要调用stoi函数就可转换为不超过int的整数
				y = l2.substr(pos_21 + 1, pos_22 - pos_21 - 1);
				radius = l2.substr(pos_22 + 1);
				size_t pos_31 = l3.find(" ", 0);
				size_t pos_32 = l3.find(" ", pos_31 + 1);
				size_t pos_33 = l3.find(" ", pos_32 + 1);
				fillColor = l3.substr(0, pos_31);
				borderColor = l3.substr(pos_31 + 1, pos_32 - pos_31 - 1);
				isFilled = l3.substr(pos_32 + 1);
				unsigned int borderColor_ = stringToInteger(borderColor);//fillColor_才是真正的颜色数值
				unsigned int fillColor_ = stringToInteger(fillColor);
				ege::setfillcolor(fillColor_);
				ege::setcolor(borderColor_);
				ege::circle(stoi(x), stoi(y), stoi(radius));
				ege::floodfill(stoi(x), stoi(y), borderColor_);
			}
			else if (l1 == "2") {
				string x1, y1, x2, y2, fillColor, borderColor, isFilled;
				size_t pos_21 = l2.find(" ", 0);
				size_t pos_22 = l2.find(" ", pos_21 + 1);
				size_t pos_23 = l2.find(" ", pos_22 + 1);
				size_t pos_24 = l2.find(" ", pos_23 + 1);
				x1 = l2.substr(0, pos_21);
				y1 = l2.substr(pos_21 + 1, pos_22 - pos_21 - 1);
				x2 = l2.substr(pos_22 + 1, pos_23 - pos_22 - 1);
				y2 = l2.substr(pos_23 + 1);
				size_t pos_31 = l3.find(" ", 0);
				size_t pos_32 = l3.find(" ", pos_31 + 1);
				size_t pos_33 = l3.find(" ", pos_32 + 1);
				fillColor = l3.substr(0, pos_31);
				borderColor = l3.substr(pos_31 + 1, pos_32 - pos_31 - 1);
				isFilled = l3.substr(pos_32 + 1);
				unsigned int borderColor_ = stringToInteger(borderColor);
				unsigned int fillColor_ = stringToInteger(fillColor);
				ege::setfillcolor(fillColor_);
				ege::setcolor(borderColor_);
				rectangle(stoi(x1), stoi(y1), stoi(x2), stoi(y2));
				ege::floodfill((stoi((x1 + x2)) / 2), (stoi((y1 + y2)) / 2), borderColor_);
			}
			else if (l1 == "3") {
				string x1, y1, x2, y2, x3, y3, fillColor, borderColor, isFilled;
				size_t pos_21 = l2.find(" ", 0);
				size_t pos_22 = l2.find(" ", pos_21 + 1);
				size_t pos_23 = l2.find(" ", pos_22 + 1);
				size_t pos_24 = l2.find(" ", pos_23 + 1);
				size_t pos_25 = l2.find(" ", pos_24 + 1);
				size_t pos_26 = l2.find(" ", pos_25 + 1);
				x1 = l2.substr(0, pos_21);
				y1 = l2.substr(pos_21 + 1, pos_22 - pos_21 - 1);
				x2 = l2.substr(pos_22 + 1, pos_23 - pos_22 - 1);
				y2 = l2.substr(pos_23 + 1, pos_24 - pos_23 - 1);
				x3 = l2.substr(pos_24 + 1, pos_25 - pos_24 - 1);
				y3 = l2.substr(pos_25 + 1);
				size_t pos_31 = l3.find(" ", 0);
				size_t pos_32 = l3.find(" ", pos_31 + 1);
				size_t pos_33 = l3.find(" ", pos_32 + 1);
				fillColor = l3.substr(0, pos_31);
				borderColor = l3.substr(pos_31 + 1, pos_32 - pos_31 - 1);
				isFilled = l3.substr(pos_32 + 1);
				unsigned int borderColor_ = stringToInteger(borderColor);
				unsigned int fillColor_ = stringToInteger(fillColor);
				ege::setcolor(borderColor_);
				ege::setfillcolor(fillColor_);
				ege::line(stoi(x1), stoi(y1), stoi(x2), stoi(y2));
				ege::line(stoi(x1), stoi(y1), stoi(x3), stoi(y3));
				ege::line(stoi(x2), stoi(y2), stoi(x3), stoi(y3));
				ege::floodfill((stoi((x1 + x2 + x3)) / 3), (stoi((y1 + y2 + y3)) / 3), borderColor_);
			}
			else if (atoi(l1.c_str())> 3||atoi(l1.c_str())<=0) {
				throw IDWrong();
			}
			}
			catch (IDWrong& e) {
				setcolor(RED);
				outtextxy(30, 30, "文件读取出错！");
				outtextxy(30, 120, e.what().c_str());
				getch();
			}


		}
	}
}
	unsigned int ReadFromFile::stringToInteger(string str) {
		unsigned int result = 0;
		for (unsigned int i = 0; i < str.size(); i++) {
			result = result * 10 + str[i] - '0';
		}
		return result;
	}