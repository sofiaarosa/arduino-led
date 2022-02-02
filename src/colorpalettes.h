#include <Arduino.h>
#include<FastLED.h>

// Gradient palette "bhw1_06_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_06.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_06_gp ) {
    0, 184,  1,128,
  160,   1,193,182,
  219, 153,227,190,
  255, 100,100,100};




// Gradient palette "bhw1_07_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_07.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE( sunset ) {
    0, 232, 65,  1,
  255, 229,227,  1};


// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( coldPalette ) {
    0,  75,  1,221,
   30, 252, 73,255,
   48, 169,  0,242,
  119,   0,149,242,
  170,  43,  0,242,
  206, 252, 73,255,
  232,  78, 12,214,
  255,   0,149,242};


// Gradient palette "autumnrose_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/autumnrose.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( hotPalette ) {
    0,  71,  3,  1,
   45, 128,  5,  2,
   84, 186, 11,  3,
  127, 215, 27,  8,
  153, 224, 69, 13,
  188, 229, 84,  6,
  226, 242,135, 17,
  255, 247,161, 79};

// Gradient palette "aquamarinemermaid_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/aquamarinemermaid.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( mermaid ) {
    0,  23,  4, 32,
   63,  98, 31, 52,
  127, 224,138, 24,
  191,   7, 55,164,
  255,  23,  4, 32};


DEFINE_GRADIENT_PALETTE(brazil){
    0, 0,150,0,
    51,255,255,0,
    102,0,0,255,
    153,0,150,0,
    204,255,255,0,
    255,0,0,255
};

//rainbow wave
CRGBPalette16 rainbowWave{
    CRGB(50,0,0),
    CRGB(255,0,0),

    CRGB(50,50,0),
    CRGB(255,255,0),

    CRGB(0,50,0),
    CRGB(0,255,0),

    CRGB(50,0,0),
    CRGB(255,0,0),

    CRGB(0,50,50),
    CRGB(0,255,255),
    
    CRGB(0,0,50),
    CRGB(0,0,255),

    CRGB(50,0,50),
    CRGB(255,0,255),

    CRGB(50,50,0),
    CRGB(255,255,0),
};

CRGBPalette16 choosePalette(int n){
    CRGBPalette16 aux;
    switch (n)
    {
    case 1:
        aux = coldPalette;
        break;
    
    case 2:
        aux = hotPalette;
        break;
    
    case 3:
        aux = sunset;
        break;

    case 4:
        aux = mermaid;
        break;
    case 5:
        aux = brazil;
        break;
    case 6:
        aux = bhw1_06_gp;
        break;
    
    default:
        aux = mermaid;
        break;
    }
    return aux;
}
