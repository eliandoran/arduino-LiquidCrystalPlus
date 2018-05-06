#ifndef LIQUID_CRYSTAL_PLUS_INCLUDED
#define LIQUID_CRYSTAL_PLUS_INCLUDED 1

#include <Arduino.h>
#include <inttypes.h>
#include <LiquidCrystal.h>
#include "Page.hpp"
#include "Display.hpp"

class LiquidCrystalPlus {
private:
    int columns;
    int rows;
    Page *activePage;
    bool activePageShown;

public:
    Display *display;
    LiquidCrystal *lcd;
    LiquidCrystalPlus();
    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);
    void init();
    void show(Page *page);
    void doLoop();
};

#endif
