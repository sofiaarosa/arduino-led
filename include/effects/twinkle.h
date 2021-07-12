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

void DrawTwinkle(int r, int g, int b)
{
    int menor = 1;
    if (r != 0)
        menor = r;
    else if (g != 0)
        menor = g;
    else if (b != 0)
        menor = b;

    if (r < menor && r != 0)
        menor = r;
    if (g < menor && g != 0)
        menor = g;
    if (b < menor && b != 0)
        menor = b;

    int sr = 0;
    int sg = 0;
    int sb = 0;

    if (menor == 1)
    {
        sr = r;
        sg = g;
        sb = b;
        r *= 5;
        g *= 5;
        b *= 5;
    }
    else
    {
        if (r != 0)
            sr = r / menor;
        if (g != 0)
            sg = g / menor;
        if (b != 0)
            sb = b / menor;
    }

    fill_solid(leds, NUM_LEDS, CRGB(sr, sg, sb));

    for (int i = 0; i < NUM_LEDS / 10; i++)
    {
        leds[random(NUM_LEDS)] = CRGB(r, g, b);
        FastLED.show();
        delay(200);
    }
}