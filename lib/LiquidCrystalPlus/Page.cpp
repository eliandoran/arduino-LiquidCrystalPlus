#include <LinkedList.h>
#include <LiquidCrystalPlus.hpp>
#include "Page.hpp"
#include "Widget.hpp"

void Page::init(LiquidCrystalPlus &lcd) {
    this->lcd = &lcd;
    this->display = &lcd.display;
    this->display->clear();
}

Display& Page::getDisplay() {
    return *this->display;
}

void Page::add(Widget &widget) {
    widgets.add(&widget);
}

Page::Page() {
}

void Page::show() {

}

void Page::loop() {

}

Page::~Page() {
    // No action needed.
}
