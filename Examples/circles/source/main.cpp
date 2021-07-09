#include "3ds.hpp"
#include <iostream>
bool running = true;

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::setBackground({255, 255, 255});
	RSGL::color c = {255,0,0};
    RSGL::circle cir = {80,100,25};
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		RSGL::renderFrame(RSGL::topScreen);
		RSGL::drawCircle({125,100,50},{0,0,0});

		RSGL::renderFrame(RSGL::bottomScreen);
        RSGL::drawCircle(cir,c, false);

		RSGL::nextFrame();
	}
	RSGL::Quit();
}