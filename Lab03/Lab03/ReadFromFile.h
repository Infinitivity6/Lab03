//�����ļ������࣬���Զ��ļ��������ļ�������ʾ��ͼ�λ�����
//֮����û��д��ķ���������Ϊд����ÿ������ͼ�����Ѿ�ʵ���ˣ����ҽ�Ϊ�򵥣�������һ�������
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
	void ReadFile();       //һ�����ļ����������ĺ���
	unsigned int stringToInteger(string);//�����ַ���ת��Ϊ������(����ege�е�color_t��unsigned int,y\��stoi�����������
};
class IDWrong {       //ID�����쳣�ࣨ��һ�в���1��2��3�ͻ��׳�)
private:
	string Wrong{ "Wrong ID!" };
public:
	string what() {
		return Wrong;
	}
};
class WrongColor {   //��ɫ�����쳣�ࣨ��ɫС�ڵ���0���ߴ���color_t����ʾ�����ֵ�ͻ��ɳ���
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