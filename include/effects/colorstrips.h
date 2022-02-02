#include <Arduino.h>
#include <FastLED.h>

void drawStrips(CRGB color)
{
  for (int j = 0; j < 15; j++)
  {
    for (int i = 0; i < NUM_LEDS; i += 15)
    {
      fill_solid(&leds[i + j], 5, color);
    }
    FastLED.show();
    delay(20);
    for (int i = 0; i < NUM_LEDS; i += 15)
    {
      leds[i + j] = CRGB(0, 0, 0);
    }
  }
}

void drawStrips(CRGB color1, CRGB color2)
{
  // FastLED.setBrightness(10);
  static int pos = 0;
  for (int i = 0; i < NUM_LEDS - 10; i += 10)
  {
    for (int j = 0; j < 5; j++)
    {
      leds[pos + i + j] = color1;
    }
    for (int j = 5; j <= 10; j++)
    {
      leds[pos + i + j] = color2;
    }
  }
  FastLED.show();
  pos++;
  if (pos == 10)
    pos = 0;
  delay(20);
}

void drawStrips(CRGB color1, CRGB color2, CRGB color3)
{
  // FastLED.setBrightness(10);
  static int pos = 0;
  for (int i = 0; i < NUM_LEDS - 15; i += 15)
  {
    for (int j = 0; j < 5; j++)
    {
      leds[pos + i + j] = color1;
    }
    for (int j = 5; j <= 10; j++)
    {
      leds[pos + i + j] = color2;
    }
    for (int j = 10; j <= 15; j++)
    {
      leds[pos + i + j] = color3;
    }
  }
  FastLED.show();
  pos++;
  if (pos == 15)
    pos = 0;
  delay(20);
}