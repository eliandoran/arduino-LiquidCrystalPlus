#ifndef WIDGET_INCLUDED
#define WIDGET_INCLUDED

#include <inttypes.h>

class Page;
class Display;

class Widget {
friend class Page;

protected:
    Page *parentPage;
    Display *display;
    unsigned int msSinceUpdate;
    uint8_t col, row;

public:
    Widget();
    Widget(uint8_t col, uint8_t row);

    void init(Page &parentPage);

    virtual void update();
    virtual bool needsUpdate();
    virtual ~Widget();

    void setPosition(uint8_t col, uint8_t row);

    Page& getParentPage();
};

#endif
