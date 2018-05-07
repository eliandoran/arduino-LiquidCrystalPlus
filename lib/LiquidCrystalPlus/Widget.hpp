#ifndef WIDGET_INCLUDED
#define WIDGET_INCLUDED

class Page;
class Display;

class Widget {
private:
    Page *parentPage;
    Display *display;

public:
    Widget();

    void init(Page &parentPage);

    virtual void show();
    virtual void loop();
    virtual ~Widget() = 0;

    Page& getParentPage();
};

#endif
