#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <LiquidCrystal.h>
#include <Print.h>

class LiquidCrystalPlus;

class Display: public Print {
protected:
    LiquidCrystal *lcd;
    uint8_t columns, rows;
    uint8_t xOffset, yOffset;
public:
    Display();

    virtual size_t write(uint8_t value);

    void clear();
    void init();

    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);

    void setCursor(uint8_t col, uint8_t row);
    void setOffset(uint8_t xOffset, uint8_t yOffset);
};

#endif
