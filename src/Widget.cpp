#include "Widget.h"
#include "Page.h"
#include <Arduino.h>

void Widget::init(Page &parentPage) {
    this->parentPage = &parentPage;
    this->display = &(parentPage.getDisplay());
}

Page& Widget::getParentPage() {
    return *this->parentPage;
}

Widget::Widget() {
    setPosition(0, 0);
}

Widget::Widget(uint8_t col, uint8_t row) {
    setPosition(col, row);
}

Widget::~Widget() {}

void Widget::update() {}

bool Widget::needsUpdate() {
    return false;
}

void Widget::setPosition(uint8_t col, uint8_t row) {
    this->col = col;
    this->row = row;
}
