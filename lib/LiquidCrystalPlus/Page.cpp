#include <LiquidCrystalPlus.hpp>
#include "Page.hpp"

void Page::init(LiquidCrystalPlus &lcd) {
    this->lcd = &lcd;
    this->display = lcd.display;
    lcd.lcd->clear();
}

Page::~Page() {
    // No action needed.
}
