#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <3ds.h>
#include <citro2d.h>

namespace RSGL{
    int init();
    int Quit();
    int nextFrame();

    struct rect{int x,y; int length, width;};
    struct circle { int x, y; int radius; };
    struct triangle { int x, y; int length, width; };
    struct color { int r, g, b; };

    int prev_pressed, prev_held;
    C3D_RenderTarget* topScreen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    C3D_RenderTarget* bottomScreen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_RIGHT);
    

    bool isPressed(int key) { return prev_pressed == key; }
    bool isHeld(int key) { return prev_pressed == key; }
    u32 background_color;

    int setBackground(color c) {
        background_color = C2D_Color32(c.r, c.g, c.b, 0xFF);
        return 1;
    }


    int drawRect(C3D_RenderTarget* Screen, rect r, color c, bool solid=true) {
        u32 colour = C2D_Color32(c.r, c.g, c.b, 0xFF);
        if (solid) {
            C2D_DrawRectSolid(r.x, r.y, 0, r.width, r.length, colour);
        }
        else {
            C2D_DrawLine(r.x, r.y, colour, (r.x + r.width) + 2, r.y, colour, 3, 1); //going upper RIGHT SIDE
            C2D_DrawLine((r.x + r.width) + 2, r.y, colour, (r.x + r.width) + 2, (r.y + r.length) + 2, colour, 3, 1); //going down RIGHT SIDE
            C2D_DrawLine((r.x + r.width) + 2, (r.y + r.length) + 2, colour, r.x , (r.y + r.length) + 2, colour, 3, 1); //going downer LEFT SIDE
            C2D_DrawLine(r.x, (r.y + r.length) + 2, colour, r.x, r.y, colour, 3, 1); //going UP RIGHT side
        }
        return 1;
    }
    int drawTriangle(C3D_RenderTarget* Screen, triangle t, color c, bool solid=true) {
        u32 colour = C2D_Color32(c.r, c.g, c.b, 0xFF);
        if (solid) {
            C2D_DrawTriangle(t.x, t.y, colour, 0,240, colour, 50, 240, colour, 0);
        }
        return 1;
    }

    int renderFrame(C3D_RenderTarget* Screen) {
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_TargetClear(Screen, background_color);
        C2D_SceneBegin(Screen);
        return 1;
    }
};


int RSGL::init(){
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
    consoleInit(GFX_BOTTOM, NULL);
    return 1;
}

struct Event{
  int type;
  int x,y;
  void CheckEvents();
};

void Event::CheckEvents(){
  	hidScanInput();
    
  	u32 pressed = hidKeysDown();
    u32 held = hidKeysHeld();
    RSGL::prev_pressed = pressed;
    RSGL::prev_held = held;
}

int RSGL::Quit(){
    C2D_Fini();
	C3D_Fini();
    gfxExit();
    return 0;
}

int RSGL::nextFrame() {
    C3D_FrameEnd(0);
    return 1;
}