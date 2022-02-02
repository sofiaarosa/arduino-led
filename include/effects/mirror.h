#include <Arduino.h>
#include <FastLED.h>

void drawMirror(CRGB color)
{
    // FastLED.setBrightness(10);
    static int sum = 0, sub = -1;

    const int denominator = 6;
    const int fraction = NUM_LEDS / denominator;
    const int halfFraction = NUM_LEDS / (2 * denominator);

    static int n = halfFraction;
    for (int i = fraction; i > halfFraction; i--)
    {
        for (int q = 0; q < denominator; q++)
        {
            leds[halfFraction + sum + q * fraction] = color;
            leds[halfFraction + sub + q * fraction] = color;
        }

        FastLED.show();
        delay(20);
        n -= 1;
        sum++;
        sub--;
    }

    n = halfFraction;
    sum = 0;
    sub = -1;

    for (int i = halfFraction; i < fraction; i++)
    {
        for (int q = 0; q <=denominator; q++)
        {
            if(q<denominator)leds[q * fraction + sum] = CRGB::Black;
            if(q>0)leds[q * fraction + sub] = CRGB::Black;
        }

        FastLED.show();
        delay(30);
        n -= 1;
        sum++;
        sub--;
    }

    n = halfFraction;
    sum = 0;
    sub = -1;
}

void drawMirror(CRGB color,CRGB color2)
{
    // FastLED.setBrightness(10);
    static int sum = 0, sub = -1;

    const int denominator = 6;
    const int fraction = NUM_LEDS / denominator;
    const int halfFraction = NUM_LEDS / (2 * denominator);

    static int n = halfFraction;
    for (int i = fraction; i > halfFraction; i--)
    {
        for (int q = 0; q < denominator; q++)
        {
            leds[halfFraction + sum + q * fraction] = color;
            leds[halfFraction + sub + q * fraction] = color;
        }

        FastLED.show();
        delay(50);
        n -= 1;
        sum++;
        sub--;
    }

    n = halfFraction;
    sum = 0;
    sub = -1;

    for (int i = halfFraction; i < fraction; i++)
    {
        for (int q = 0; q <=denominator; q++)
        {
            if(q<denominator)leds[q * fraction + sum] = color2;
            if(q>0)leds[q * fraction + sub] = color2;
        }

        FastLED.show();
        delay(50);
        n -= 1;
        sum++;
        sub--;
    }

    n = halfFraction;
    sum = 0;
    sub = -1;
}