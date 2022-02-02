#include "colorpalettes.h" // color palettes declaration header file
#include "effects.h" // including effects that are in header files

void draw(int effect, CRGB color){
    switch(effect){
        case 0:
            FastLED.setBrightness(50);
            drawBuilting(color.r, color.g, color.b);
            break;
        case 1:
            drawCommets(color);
            break;
        case 2:
            drawChroma();
            break;
        case 3:
            drawFade();
            break;
        case 4:
            drawRainbowWave();
            break;
        case 5:
            drawStrips(color);
            break;
        case 6:
            drawColorWave(color);
            FastLED.show();
            break;
        case 8:
            drawPixelsPacMan();
            break;
        default:
            drawFade();
            break;
    }
}