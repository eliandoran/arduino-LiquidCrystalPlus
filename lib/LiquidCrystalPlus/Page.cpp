#include <LinkedList.h>
#include <LiquidCrystalPlus.hpp>
#include <Arduino.h>
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
    add(&widget);
}

void Page::add(Widget *widget) {
    widgets.add(widget);
    widget->init(*this);
}

void Page::add(Widget &widget, uint8_t col, uint8_t row) {
    add(&widget, col, row);
}

void Page::add(Widget *widget, uint8_t col, uint8_t row) {
    widget->setPosition(col, row);
    add(widget);
}

Page::Page() { }
Page::~Page() { }
void Page::show() { }
void Page::loop() { }

void Page::inner_show() {
    if (!widgets.size()) return;

    lastUpdateTime = millis();

    for (int i=0; i<widgets.size(); i++) {
        Widget* widget = widgets.get(i);
        updateWidget(*widget);
    }
}

inline void Page::updateWidget(Widget &widget) {
    display->setOffset(widget.col, widget.row);
    display->setCursor(0, 0);
    widget.update();
}

void Page::inner_loop() {
    if (!widgets.size()) return;

    unsigned int timePassed = millis() - lastUpdateTime;

    for (int i=0; i<widgets.size(); i++) {
        Widget* widget = widgets.get(i);
        widget->msSinceUpdate += timePassed;

        if (widget->needsUpdate()) {
            updateWidget(*widget);
            widget->msSinceUpdate = 0;
        }
    }

    lastUpdateTime += timePassed;
}
