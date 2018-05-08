#include <LiquidCrystalPlus.h>
#include <inttypes.h>

uint8_t starsCharacter[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

uint8_t starsCharacterReverse[8] = {
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
    CustomCharacterManager<uint8_t> *charMan;

    void show() {
        charMan = new CustomCharacterManager<uint8_t>(*display, 8, 5, 8);

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
        charMan->printChar(which ? starsCharacter : starsCharacterReverse);       

        display->setCursor(i, 1);
        charMan->printChar(which ? starsCharacter : starsCharacterReverse);       

        which = !which;

        i++;
    }
};
