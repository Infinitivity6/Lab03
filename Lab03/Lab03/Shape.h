//shape�࣬ĸ�࣬���о�����״��ļ̳���������������ɫ(borderColor����fillColor����һ���Ƿ����Ĳ�����
//�Լ���Ӧ��getter��setter
#pragma once
#include <graphics.h>
#include <filesystem>
#include <fstream>
using std::ifstream;
using std::ofstream;
namespace fs = std::filesystem;
class Shape {
protected:
	color_t borderColor{ 0x000000 };
	color_t fillColor{ 0xf2eada };
	bool isFilled{ false };
	ofstream output{"Data of Shapes.txt",std::ios::app};
public:
	Shape();
	~Shape();
	color_t getBorderColor()const;          //�ĸ����غ������ֱ𷵻ر߽�/�����ɫ���Ƿ�����Լ�����cnt��������������
	color_t getFillColor()const;
	bool hasFilled()const;
	void setisFilled(bool b1);           //����setcolor/���ĺ�����һ��Draw��������
	void setBorderColor(color_t);
	void setFillColor(color_t);
	virtual void Draw(Shape*) = 0;
	virtual void Write(ofstream&)=0;
};
