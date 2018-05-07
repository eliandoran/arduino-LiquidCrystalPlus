#include "Widget.hpp"
#include "Page.hpp"

Widget::Widget() {

}

void Widget::init(Page &parentPage) {
    this->parentPage = &parentPage;
    this->display = &parentPage.getDisplay();
}

Page& Widget::getParentPage() {
    return *this->parentPage;
}

Widget::~Widget() {

}
