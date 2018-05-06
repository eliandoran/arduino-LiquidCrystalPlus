#include <LiquidCrystalPlus.hpp>

class HelloWorldPage: public Page {
public:
    void show() {
        display->print("Hello world.");
    }

    void loop() {

    }
};
