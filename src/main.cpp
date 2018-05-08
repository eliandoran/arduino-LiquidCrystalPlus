#include <Arduino.h>
#include <LiquidCrystalPlus.h>
#include "examples/HelloWorld/HelloWorldPage.h"
#include "examples/HelloWorldWidget/HelloWorldWidget.h"
#include "examples/RecursivePageNavigation/PingPage.h"
#include "examples/CustomCharacter.h"
#include "examples/RandomCustomCharacter.h"

LiquidCrystalPlus lcd;

void setup() {
    Serial.begin(9600);
    Serial.println("Startup");

    lcd.setPins(8, 9, 4, 5, 6, 7);
    lcd.setResolution(16, 2);
    lcd.init();

    // Example: HelloWorld
    //lcd.show(new HelloWorldPage());

    // Example: HelloWorldWidgetPage
    lcd.show(new HelloWorldWidgetPage());

    // Example: RecursivePageNavigation
    //lcd.show(new PingPage());

    // Example: Custom Character
    lcd.show(new RandomCustomCharacterPage());

    lcd.doLoop();
}
