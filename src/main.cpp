#include <Arduino.h>
#include <LiquidCrystalPlus.hpp>
#include "HelloWorldPage.hpp"
#include "PingPage.hpp"

LiquidCrystalPlus lcd;

void setup() {
    Serial.begin(9600);

    lcd.setPins(8, 9, 4, 5, 6, 7);
    lcd.setResolution(16, 2);
    lcd.init();

    lcd.show(new PingPage());
    lcd.doLoop();
}

void loop() {
    // put your main code here, to run repeatedly:
}
