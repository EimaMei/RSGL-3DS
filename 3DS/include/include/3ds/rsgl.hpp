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
    struct image {const char* file; RSGL::rect r;};
    struct color { int r, g, b; };

    int prev_pressed, prev_held, touch_x, touch_y;
    u32 background_color;
    C3D_RenderTarget* topScreen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    C3D_RenderTarget* bottomScreen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_RIGHT);
    

    bool isPressed(int key) { return prev_pressed == key; }
    bool isHeld(int key) { return prev_held == key; }

    int setBackground(color c) {
        background_color = C2D_Color32(c.r, c.g, c.b, 0xFF);
        return 1;
    }


    int drawRect(rect r, color col, bool solid=true) {
        u32 clr = C2D_Color32(col.r, col.g, col.b, 0xFF);
        
        if (solid) {
            C2D_DrawRectSolid(r.x, r.y, 0, r.width, r.length, clr);
        }
        else {
            C2D_DrawLine(r.x, r.y, clr, (r.x + r.width) + 3, r.y, clr, 3, 1); //going upper RIGHT SIDE
            C2D_DrawLine((r.x + r.width) + 3, r.y, clr, (r.x + r.width) + 3, (r.y + r.length) + 3, clr, 3, 1); //going down RIGHT SIDE
            C2D_DrawLine((r.x + r.width) + 3, (r.y + r.length) + 3, clr, r.x , (r.y + r.length) + 3, clr, 3, 1); //going downer LEFT SIDE
            C2D_DrawLine(r.x, (r.y + r.length) + 3, clr, r.x, r.y, clr, 3, 1); //going UP RIGHT side
        }
        return 1;
    }
    int drawTriangle(triangle t, color c, bool solid=true) {
        u32 colour = C2D_Color32(c.r, c.g, c.b, 0xFF);
        if (solid) {
            C2D_DrawTriangle(t.x, t.y, colour, 0,t.width, colour, 0, t.length, colour, 0);
        }
        return 1;
    }
    int drawCircle(circle c, color col, bool solid=true, bool shadow=false) {
        u32 clr = C2D_Color32(col.r, col.g, col.b, 0xFF);
        if (shadow) C2D_DrawCircleSolid(c.x, c.y, 0, c.radius+1, C2D_Color32(col.r, col.g, col.b, 60));
        C2D_DrawCircleSolid(c.x, c.y, 0, c.radius, clr);
        if (!solid) {
            C2D_DrawCircleSolid(c.x, c.y, 0, c.radius-3, background_color);
        }
        return 1;
    }

    int enableConsole(std::string arg) {
        if (arg == "Bottom") {consoleInit(GFX_BOTTOM, NULL);}
        if (arg == "Upper") {consoleInit(GFX_TOP, NULL);}
        else {std::cout << "No console";}
        return 1;
    }

    /*int drawImage(RSGL::image image, color c) {
        static C2D_SpriteSheet spriteSheet;
        size_t numImages = C2D_SpriteSheetCount(spriteSheet);
        C2D_SpriteFromSheet(&sprite->spr, spriteSheet,  0);
		C2D_SpriteSetCenter(&sprite->spr, 0.5f, 0.5f);
		C2D_SpriteSetPos(&sprite->spr, image.x  );
    }*/
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
    return 1;
}


struct Event{
  void CheckEvents();
};

void Event::CheckEvents(){
  	hidScanInput();
    touchPosition touch;
    hidTouchRead(&touch);
    
  	u32 pressed = hidKeysDown();
    u32 held = hidKeysHeld();
    RSGL::prev_pressed = pressed;
    RSGL::prev_held = held;
    RSGL::touch_x = touch.px;
    RSGL::touch_y = touch.py;
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