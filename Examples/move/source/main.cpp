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
		if (RSGL::isHeld(KEY_DRIGHT)){r.x++;}
        if (RSGL::isHeld(KEY_DLEFT)){r.x--;}
		RSGL::renderFrame(RSGL::topScreen);
		RSGL::drawRect({200,100,25,25},{0,0,0},false);
        RSGL::drawRect(r,c);
		RSGL::nextFrame();
	}
	RSGL::Quit();
}