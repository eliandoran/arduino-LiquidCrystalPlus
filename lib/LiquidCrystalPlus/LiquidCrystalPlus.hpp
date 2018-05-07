#ifndef LIQUID_CRYSTAL_PLUS_INCLUDED
#define LIQUID_CRYSTAL_PLUS_INCLUDED 1

#include <Arduino.h>
#include <inttypes.h>
#include "Page.hpp"
#include "Display.hpp"

#include "widgets/Label.hpp"

class LiquidCrystalPlus {
private:
    Page *activePage;
    bool activePageShown;

public:
    Display display;

    LiquidCrystalPlus();

    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);
    void init();

    void show(Page *page);
    void doLoop();
};

#endif
