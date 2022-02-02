#include <Arduino.h>
#include <FastLED.h>

void drawChroma()
{
    uint16_t wave = beat8(10, 0);
    fill_rainbow(leds, NUM_LEDS, wave, 1);
}

void drawPalette(int numberPalette)
{
    CRGBPalette16 palette = choosePalette(numberPalette);

    static int paletteIndex = 0;
    // FastLED.setBrightness(5);
    fill_palette(leds, NUM_LEDS, paletteIndex, 3, palette, 255, LINEARBLEND);

    EVERY_N_MILLISECONDS(10)
    {
        paletteIndex++;
    }
}

void drawRainbowWave()
{
    static int paletteIndex = 0;
    // FastLED.setBrightness(5);
    fill_palette(leds, NUM_LEDS, paletteIndex, 2, rainbowWave, 255, LINEARBLEND);

    EVERY_N_MILLISECONDS(5)
    {
        paletteIndex++;
    }
}

void drawColorWave(CRGB color){
    static int paletteIndex = 0;
    // FastLED.setBrightness(5);
    CRGBPalette16 wave{
        CRGB(0,0,0), color,CRGB(0,0,0), color,
        CRGB(0,0,0), color,CRGB(0,0,0), color,
        CRGB(0,0,0), color,CRGB(0,0,0), color,
        CRGB(0,0,0), color, CRGB(0,0,0),color,
    };
    fill_palette(leds, NUM_LEDS, paletteIndex, 2, wave, 255, LINEARBLEND);

    EVERY_N_MILLISECONDS(15)
    {
        paletteIndex++;
    }
}
void drawColorWave(CRGB color,CRGB color2){
    static int paletteIndex = 0;
    // FastLED.setBrightness(5);
    CRGBPalette16 wave{
        CRGB(0,0,0), color,CRGB(0,0,0), color2,
        CRGB(0,0,0), color,CRGB(0,0,0), color2,
        CRGB(0,0,0), color,CRGB(0,0,0), color2,
        CRGB(0,0,0), color, CRGB(0,0,0),color2,
    };
    fill_palette(leds, NUM_LEDS, paletteIndex, 2, wave, 255, LINEARBLEND);

    EVERY_N_MILLISECONDS(15)
    {
        paletteIndex++;
    }
}

