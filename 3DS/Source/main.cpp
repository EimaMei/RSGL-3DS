#define __3ds__
#include "RSGL.hpp"

int main(int argc, char* argv[]) {
	RSGL::init();
    Event e;
	printf("Hello, world!\n");
	while (true)
	{
		e.CheckEvents();
		if (RSGL::isPressed(KEY_START)) { break; } 
		if (RSGL::isPressed(KEY_A)) { printf("Rucka rucka!\n"); } 
	}

	RSGL::Quit();
	return 0;
}
