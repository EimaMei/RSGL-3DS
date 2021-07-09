#include "3ds.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	RSGL::setBackground({255, 255, 255});
	RSGL::enableConsole(rsgl::bottomScreen);
	std::cout << "Hello, world, from the 3DS!\n";
	while (aptMainLoop()) {
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)) { break; } 
		if (RSGL::isHeld(KEY_A)) { std::cout << "Rucka rucka!\n"; } 

		RSGL::renderFrame(RSGL::topScreen);

		RSGL::drawRect({20, 20, 50, 50}, {255,0,0});
		RSGL::drawCircle({80, 100, 25}, {0,0,0}, false)

		RSGL::nextFrame();
	}

	RSGL::Quit();
	return 0;
}