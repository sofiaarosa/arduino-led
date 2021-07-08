#include <Arduino.h>
#include <FastLED.h>

void DrawTwinkleColor(int r, int g, int b)
{
    int menor = 1;

    if (r > 0)
        menor = r;
    if (g < menor && g > 0)
        menor = g;
    if (b < menor && b > 0)
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
        delay(100);
    }
}