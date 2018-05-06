#include <LiquidCrystalPlus.hpp>
#include "Display.hpp"

Display::Display(LiquidCrystalPlus &lcd) : lcd(lcd) {}

void Display::print(char* message) {
    lcd.lcd->print(message);
}
