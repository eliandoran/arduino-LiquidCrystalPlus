#include <LiquidCrystalPlus.hpp>
#include "Display.hpp"

Display::Display(LiquidCrystalPlus &lcd) : lcd(lcd) {}

void Display::print(char* message) {
    lcd.lcd->print(message);
}

void Display::print(int x, int y, char* message) {
    lcd.lcd->setCursor(x, y);
    lcd.lcd->print(message);
}
