/*
author: Sofia Azevedo Rosa
file:main.cpp

description: main file of LedEffects project. 
(07/07/2021) In beginning, it only calls the effects functions from the effects files

*/
#include <Arduino.h>
#include<FastLED.h>

#define DATA_PIN 7
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

#include "effects.h"

void setup() {
  pinMode(DATA_PIN,OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  DrawCommet();
  FastLED.show(); 
}