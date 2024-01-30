#include <ogcsys.h>
#include <wiiuse/wpad.h>
#include <wiisprite.h>
#include <core

// Function to create and draw a square
wsp::Rectangle* createSquare(float x, float y, float size, u8 red, u8 green, u8 blue, u8 alpha) {
    wsp::Rectangle* rect = new wsp::Rectangle{};
    rect->x = x;
    rect->y = y;
    rect->width = size;
    rect->height = size;

    wsp::Quad quad{};
    quad.SetRectangle(rect);
    quad.SetFillColor({red, green, blue, alpha});
    quad.Draw(0, 0);

    return rect;
}

// The main game loop
int main() {

    wsp::GameWindow gwd;
    gwd.InitVideo();
    gwd.SetBackground((GXColor) {0, 0, 0, 255});

    int x = gwd.GetWidth() / 2;
    int y = gwd.GetHeight();

    WPAD_Init();

    for (;;) {
        WPAD_ScanPads();
        if ((WPAD_ButtonsDown(WPAD_CHAN_0) & WPAD_BUTTON_HOME) != 0u){
            break;
        }
        
        gwd.Flush();
    }

    return 0;
}