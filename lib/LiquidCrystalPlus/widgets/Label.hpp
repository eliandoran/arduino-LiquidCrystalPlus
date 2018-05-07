#ifndef LABEL_INCLUDED
#define LABEL_INCLUDED

#include "../Widget.hpp"
#include "../Display.hpp"
#include <Arduino.h>

class Label: public Widget {
    void update() {
        display->setCursor(0, 0);
        display->print("Hi");
    }
};

#endif
