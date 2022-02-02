#include <Arduino.h>
#include <FastLED.h>

#include <Arduino.h>
#include <FastLED.h>

void drawCommets(CRGB color)
{
    static const int cInitialSize = 30;
    for (int k = 0; k < cInitialSize; k++)
    {
        for (int i = 0; i < NUM_LEDS; i += cInitialSize)
        {
            leds[k + i] = color;
        }
        fadeToBlackBy(leds, NUM_LEDS, 30);
        FastLED.show();
        delay(10);
    }
}
void drawCommets()
{
    static const int cInitialSize = 30;
    static int count = 0;
    for (int k = 0; k < cInitialSize; k++)
    {
        for (int i = 0; i < NUM_LEDS; i += cInitialSize)
        {
            if (count % 2 == 0)
                leds[k + i] = CRGB(100, 0, 0);
            else
                leds[k + i] = CRGB(0, 0, 100);
            count++;
        }
        fadeToBlackBy(leds, NUM_LEDS, 30);
        FastLED.show();
        delay(10);
    }
}

void drawWaveCommets(CRGB color)
{
    for (int i = 0; i > -1; i += 1000)
    {
        uint16_t p = map(beat16(15, i), 0, 65535, 0, NUM_LEDS - 1);
        leds[p] = color;
        fadeToBlackBy(leds, NUM_LEDS, 30);
        FastLED.show();
        if (Serial.available() > 0)
            break;
    }
}

void drawMirroredCommets(CRGB color)
{
    static const int cInitialSize = 30;
    for (int k = 0; k < cInitialSize; k++)
    {
        for (int i = 0; i < (NUM_LEDS / 2); i += cInitialSize)
        {
            leds[k + i] = color;
        }
        for (int i = 0; i < (NUM_LEDS / 2); i += cInitialSize)
        {
            leds[NUM_LEDS - (k + i)] = color;
        }
        fadeToBlackBy(leds, NUM_LEDS, 50);
        FastLED.show();
        delay(10);
    }
}