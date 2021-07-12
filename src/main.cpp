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

//////////////////////////////////////////// some effects functions that aren't in header files
void BouncingBalls(byte, byte, byte, int);

void setup() {
  pinMode(DATA_PIN,OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  Serial.begin(9600);
}

void loop() {
  drawStrips(CRGB(5,5,5),CRGB(5,0,0));
  // fill_solid(leds,NUM_LEDS,CRGB(0,0,255));
  FastLED.show();
}

//bouncing effect -> it sucks right now, i will make it look better soon 
//(https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#LEDStripEffectBouncingBalls)
void BouncingBalls(byte red, byte green, byte blue, int BallCount) {
  float Gravity = -9.81;
  int StartHeight = 1;
 
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
 
  for (int i = 0 ; i < BallCount ; i++) {  
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
 
      if ( Height[i] < 0 ) {                      
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();
 
        if ( ImpactVelocity[i] < 0.01 ) {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round( Height[i] * (NUM_LEDS - 1) / StartHeight);
    }
 
    for (int i = 0 ; i < BallCount ; i++) {
      leds[Position[i]]=CRGB(red,green,blue);
    }
   
    FastLED.show();
    FastLED.clear();
  }
}