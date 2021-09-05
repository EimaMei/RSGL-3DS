#include "3ds.hpp"
#include <iostream>
bool running = true;

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::window topScreen = RSGL::createWindow(TOP_SCREEN, 0,0,SCREEN_WIDTH,SCREEN_LENGTH, {255,255,255});
	RSGL::window bottomScreen = RSGL::createWindow(BOTTOM_SCREEN, 0,0,BOTTOM_SCREEN_WIDTH,BOTTOM_SCREEN_LENGTH, {255,255,255});
	RSGL::color c = {255,0,0};
    RSGL::circle cir = {80,100,25};
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		RSGL::InitWindow(topScreen);
		RSGL::drawCircle({125,100,50},{0,0,0});
		RSGL::RenderWindow(topScreen);

		RSGL::InitWindow(bottomScreen);
        RSGL::drawCircle(cir,c, false);
		RSGL::RenderWindow(bottomScreen);
	}
	RSGL::Quit();
}