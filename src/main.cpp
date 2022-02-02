/*
author: Sofia Azevedo Rosa
file:main.cpp
description: main file of LedEffects project. 
(07/07/2021) In beginning, it only calls the effects functions from the effects files
*/

#include <Arduino.h>
#include <FastLED.h>

#define DATA_PIN 13
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
String message;

#include "drawEffect.h"

void setup()
{
  pinMode(DATA_PIN, OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  fill_solid(leds,NUM_LEDS,CRGB(100,100,100));
  FastLED.show();
  Serial.begin(9600);
  Serial.println("SETUP");
}

void loop()
{
  if(Serial.available()>0){
    char reading=Serial.read();
    Serial.print("\nReading: "); Serial.print(reading,DEC);
    
    if(reading!=59){
      //59 = ;
      message+=reading;
      Serial.print("\n Message:"); Serial.print(message);
    }

    else {
      //if is ;
      if(message=="P"){
        //P means pause -> using it to stop effects
        FastLED.clear();
        FastLED.show();
        message = ""; reading=' ';
      }
      if(message=="RGB"){
        message="";reading=' ';
        Serial.println("Solid Color:");
        int r, g,b, count=0;

        //59 = ; in ASCII        
        while(reading!=59 && count<3){
          reading=Serial.read();
          Serial.print("\nreading color: ");Serial.print(reading);
          
          if(reading!=44 && reading!=59){
            //44 = ,
            message+=reading;
            Serial.print("\nmessage color:");Serial.print(message);
          }
          else{
            if(count==0)r=message.toInt();
            else if(count==1)g=message.toInt();
            else b=message.toInt();

            message="";
            count++;
          }
        }//while reading colors

        Serial.print("\n\nR: ");Serial.print(r);
        Serial.print("\nG: ");Serial.print(g);
        Serial.print("\nB: ");Serial.print(b);

        FastLED.setBrightness(50);
        fill_solid(leds,NUM_LEDS, CRGB(r,g,b));
        FastLED.show();
        FastLED.setBrightness(100);

      }//if rgb

      if(message=="EF"){
        message = ""; reading= ' ';
        int effect = 0;
        int rE=10, gE = 10, bE=10, count=0;
        CRGB color = CRGB(rE,gE,bE);

        Serial.println("effects");
        
        //59 = ';' in ASCII
        while(reading!=59){
          reading=Serial.read();
          Serial.print(reading);
          if(reading!=59)message+=reading;
        }

        effect = message.toInt();

        //verify if still has a color for the effect
        if(Serial.available()>0){
          message=""; reading=' ';
          Serial.println("color 4 the effect");

          //59 = ; in ASCII
          while(reading!=59&&count<3){
            reading = Serial.read();
            Serial.print(reading);

            //44 = ',' in ASCII
            if(reading!=44&&reading!=59){
              message+=reading;
            }
            else{
              if(count==0) rE=message.toInt();
              else if(count==1)gE= message.toInt();
              else bE = message.toInt();

              message=""; count++;
            }
          }

          Serial.print("\n\nR: ");Serial.print(rE);
          Serial.print("\nG: ");Serial.print(gE);
          Serial.print("\nB: ");Serial.print(bE);

          color = CRGB(rE, gE, bE);
          
        }

        while(Serial.available()==0){
          draw(effect, color);
        }
      }

      message="";reading=' ';
      
    }
  }//Serial.available()>0
}
