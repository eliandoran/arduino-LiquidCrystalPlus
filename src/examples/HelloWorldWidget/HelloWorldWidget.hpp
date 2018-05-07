#include <Arduino.h>
#include <LiquidCrystalPlus.hpp>

class MillisecondsCounterWidget: public Widget {
    void update() {
        display->setCursor(0, 1);
        display->print(millis());
    }

    bool needsUpdate() {
        return (msSinceUpdate >= 1000);
    }
};

class HelloWorldWidgetPage: public Page {
public:
    virtual void show() {
        add(new Label());
        add(new MillisecondsCounterWidget());
    }

    virtual void loop() {

    }
};
