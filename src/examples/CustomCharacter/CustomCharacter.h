#include <LiquidCrystalPlus.h>
#include <inttypes.h>

uint8_t starsCharacter[] = {
    0b01010,
    0b10101,
    0b01010,
    0b10101,
    0b01010,
    0b10101,
    0b01010,
    0b10101,
};

class CustomCharacterPage: public Page {
    CustomCharacterManager<uint8_t> *charMan;

    void show() {
        display->println("Custom character.");
        charMan = new CustomCharacterManager<uint8_t>(*display, 8, 5, 8);        

        display->setCursor(0, 1);
        charMan->printChar(starsCharacter);

        display->setCursor(1, 1);
        charMan->printChar(starsCharacter);
    }

    void loop() {
        
        delay(500);
    }
};
