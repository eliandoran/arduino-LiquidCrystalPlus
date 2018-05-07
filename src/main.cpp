#include <Arduino.h>
#include <LiquidCrystalPlus.hpp>
#include "examples/HelloWorld/HelloWorldPage.hpp"
#include "examples/HelloWorldWidget/HelloWorldWidget.hpp"
#include "examples/RecursivePageNavigation/PingPage.hpp"

LiquidCrystalPlus lcd;

void setup() {
    Serial.begin(9600);

    lcd.setPins(8, 9, 4, 5, 6, 7);
    lcd.setResolution(16, 2);
    lcd.init();

    // Example: HelloWorld
    //lcd.show(new HelloWorldPage());

    // Example: HelloWorldWidgetPage
    lcd.show(new HelloWorldWidgetPage());

    // Example: RecursivePageNavigation
    //lcd.show(new PingPage());
}

void loop() {
    lcd.doLoop();
}
