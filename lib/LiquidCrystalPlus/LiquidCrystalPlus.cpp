#include <Arduino.h>
#include "LiquidCrystalPlus.hpp"

LiquidCrystalPlus::LiquidCrystalPlus()
{
    activePage = NULL;
}

void LiquidCrystalPlus::setPins(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
    display.setPins(rs, enable, d0, d1, d2, d3);
}

void LiquidCrystalPlus::setResolution(int columns, int rows) {
    display.setResolution(columns, rows);
}

void LiquidCrystalPlus::init() {
    display.init();
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
                activePage->inner_show();
                activePageShown = true;
            }

            activePage->inner_loop();
            activePage->loop();
        }
    }
}
