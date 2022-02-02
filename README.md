# arduino-led
LED controlling with arduino and FastLED library. Built with **PlatformIO** tool <br><br>

In the directory ```include/effects``` there are a lot of headfiles with the effects. Some of them have more than one function, those are some variations of the same effect.<br><br>
The ```main.cpp``` file has a serial communication algorithm. This project fits in every arduino board. The effects can be called from the Monitor Serial.<br><br>

## Usage
**Solid colors:** <br>
To fill the hole led with yellow solid color, it's needed to write on the Monitor Serial:
```RGB;255,255,0;```<br>
The same sintax is used to any other RGB color.
<br><br>
**Effects:**<br>
To call any effect, it's needed to write on the Monitor Serial ```EF;<effect_code>```. <br>
The effects code are listed in the ```drawEffect.h``` file. <br>
Between calling the effects, write on the Monitor Serial: ```P;```, to pause the previous effect