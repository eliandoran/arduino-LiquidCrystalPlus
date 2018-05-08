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
    int lastIndex;

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
        int charIndex;

        if (lastIndex < maxCharacters) {
            charIndex = lastIndex++;
        } else {
            charIndex = lastIndex;
        }

        display.lcd->createChar(charIndex, rows);
        charStore[charIndex] = rows;
        
        return charIndex;
    }

public:    
    CustomCharacterManager(Display &display, int maxCharacters, int charWidth, int charHeight): display(display) {
        this->maxCharacters = maxCharacters;
        this->charWidth = charWidth;
        this->charHeight = charHeight;
        this->charStore = (TRow**)calloc(maxCharacters, sizeof(TRow*));
        this->lastIndex = 0;

        uint8_t emptyChar[8] = {
            0b00000,
            0b00000,
            0b00000,
            0b00000,
            0b00000,
            0b00000,
            0b00000,
            0b00000
        };

        for (int i=0; i<maxCharacters; i++) {
            display.lcd->createChar(i, emptyChar);
        }

        delay(500);

        lastIndex = 0;
    }

    void printChar(TRow* rows) {        
        int charIndex = findCharIndex(rows);

        if (charIndex == CHAR_NOT_FOUND) {
            charIndex = loadChar(rows);

            /*
             * HACK: Interestingly enough, it seems that without repositioning the cursor the first
             * time the custom character is displayed, the character would not display at all.
             */
            uint8_t currentX = display.getCurrentX();
            uint8_t currentY = display.getCurrentY();
            display.setCursor(currentX, currentY);

            display.write((uint8_t)charIndex);
        } else {
            display.write(charIndex);
        }
    }
};

#endif
