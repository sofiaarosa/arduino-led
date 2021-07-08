#include <Arduino.h>
#include <FastLED.h>

void DrawTwinkle()
{
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.setBrightness(50);
    for (int i = 0; i < NUM_LEDS / 5; i++)
    {
        leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));
    }
    for (int j = 0; j < 50; j++)
        {
            FastLED.setBrightness(j);
            FastLED.show();
            delay(10);
        }
        for (int k = 50; k >= 0; k--)
        {
            FastLED.setBrightness(k);
            FastLED.show();
            delay(10);
        }
}