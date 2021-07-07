#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#define RSGLRGBTOHEX(r, g, b) ((r << 16) + (g << 8) + b)

namespace RSGL{
    int init();
    int Quit();
    //int end();
    //std::string conversion();d

    struct rect{int x,y; int length, width;};
    struct circle { int x, y; int radius; };
    struct color { int r, g, b, a; };

    int prev_buttonorsomethinglikethatiamnot100percentsuredontblameme;
    

    bool isPressed(int key) {
        return prev_buttonorsomethinglikethatiamnot100percentsuredontblameme == key;
    }
};


int RSGL::init(){
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);
    return 1;
}

struct Event{
  int type;
  int x,y;
  void CheckEvents();
};

void Event::CheckEvents(){
    gspWaitForVBlank();
  	gfxSwapBuffers();
  	hidScanInput();

  	u32 pressed = hidKeysDown();
    u32 held = hidKeysHeld();
    RSGL::prev_buttonorsomethinglikethatiamnot100percentsuredontblameme = pressed;
}

int RSGL::Quit(){
    gfxExit();
    return 0;
}
