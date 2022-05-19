//shape类，母类，所有具体形状类的继承它；包含两个颜色(borderColor还有fillColor），一个是否填充的布尔量
//以及相应的getter，setter
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
	color_t getBorderColor()const;          //四个返回函数，分别返回边界/填充颜色，是否填充以及计数cnt（对象存活数量）
	color_t getFillColor()const;
	bool hasFilled()const;
	void setisFilled(bool b1);           //三个setcolor/填充的函数，一个Draw（）方法
	void setBorderColor(color_t);
	void setFillColor(color_t);
	virtual void Draw(Shape*) = 0;
	virtual void Write(ofstream&)=0;
};
