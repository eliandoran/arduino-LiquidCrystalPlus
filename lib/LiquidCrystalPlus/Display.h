#ifndef DISPLAY_INCLUDED
#define DISPLAY_INCLUDED

#include <LiquidCrystal.h>
#include <Print.h>

template <typename TRow>
class CustomCharacterManager;

class Display: public Print {
template<class TRow> friend class CustomCharacterManager;
protected:
    LiquidCrystal *lcd;
    uint8_t columns, rows;
    uint8_t xOffset, yOffset;
    uint8_t currentX, currentY;
    uint8_t charWidth, charHeight;
public:
    Display();

    virtual size_t write(uint8_t value);

    void clear();
    void init();

    uint8_t getCurrentX();
    uint8_t getCurrentY();

    uint8_t getScreenWidth();
    uint8_t getScreenHeight();
    uint8_t getCharacterWidth();
    uint8_t getCharacterHeight();

    void setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void setResolution(int columns, int rows);

    void setCursor(uint8_t col, uint8_t row);    
    void refreshCursor();
    
    void setOffset(uint8_t xOffset, uint8_t yOffset);
};

#endif
