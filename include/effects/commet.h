#include <Arduino.h>
#include <FastLED.h>

//arduino's random alternative -> to make it faster
//i got it at http://engineeringnotes.blogspot.com/2015/07/a-fast-random-function-for-arduinoc.html
uint16_t rng(uint16_t seed) {
    static uint16_t y = 0;
    if (seed != 0) y += (seed && 0x1FFF); // seeded with a different number
    y ^= y << 2;
    y ^= y >> 7;
    y ^= y << 7;
    return (y);
}

void DrawCommet(){

    const byte fadeAmnt = 128;
    const int commetSize = 10;
    const int deltaHue = 4;

    static byte hue = HUE_RED;
    static int iDirection = 1; //commet direction (1 or -1)
    static int iPos=0; //position
    boolean commetRandomDecay = true;

    hue+=deltaHue;
    iPos+=iDirection;

    if(iPos == (NUM_LEDS - commetSize) || iPos==0)
        iDirection*=-1;
    
    for(int i=0;i<commetSize;i++){
        leds[iPos + i].setHue(hue);
    }

    //fade the commet's tail
    for(int j=0;j<NUM_LEDS;j++){
        if((!commetRandomDecay) || (rng(2))%2==0){
            leds[j]=leds[j].fadeToBlackBy(fadeAmnt);//randomly fading
        }
    }
    delay(5);

}

void DrawCommet(int s){

    const byte fadeAmnt = 128;
    const int commetSize = s;
    const int deltaHue = 4;

    static byte hue = HUE_RED;
    static int iDirection = 1; //commet direction (1 or -1)
    static int iPos=0; //position
    boolean commetRandomDecay = true;

    hue+=deltaHue;
    iPos+=iDirection;

    if(iPos == (NUM_LEDS - commetSize) || iPos==0)
        iDirection*=-1;
    
    for(int i=0;i<commetSize;i++){
        leds[iPos + i].setHue(hue);
    }

    //fade the commet's tail
    for(int j=0;j<NUM_LEDS;j++){
        if((!commetRandomDecay) || (rng(2))%2==0){
            leds[j]=leds[j].fadeToBlackBy(fadeAmnt);//randomly fading
        }
    }
    delay(5);

}

void DrawCommet(CRGB color1, CRGB color2, CRGB color3){

    const byte fadeAmnt = 128;
    const int commetSize = 30;
    const int deltaHue = 4;

    static byte hue = HUE_RED;
    static int iDirection = 1; //commet direction (1 or -1)
    static int iPos=0; //position
    boolean commetRandomDecay = true;

    hue+=deltaHue;
    iPos+=iDirection;

    if(iPos == (NUM_LEDS - commetSize) || iPos==0)
        iDirection*=-1;
    
    if(iDirection==1)fill_gradient_RGB(&leds[iPos],commetSize,color1, color2, color3);
    else fill_gradient_RGB(&leds[iPos],commetSize,color3, color2, color1);

    //fade the commet's tail
    for(int j=0;j<NUM_LEDS;j++){
        if((!commetRandomDecay) || (rng(2))%2==0){
            leds[j]=leds[j].fadeToBlackBy(fadeAmnt);//randomly fading
        }
    }
    // delay(5);

}