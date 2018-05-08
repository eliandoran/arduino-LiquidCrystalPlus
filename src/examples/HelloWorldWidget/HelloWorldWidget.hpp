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
Label topLabel;

public:
    virtual void show() {
        add(topLabel);
        add(new MillisecondsCounterWidget());
    }

    virtual void loop() {
        topLabel.setText("Hello");
    }
};
