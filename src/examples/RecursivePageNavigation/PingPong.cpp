#include <Arduino.h>
#include <LiquidCrystalPlus.h>
#include "PingPage.h"
#include "PongPage.h"

#define DELAY 1000

void displayFreeRAM(Display *display) {
    extern int __heap_start, *__brkval;
    int v;
    int freeRAM = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);

    display->setCursor(12, 0);
    display->print("RAM");

    display->setCursor(11, 1);
    display->print(freeRAM);
    display->write('B');
}

void PingPage::show() {
    display->print("Ping");

    displayFreeRAM(display);
}

void PingPage::loop() {
    delay(DELAY);
    lcd->show(new PongPage());
}

void PongPage::show() {
    display->setCursor(0, 1);
    display->print("Pong");

    displayFreeRAM(display);
}

void PongPage::loop() {
    delay(DELAY);
    lcd->show(new PingPage());
}
