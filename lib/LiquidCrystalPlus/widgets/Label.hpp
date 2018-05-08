#ifndef LABEL_INCLUDED
#define LABEL_INCLUDED

#include "../Widget.hpp"
#include "../Display.hpp"
#include <Arduino.h>

class Label: public Widget {
private:
    bool textChanged = false;
    char* text = NULL;

public:
    void update() {
        if (text == NULL) return;

        display->setCursor(0, 0);
        display->print(text);
    }

    bool needsUpdate() {
        return textChanged;
    }

    void setText(char* text) {
        this->text = text;
        textChanged = true;
    }
};

#endif
