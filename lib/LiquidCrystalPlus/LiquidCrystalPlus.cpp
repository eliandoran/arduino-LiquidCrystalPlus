#include <LiquidCrystal.h>
#include "LiquidCrystalPlus.hpp"

LiquidCrystalPlus::LiquidCrystalPlus()
{
    // Set defaults
    this->columns = 16;
    this->rows = 2;
}

void LiquidCrystalPlus::setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
    this->lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
}

void LiquidCrystalPlus::setResolution(int columns, int rows) {
    this->columns = columns;
    this->rows = rows;
}

void LiquidCrystalPlus::init() {
    this->lcd->begin(this->rows, this->columns);
}
