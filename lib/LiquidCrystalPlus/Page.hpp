#ifndef PAGE_INCLUDED
#define PAGE_INCLUDED

#include <LinkedList.h>
#include "Widget.hpp"

class LiquidCrystalPlus;
class Display;

class Page {
protected:
    LiquidCrystalPlus *lcd;
    Display *display;
    LinkedList<Widget*> widgets;
    unsigned long lastUpdateTime;

public:
    Page();

    void init(LiquidCrystalPlus &lcd);
    Display& getDisplay();

    void add(Widget &widget);
    void add(Widget *widget);

    void inner_show();
    void inner_loop();

    virtual void show();
    virtual void loop();
    virtual ~Page() = 0;
};

#endif
