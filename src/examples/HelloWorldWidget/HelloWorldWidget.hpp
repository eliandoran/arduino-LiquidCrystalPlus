#include <LiquidCrystalPlus.hpp>

class HelloWorldWidgetPage: public Page {
private:
    Label helloWorld;

public:
    virtual void show() {
        add(helloWorld);
    }

    virtual void loop() {
        display->setCursor(0, 1);
        display->print(millis() / 1000);
        delay(100);
    }
};
