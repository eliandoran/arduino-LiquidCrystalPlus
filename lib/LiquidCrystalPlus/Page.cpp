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

Page::Page() { }
Page::~Page() { }
void Page::show() { }
void Page::loop() { }

void Page::inner_show() {
    if (!widgets.size()) return;

    Serial.print(widgets.size());
    for (int i=0; i<widgets.size(); i++) {
        Widget* widget = widgets.get(i);
        Serial.print("Widget");
        Serial.println((long)widget);

        delay(100);
        widget->update();
    }
}

void Page::inner_loop() {
    if (!widgets.size()) return;

    for (int i=0; i<widgets.size(); i++) {
        Widget* widget = widgets.get(i);
        widget->update();
        delay(100);
    }
}
