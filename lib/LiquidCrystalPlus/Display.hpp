#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <LiquidCrystal.h>

class LiquidCrystalPlus;

class Display {
protected:
    LiquidCrystal *lcd;
    int columns;
    int rows;
public:
    Display();

    void print(char* message);
    void print(int x, int y, char* message);

    void clear();
    void init();

    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);
};

#endif
