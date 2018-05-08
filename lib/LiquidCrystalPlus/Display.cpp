#include <LiquidCrystal.h>
#include <LiquidCrystalPlus.hpp>
#include "Display.hpp"

Display::Display() {
    // Set defaults
    this->columns = 16;
    this->rows = 2;
}

void Display::init() {
    lcd->begin(this->rows, this->columns);
}

/**
 * Causes the screen to be cleared.
 */
void Display::clear() {
    lcd->clear();
}

void Display::setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
    lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
}

void Display::setResolution(int columns, int rows) {
    this->columns = columns;
    this->rows = rows;
}

size_t Display::write(uint8_t value) {
    lcd->write(value);
    return true;
}

void Display::setCursor(uint8_t col, uint8_t row) {
    col += xOffset;
    row += yOffset;

    lcd->setCursor(col, row);
}

void Display::setOffset(uint8_t xOffset, uint8_t yOffset) {
    this->xOffset = xOffset;
    this->yOffset = yOffset;
}
