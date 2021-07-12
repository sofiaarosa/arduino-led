#include <Arduino.h>
#include <FastLED.h>

class cFireEffect
{
protected:
    int Size;
    int Cooling;
    int Sparks;
    int SparkHeight;
    int Sparking;
    bool bReversed;
    bool bMirrored;

    byte *heat;

    static const byte BlendSelf = 2;
    static const byte BlendNeighbor1 = 3;
    static const byte BlendNeighbor2 = 2;
    static const byte BlendNeighbor3 = 1;
    static const byte BlendTotal = (BlendSelf + BlendNeighbor1 + BlendNeighbor2 + BlendNeighbor3);

public:
    cFireEffect(int size, int cooling = 80, int sparking = 50, int sparks = 3, int sparkHeight = 4, bool reversed = true, bool mirrored = true)
    {
        Size = size;
        Cooling = cooling;
        Sparking = sparking;
        Sparks = sparks;
        SparkHeight = sparkHeight;
        bReversed = reversed;
        bMirrored = mirrored;

        if (bMirrored)
            Size = Size/2;
        heat = new byte[size]{0};
    }

    virtual void DrawFire()
    {
        //First cool each cell by a little bit
        for (int i = 0; i < Size; i++)
        {
            heat[i] = max(0L, heat[i] - random(0, ((Cooling * 10) / Size) + 2));
        }

        //next drift heat up and difuse it a little bit
        for (int i = 0; i < Size; i++)
        {
            heat[i] = (heat[i] * BlendSelf +
                       heat[(i + 1) % Size] * BlendNeighbor1 +
                       heat[(i + 2) % Size] * BlendNeighbor2 +
                       heat[(i + 2) % Size] * BlendNeighbor3) /
                      BlendTotal;
        }

        //random ignite flames' sparks
        for (int i = 0; i < Sparks; i++)
        {
            int y = Size - 1 - random(SparkHeight);
            heat[y] = heat[y] + random(160, 255);
        }

        for (int i = 0; i < Size; i++)
        {
            CRGB color = HeatColor(heat[i]);
            int j = bReversed ? (Size - 1 - i) : i;
            leds[j]=color;
            if (bMirrored)
            {
                int j2 = !bReversed ? (2 * Size - 1 - i) : Size + i;
                leds[j2]=color;
            }
        }
    }
};