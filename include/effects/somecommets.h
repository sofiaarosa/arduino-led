#include <Arduino.h>
#include <FastLED.h>

#include <Arduino.h>
#include <FastLED.h>

void drawCommets(int r, int g, int b)
{
    static int cPosition = 0;
    static const int cInitialSize = 30;
    static int cSize = cInitialSize - 3;

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

    for (int i = 0; i < NUM_LEDS - cInitialSize; i += cInitialSize)
    {
        cSize = cInitialSize - 3;
        for (int j = 1; j <= cSize; j++)
        {
            if (cPosition + j + i == NUM_LEDS-3)
            {
                cPosition=0;
                break;
            }
            else
            {
                if (sr * j <= r && sg * j <= g && sb * j <= b)
                    leds[cPosition + j + i] = CRGB(sr * j, sg * j, sb * j);
                else
                    leds[cPosition + j + i] = CRGB(sr, sg, sb);
            }
        }
    }

    FastLED.show();
    cPosition++;
    delay(10);
}