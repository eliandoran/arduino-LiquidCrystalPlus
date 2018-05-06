#include <LiquidCrystal.h>
#include <LiquidCrystalPlus.hpp>
#include "Display.hpp"

Display::Display(LiquidCrystal &lcd) : lcd(lcd) {}

void Display::print(char* message) {
    lcd.print(message);
}

void Display::print(int x, int y, char* message) {
    lcd.setCursor(x, y);
    lcd.print(message);
}
