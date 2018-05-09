#include <LiquidCrystal.h>
#include <LiquidCrystalPlus.h>
#include "Display.h"

Display::Display() {
    // Set defaults
    this->columns = 16;
    this->rows = 2;
    this->charWidth = 5;
    this->charHeight = 8;
    this->maxCustomCharacters = 8;
    this->charStore = (CustomChar**)calloc(maxCustomCharacters, sizeof(CustomChar*));
    this->lastIndex = 0;
}

void Display::init() {
    lcd->begin(this->rows, this->columns);
}

uint8_t Display::getCurrentX() {
    return currentX;
}

uint8_t Display::getCurrentY() {
    return currentY;
}

/**
 * Causes the screen to be cleared.
 */
void Display::clear() {
    lcd->clear();
}

void Display::setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
    lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
}

uint8_t Display::getScreenWidth() {
    return columns;
}

uint8_t Display::getScreenHeight() {
    return rows;
}

uint8_t Display::getCharacterWidth() {
    return charWidth;
}

uint8_t Display::getCharacterHeight() {
    return charHeight;
}

uint8_t Display::getMaxCustomCharacters() {
    return maxCustomCharacters;
}

void Display::setResolution(int columns, int rows) {
    this->columns = columns;
    this->rows = rows;
}

size_t Display::write(uint8_t value) {
    lcd->write(value);
    return true;
}

void Display::setCursor(uint8_t col, uint8_t row) {
    currentX = col;
    currentY = row;

    col += xOffset;
    row += yOffset;

    lcd->setCursor(col, row);
}

void Display::refreshCursor() {
    setCursor(currentX, currentY);
}

void Display::setOffset(uint8_t xOffset, uint8_t yOffset) {
    this->xOffset = xOffset;
    this->yOffset = yOffset;
}

short Display::loadChar(CustomChar *customChar) {
    if (++lastIndex >= maxCustomCharacters)
        lastIndex = 0;    

    lcd->createChar(lastIndex, customChar);
    charStore[lastIndex] = customChar;
    
    return lastIndex;
}

void Display::printChar(CustomChar *customChar) {    
    int charIndex;

    // Treat NULL characters as blank spaces.
    if (customChar == NULL) {
        print(' ');
        return;
    }

    for (charIndex=0; charIndex<maxCustomCharacters; charIndex++) {
        if (charStore[charIndex] == customChar) {
            write((uint8_t)charIndex);
            return;
        }
    }

    charIndex = loadChar(customChar);

    /*
     * HACK: Interestingly enough, if one draws a character that was just
     * loaded via `loadChar()` it will not display at all. It seems that
     * simply repositioning the cursor to the same spot where it would
     * normally be drawn fixes the problem.
     */
    refreshCursor();

    write((uint8_t)charIndex);
}