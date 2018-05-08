#ifndef CUSTOM_CHARACTER_MANAGER_INCLUDED
#define CUSTOM_CHARACTER_MANAGER_INCLUDED

#include <Arduino.h>
#include <LinkedList.h>
#include <Display.h>

#define CHAR_NOT_FOUND 255

template <typename TRow>
class CustomCharacterManager {
private:
    int maxCharacters;
    int charWidth, charHeight;
    Display &display;
    TRow **charStore;

    short findCharIndex(TRow* rows) {
        Serial.print("Finding character @ ");
        Serial.println((long)rows);        

        for (int i=0; i<maxCharacters; i++) {
            if (charStore[i] == rows) {
                Serial.print("Found it at ");
                Serial.println(i);
                return i;
            }
        }
        
        return CHAR_NOT_FOUND;
    }

    short loadChar(TRow* rows) {
        Serial.println("Not found, loading.");
        int i = 0;
        display.lcd->createChar(i, rows);
        charStore[i] = rows;
    }

public:
    CustomCharacterManager(Display &display, int maxCharacters, int charWidth, int charHeight): display(display) {
        this->maxCharacters = maxCharacters;
        this->charWidth = charWidth;
        this->charHeight = charHeight;
        this->charStore = (TRow**)calloc(maxCharacters, sizeof(TRow*));
    }

    void printChar(TRow* rows) {        
        int charIndex = findCharIndex(rows);

        if (charIndex == CHAR_NOT_FOUND) {
            uint8_t currentX = display.getCurrentX();
            uint8_t currentY = display.getCurrentY();
            charIndex = loadChar(rows);

            for (int i=0; i<2; i++) {
                display.setCursor(currentX, currentY);
                display.write(charIndex);  
            }      
        }

        display.write(charIndex);
    }
};

#endif
