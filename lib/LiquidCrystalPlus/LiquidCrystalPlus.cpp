#include <Arduino.h>
#include <LiquidCrystal.h>
#include "LiquidCrystalPlus.hpp"

LiquidCrystalPlus::LiquidCrystalPlus()
{
    activePage = NULL;

    // Set defaults
    this->columns = 16;
    this->rows = 2;
}

void LiquidCrystalPlus::setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
    this->lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
}

void LiquidCrystalPlus::setResolution(int columns, int rows) {
    this->columns = columns;
    this->rows = rows;
}

void LiquidCrystalPlus::init() {
    this->display = new Display(*this->lcd);
    this->lcd->begin(this->rows, this->columns);
}

void LiquidCrystalPlus::show(Page *page) {
    if (activePage != NULL) {
        delete activePage;
    }

    activePage = page;
    activePageShown = false;
}

void LiquidCrystalPlus::doLoop() {
    while (1) {
        if (activePage != NULL) {
            if (!activePageShown) {
                activePage->init(*this);
                activePage->show();
                activePageShown = true;
            }

            activePage->loop();
        }
    }
}
