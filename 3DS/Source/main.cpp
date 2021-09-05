#include "3ds.hpp"
#include <iostream> 

bool running = true;

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::window topScreen = RSGL::createWindow(TOP_SCREEN, 0,0,SCREEN_WIDTH,SCREEN_LENGTH, {255,255,255});
	RSGL::enableConsole(BOTTOM_SCREEN);
	std::cout << "Thank you for using RSGL 3DS! We hope that it'll be easy using this library.";
	while (aptMainLoop()) {
		e.CheckEvents();
		if (RSGL::isClicked(KEY_START)){
			running = false;
		}
		RSGL::InitWindow(topScreen);
        RSGL::drawRect({25,25,100,100},{255,0,0});
		RSGL::RenderWindow(topScreen);
	}
	RSGL::Quit();
}
