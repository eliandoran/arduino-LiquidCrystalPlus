#include "Widget.hpp"
#include "Page.hpp"
#include <Arduino.h>

Widget::Widget() {

}

void Widget::init(Page &parentPage) {
    this->parentPage = &parentPage;
    this->display = &(parentPage.getDisplay());
}

Page& Widget::getParentPage() {
    return *this->parentPage;
}

void Widget::show() {
    Serial.println("WTF.");
}

void Widget::loop() {
    ;
}

Widget::~Widget() {

}
