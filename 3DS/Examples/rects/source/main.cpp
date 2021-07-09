#include "3ds.hpp"
#include <iostream>
bool running = true;

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::setBackground({255, 255, 255});
	RSGL::color c = {255,0,0};
    RSGL::rect r = {100,100,50,50};
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		RSGL::renderFrame(RSGL::topScreen);
		RSGL::drawRect({200,75,25,25},{0,0,0},false);
        RSGL::drawRect(r,c);
		RSGL::nextFrame();
	}
	RSGL::Quit();
}