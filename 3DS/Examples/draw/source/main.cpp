#include "3ds.hpp"
#include <vector>
#include <iostream>
bool running = true;

std::vector<RSGL::circle> dots = {};

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::setBackground({255, 255, 255});
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		RSGL::renderFrame(RSGL::bottomScreen);
        if (RSGL::isHeld(KEY_TOUCH)){dots.insert(dots.end(),{RSGL::touch_x,RSGL::touch_y, 25});}
        for (int i = 0; i < dots.size(); i++){
            RSGL::drawCircle({dots[i].x,dots[i].y,25},{0,0,0});
        }
		RSGL::nextFrame();

	}
	RSGL::Quit();
}