#include "Controller.h"
#include <graphics.h>
Controller::Controller() = default;

Controller::~Controller() = default;
void Controller::init() {
    initgraph(-1, -1);
    ege_enable_aa(true);
    setbkcolor(0xf2eada);
    setcaption("ª∂”≠ π”√ª≠∞Â1.0");
}
void Controller::end() {
    getch();
    cleardevice();
    closegraph();
}