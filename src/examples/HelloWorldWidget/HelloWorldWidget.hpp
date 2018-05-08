#include <Arduino.h>
#include <LiquidCrystalPlus.hpp>

class MillisecondsCounterWidget: public Widget {
    void update() {
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
        add(new MillisecondsCounterWidget(), 1, 1);
    }

    virtual void loop() {
        topLabel.setText("Millis:");
    }
};
