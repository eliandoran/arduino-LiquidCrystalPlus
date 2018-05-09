#include <LiquidCrystalPlus.h>

class HelloWorldPage: public Page {
public:
    void show() {
        display->print("Hello world.");
    }

    void loop() {
        display->setCursor(0, 1);
        display->print(millis() / 1000);
        delay(100);
    }
};
