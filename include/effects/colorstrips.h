#include<Arduino.h>
#include<FastLED.h>

void drawStrips(int r, int g, int b){
  for(int j=0;j<15;j++){
    for(int i=0;i<NUM_LEDS;i+=15){
      fill_solid(&leds[i+j],3,CRGB(r,g,b));
    }
    FastLED.show();
    delay(20);
    for(int i=0;i<NUM_LEDS;i+=15){
      leds[i+j]=CRGB(0,0,0);
    }
  }
}