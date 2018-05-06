#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

class LiquidCrystalPlus;

class Display {
protected:
    LiquidCrystalPlus &lcd;
public:
    Display(LiquidCrystalPlus &lcd);

    void print(char* message);
    void print(int x, int y, char* message);
};

#endif
