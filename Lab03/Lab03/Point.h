//һ����������࣬����x��y���Լ����ã���ȡx��y����ÿ��ͼ����ıر���Ƕ����

#pragma once
class Point {
private:
	int x{ 0 };
	int y{ 0 };
public:
	Point();
	Point(int, int);
	void setPoint(int, int);
	int getPoint_X() const;
	int getPoint_Y() const;
};