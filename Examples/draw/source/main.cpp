#include "3ds.hpp"
#include <vector>
#include <iostream>
bool running = true;

std::vector<RSGL::circle> dots = {};

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::window bottomScreen = RSGL::createWindow(BOTTOM_SCREEN, 0,0,BOTTOM_SCREEN_WIDTH,BOTTOM_SCREEN_LENGTH, {255,255,255});
	while (running) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)){
			running = false;
		}
		
		RSGL::InitWindow(bottomScreen);
        if (RSGL::isPressed(RK_Touch)){dots.insert(dots.end(),{e.x,e.y, 25});}
        for (int i = 0; i < dots.size(); i++){
            RSGL::drawCircle({dots[i].x,dots[i].y,25},{0,0,0});
        }
		RSGL::RenderWindow(bottomScreen);

	}
	RSGL::Quit();
}