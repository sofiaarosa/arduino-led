#include <Arduino.h>
#include <FastLED.h>

void drawPixels(CRGB color)
{
    static int p = 0;
    for (int i = 0; i < NUM_LEDS; i += 10)
    {
        leds[p + i] = color;
        leds[p + i - 1] = CRGB::Black;
    }
    FastLED.show();
    delay(20);
    p++;
    if (p == 10)
        p = 0;
}

//not done yet - im hating it
void drawPixels()
{
    FastLED.setBrightness(50);

    const CRGB colors[6] = {
        CRGB(255, 0, 0), CRGB(255, 255, 0),
        CRGB(0, 255, 0), CRGB(0, 255, 255),
        CRGB(0, 0, 255), CRGB(255, 0, 255)};

    int count = 1;
    for (int p = 0; p < 10; p++)
    {
        int index = 0;
        for (int i = 0; i < NUM_LEDS; i += 10)
        {
            leds[p + i] = colors[index];
            leds[p + i - 1] = CRGB::Black;
            index++;
            if (index == 7)
                index = 0;
        }
        FastLED.show();
        delay(20);
        count++;
    }
}

void drawPixelsPacMan()
{
    FastLED.setBrightness(50);

    int ghost1, ghost2, ghost3, ghost4;
    int pacman;

    for (int i = 0; i < (NUM_LEDS - 50); i++)
    {
        if (i == 90 || i==180)
        {
            FastLED.clear();
            leds[pacman] = CRGB(255, 155, 0);
            leds[pacman-1] = CRGB(255, 155, 0);
            leds[pacman-2] = CRGB(255, 155, 0);
            leds[pacman-3] = CRGB(255, 155, 0);
            leds[pacman-4] = CRGB(255, 155, 0);
            FastLED.show();
            delay(100);
            leds[ghost1-1]=CRGB(255,0,0);
            leds[ghost2-1]=CRGB(0,191,255);
            leds[ghost3-1]=CRGB(255,69,0);
            leds[ghost4-1]=CRGB(255,0,255);
            FastLED.show();
            delay(160);
            FastLED.clear();
            leds[pacman] = CRGB(255, 155, 0);
            leds[pacman-1] = CRGB(255, 155, 0);
            leds[pacman-2] = CRGB(255, 155, 0);
            leds[pacman-3] = CRGB(255, 155, 0);
            leds[pacman-4] = CRGB(255, 155, 0);
            FastLED.show();
            delay(100);
            leds[ghost1-2]=CRGB(255,0,0);
            leds[ghost2-2]=CRGB(0,191,255);
            leds[ghost3-2]=CRGB(255,69,0);
            leds[ghost4-2]=CRGB(255,0,255);
            FastLED.show();
            FastLED.clear();
            leds[pacman] = CRGB(255, 155, 0);
            leds[pacman-1] = CRGB(255, 155, 0);
            leds[pacman-2] = CRGB(255, 155, 0);
            leds[pacman-3] = CRGB(255, 155, 0);
            leds[pacman-4] = CRGB(255, 155, 0);
        }
        else
        {
            leds[NUM_LEDS - i] = CRGB(255, 155, 0);
            leds[NUM_LEDS - i + 5] = CRGB::Black;
            pacman = NUM_LEDS - i;

            leds[NUM_LEDS - i - 11] = CRGB(255, 0, 0);
            leds[NUM_LEDS - i - 11 + 1] = CRGB::Black;
            ghost1 = NUM_LEDS - i - 11;

            leds[NUM_LEDS - i - 21] = CRGB(0, 191, 255);
            leds[NUM_LEDS - i - 21 + 1] = CRGB::Black;
            ghost2 = NUM_LEDS - i - 21;

            leds[NUM_LEDS - i - 31] = CRGB(255, 69, 0);
            leds[NUM_LEDS - i - 31 + 1] = CRGB::Black;
            ghost3 = NUM_LEDS - i - 31;

            leds[NUM_LEDS - i - 41] = CRGB(255, 0, 255);
            leds[NUM_LEDS - i - 41 + 1] = CRGB::Black;
            ghost4 = NUM_LEDS - i - 41;

            FastLED.show();
            // delay(3);
        }
    }

    FastLED.clear();
}

void drawPixelsPacMan2()
{
    FastLED.setBrightness(50);

    int ghost1, ghost2, ghost3, ghost4;

    for (int i = 0; i < (NUM_LEDS - 30) / 2; i++)
    {
        int pacman = i;
        leds[i] = CRGB(255, 255, 0);
        leds[i - 3] = CRGB::Black;

        leds[NUM_LEDS - i] = CRGB(255, 0, 255);
        leds[NUM_LEDS - i + 1] = CRGB::Black;
        ghost1 = NUM_LEDS - i; //purple

        leds[NUM_LEDS - i - 11] = CRGB(255, 0, 0);
        leds[NUM_LEDS - i - 11 + 1] = CRGB::Black;
        ghost2 = NUM_LEDS - i - 11 + 1; //red

        leds[NUM_LEDS - i - 21] = CRGB(0, 191, 255);
        leds[NUM_LEDS - i - 21 + 1] = CRGB::Black;
        ghost3 = NUM_LEDS - i - 21 + 1; //blue

        leds[NUM_LEDS - i - 31] = CRGB(255, 69, 0);
        leds[NUM_LEDS - i - 31 + 1] = CRGB::Black;
        ghost4 = NUM_LEDS - i - 31 + 1; //orange

        FastLED.show();
        delay(5);
    }

    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            leds[ghost1] = CRGB::Black;
            leds[ghost2 - 1] = CRGB::Black;
            leds[ghost3 - 1] = CRGB::Black;
            leds[ghost4 - 1] = CRGB::Black;
        }
        else
        {
            leds[ghost1] = CRGB(255, 0, 255);
            leds[ghost2 - 1] = CRGB(255, 0, 0);
            leds[ghost3 - 1] = CRGB(0, 191, 255);
            leds[ghost4 - 1] = CRGB(255, 50, 10);
        }

        FastLED.show();
        delay(200);
    }

    FastLED.clear();
}