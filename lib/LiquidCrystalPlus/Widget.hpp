#ifndef WIDGET_INCLUDED
#define WIDGET_INCLUDED

class Page;
class Display;

class Widget {
friend class Page;

protected:
    Page *parentPage;
    Display *display;
    unsigned int msSinceUpdate;

public:
    Widget();

    void init(Page &parentPage);

    virtual void update();
    virtual bool needsUpdate();
    virtual ~Widget();

    Page& getParentPage();
};

#endif
