#include <LiquidCrystalPlus.hpp>

class HelloWorldWidgetPage: public Page {
private:
    Label helloWorld;

public:
    virtual void show() {
        add(helloWorld);
    }

    virtual void loop() {
        extern int __heap_start, *__brkval;
        int v;
        int freeRAM = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);

        display->setCursor(0, 1);
        display->print(freeRAM);
        delay(100);
    }
};
