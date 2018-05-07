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

public:
    Page();

    void init(LiquidCrystalPlus &lcd);
    Display& getDisplay();
    void add(Widget &widget);

    virtual void show();
    virtual void loop();
    virtual ~Page() = 0;
};

#endif
