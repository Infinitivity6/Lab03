//control类，只包含初始化和关闭环境的方法，无数据成员
#pragma once
class Controller {
private:
public:
	Controller();
	void init();
	void end();
	~Controller();
};