#include <Arduino.h>
#include <FastLED.h>

#define NUM_COLORS 10
static const CRGB StarsColors[NUM_COLORS]={
    CRGB(255,0,0),
    CRGB(255,255,0),
    CRGB(0,255,0),
    CRGB(0,255,255),
    CRGB(0,0,255),
    CRGB(255,0,255),
    CRGB(255,165,0),
    CRGB(127,255,212),
    CRGB(75,0,130),
    CRGB(255,99,71)
};

void DrawTwinkle()
{
    
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.setBrightness(50);
    for (int i = 0; i < NUM_LEDS / 5; i++)
    {
        CRGB currentColor = StarsColors[random(10)];
        int r=currentColor.r/20;
        int g=currentColor.g/20;
        int b=currentColor.b/20;

        int currentPosition = random(NUM_LEDS);
        for(int j=1;j<=20;j++){
            leds[currentPosition]=CRGB(r*j,g*j,b*j);
            FastLED.show();
            delay(2);
        }
        delay(20);
        FastLED.show();
    }
    delay(100);
    FastLED.clear(false);
}