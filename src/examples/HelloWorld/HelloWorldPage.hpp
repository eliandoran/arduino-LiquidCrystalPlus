#include <LiquidCrystalPlus.hpp>

class HelloWorldPage: public Page {
public:
    void show() {
        display->print("Hello world.");
    }

    void loop() {
        lcd->lcd->setCursor(0, 1);
        lcd->lcd->print(millis() / 1000);
        delay(100);
    }
};
