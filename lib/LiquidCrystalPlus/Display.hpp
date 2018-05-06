#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <LiquidCrystal.h>
#include <Print.h>

class LiquidCrystalPlus;

class Display: public Print {
protected:
    LiquidCrystal *lcd;
    int columns;
    int rows;
public:
    Display();

    virtual size_t write(uint8_t value);

    void clear();
    void init();

    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);

    void setCursor(uint8_t col, uint8_t row);
};

#endif
