#include <Arduino.h>
#include <FastLED.h>

void drawFade(){
    // FastLED.setBrightness(10);
    for(int i=0;i<100000;i++){
      for(int j=0;j<NUM_LEDS;j++){
        leds[j].setHSV(i*4,255,255);
      }
      FastLED.show();
      delay(10);
    }
}