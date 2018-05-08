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
        for (int i=0; i<maxCharacters; i++) {
            if (charStore[i] == rows)
                return i;        
        }
        
        return CHAR_NOT_FOUND;
    }

    short loadChar(TRow* rows) {
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
    }

    void printChar(TRow* rows) {        
        int charIndex = findCharIndex(rows);

        if (charIndex == CHAR_NOT_FOUND) {
            charIndex = loadChar(rows);

            /*
             * HACK: Interestingly enough, if one draws a character that was just
             * loaded via `loadChar()` it will not display at all. It seems that
             * simply repositioning the cursor to the same spot where it would
             * normally be drawn fixes the problem.
             */
            display.refreshCursor();

            display.write((uint8_t)charIndex);
        } else {
            display.write(charIndex);
        }
    }
};

#endif
