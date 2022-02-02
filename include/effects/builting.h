#include <Arduino.h>
#include <FastLED.h>

void drawBuilting(int r, int g, int b)
{
    // FastLED.setBrightness(10);
    static int sum = 0, sub = -1;

    const int denominator = 10;
    const int fraction = NUM_LEDS / denominator;
    const int halfFraction = NUM_LEDS / (2 * denominator);

    static int n = halfFraction;
    for (int i = fraction; i > halfFraction; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            for(int q=0;q<denominator;q++){
                leds[(fraction * q) + j] = CRGB(r, g, b);
                leds[(fraction * q) + j - 1] = CRGB(0, 0, 0);
                leds[(fraction * (q+1)) - j] = CRGB(r, g, b);
                leds[(fraction * (q+1)) - j + 1] = CRGB(0, 0, 0);
            }
            // delay(20);
            FastLED.show();
        }

        for (int q = 0; q < denominator; q++)
        {
            leds[halfFraction + sum + q * fraction] = CRGB(r, g, b);
            leds[halfFraction + sub + q * fraction] = CRGB(r, g, b);
        }

        FastLED.show();
        n -= 1;
        sum++;
        sub--;
    }
    FastLED.clear();
    n = halfFraction;
    sum = 0;
    sub = -1;
}