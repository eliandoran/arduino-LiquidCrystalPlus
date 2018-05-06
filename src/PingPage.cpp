#include <Arduino.h>
#include "PingPage.hpp"
#include "PongPage.hpp"

#define DELAY 1000

void PingPage::show() {
    display->print("Ping");
}

void PingPage::loop() {
    delay(DELAY);
    lcd->show(new PongPage());
}

void PongPage::show() {
    lcd->lcd->setCursor(0, 1);
    lcd->lcd->print("Pong");
}

void PongPage::loop() {
    delay(DELAY);
    lcd->show(new PingPage());
}
