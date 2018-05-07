#include "Widget.hpp"
#include "Page.hpp"
#include <Arduino.h>

void Widget::init(Page &parentPage) {
    this->parentPage = &parentPage;
    this->display = &(parentPage.getDisplay());
}

Page& Widget::getParentPage() {
    return *this->parentPage;
}

Widget::Widget() { }
Widget::~Widget() {}

void Widget::update() {}

bool Widget::needsUpdate() {
    return false;
}
