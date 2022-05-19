//新增文件读入类，可以读文件，并把文件中所表示的图形画出。
//之所以没有写入的方法，是因为写入在每个具体图形类已经实现了，并且较为简单，比新增一个类更简单
#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <limits>
#include <graphics.h>
using std::string;
namespace fs = std::filesystem;
using std::ifstream;
class ReadFromFile {
private:
public:
	ReadFromFile() = default;
	void ReadFile();       //一个读文件并画出来的函数
	unsigned int stringToInteger(string);//将长字符串转换为长整数(由于ege中的color_t是unsigned int,y\用stoi函数会溢出）
};
class IDWrong {       //ID错误异常类（第一行不是1，2，3就会抛出)
private:
	string Wrong{ "Wrong ID!" };
public:
	string what() {
		return Wrong;
	}
};
class WrongColor {   //颜色错误异常类（颜色小于等于0或者大于color_t所表示的最大值就会派出）
private:
	string Wrong{ "Wrong Color!" };
public:
	string what() {
		return Wrong;
	}
};
class minusNumber {
private:
	string Wrong{ "Minus Number!" };
public:
		string what() {
		return what();
	}
};