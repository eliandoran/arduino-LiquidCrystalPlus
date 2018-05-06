#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <LiquidCrystal.h>

class LiquidCrystalPlus;

class Display {
protected:
    LiquidCrystal &lcd;
public:
    Display(LiquidCrystal &lcd);

    void print(char* message);
    void print(int x, int y, char* message);
};

#endif
