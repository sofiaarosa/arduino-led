#include <Arduino.h>
#include <FastLED.h>

//arduino's random alternative -> to make it faster
//i got it at http://engineeringnotes.blogspot.com/2015/07/a-fast-random-function-for-arduinoc.html
uint16_t randomgenerator(uint16_t seed) {
    static uint16_t y = 0;
    if (seed != 0) y += (seed && 0x1FFF); // seeded with a different number
    y ^= y << 2;
    y ^= y >> 7;
    y ^= y << 7;
    return (y);
}

void drawLightning(){
    FastLED.clear();
    int startPosition = 30;
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = CRGB(100,100,100);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = NUM_LEDS-50;
    FastLED.clear();
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = CRGB(100,100,100);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = 100;
    FastLED.clear();
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = CRGB(100,100,100);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = 200;
    FastLED.clear();
    for (int i = 0; i <= 20; i++)
    {
        leds[i+startPosition] = CRGB(100,100,100);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition =0;
    FastLED.clear();
    for (int i = 0; i <= NUM_LEDS; i++)
    {
        leds[i+startPosition] = CRGB(50,50,50);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition =0;
    FastLED.clear();
    for (int i = 0; i <= 100; i++)
    {
        leds[i+startPosition] = CRGB(50,50,50);
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);
}

void drawLightning(CRGB color){
    FastLED.clear();
    int startPosition = 30;
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = NUM_LEDS-50;
    FastLED.clear();
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = 100;
    FastLED.clear();
    for (int i = 0; i <= 50; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition = 200;
    FastLED.clear();
    for (int i = 0; i <= 20; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition =0;
    FastLED.clear();
    for (int i = 0; i <= NUM_LEDS; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);

    startPosition =0;
    FastLED.clear();
    for (int i = 0; i <= 100; i++)
    {
        leds[i+startPosition] = color;
        if(i+startPosition>NUM_LEDS)break;
    }
    FastLED.show();
    delay(50);
}