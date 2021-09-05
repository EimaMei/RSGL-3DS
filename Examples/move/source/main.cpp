#include "3ds.hpp"
#include <iostream>
bool running = true;

int main(int argc, char* argv[]) {
	RSGL::init();
	RSGL::window topScreen = RSGL::createWindow(TOP_SCREEN, 0,0,SCREEN_WIDTH,SCREEN_LENGTH, {255,255,255});
    Event e;
	RSGL::color c = {255,0,0};
    RSGL::rect r = {100,100,50,50};
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		if (RSGL::isPressed(RK_Right)){r.x++;}
        if (RSGL::isPressed(RK_Left)){r.x--;}
		RSGL::InitWindow(topScreen);
		RSGL::drawRect({200,200,25,25},{0,0,0},false);
        RSGL::drawRect(r,c);
		RSGL::RenderWindow(topScreen);
	}
	RSGL::Quit();
}