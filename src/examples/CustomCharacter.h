#include <LiquidCrystalPlus.h>

CustomChar starsCharacter[] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

CustomChar starsCharacterReverse[] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};

class CustomCharacterPage: public Page {
    void show() {
        display->setOffset(0, 0);
    }

    void loop() {        
        delay(500);

        static int i = 0;
        static bool which = false;

        if (i > 16) {
            i = 0;
        }

        display->setCursor(i, 0);
        display->printChar(which ? starsCharacter : starsCharacterReverse);       

        display->setCursor(i, 1);
        display->printChar(which ? starsCharacter : starsCharacterReverse);       

        which = !which;

        i++;
    }
};
