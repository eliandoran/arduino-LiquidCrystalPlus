#include <Arduino.h>
#include <LiquidCrystalPlus.hpp>
#include "HelloWorldPage.hpp"

LiquidCrystalPlus lcd;

void setup() {
    lcd.setPins(8, 9, 4, 5, 6, 7);
    lcd.setResolution(16, 2);
    lcd.init();

    HelloWorldPage helloPage;
    lcd.show(helloPage);
    lcd.doLoop();
}

void loop() {
    // put your main code here, to run repeatedly:
}
