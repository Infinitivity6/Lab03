#include "graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Controller.h"
#include "myRectangle.h"
#include "Triangle.h"
#include "Point.h"
#include "Menu.h"
int main() {
    Controller controll;
    controll.init();
    Menu menu;
    menu.ReadFile();
    controll.end();
    return 0;
}