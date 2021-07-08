#include "3ds.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	std::cout << "Hello, world!\n";
	RSGL::setBackground({255, 255, 255});
	while (aptMainLoop()) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)) { break; } 
		if (RSGL::isHeld(KEY_A)) { std::cout << "Rucka rucka!\n"; } 
		if (RSGL::isHeld(KEY_B)) { std::cout << "Sussy sus sus\n"; } 

		RSGL::renderFrame(RSGL::topScreen);

		RSGL::drawRect(RSGL::topScreen, {20, 20, 50, 50}, {255,0,0});
		RSGL::drawRect(RSGL::topScreen, {20, 100, 50, 50}, {0x40, 0xEA, 0x87}, false);

		RSGL::nextFrame();
	}

	RSGL::Quit();
	return 0;
}