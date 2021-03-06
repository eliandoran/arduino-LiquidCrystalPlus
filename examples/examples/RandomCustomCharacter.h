#include <Arduino.h>
#include <LiquidCrystalPlus.h>

class RandomCustomCharacterPage: public Page {
    int rows, columns;
    int charWidth, charHeight;

    void show() {
        columns = display->getScreenWidth();
        rows = display->getScreenHeight();   

        charWidth = display->getCharacterWidth();
        charHeight = display->getCharacterHeight();

        randomSeed(analogRead(0));
    }

    void loop() {
        for (int y=0; y<rows; y++) {
            for (int x=0; x<columns; x++) {
                display->setCursor(x, y);
                printRandomChar();
                delay(300);
            }
        }

        display->clear();
    }

    void printRandomChar() {
        uint8_t *randomChar = new uint8_t[rows];
        int max = pow(2, 5) - 1;

        for (int row = 0; row < charHeight; row++) {
            randomChar[row] = random(max);
        }

        display->printChar(randomChar);        
    }
};