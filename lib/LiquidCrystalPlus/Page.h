#ifndef PAGE_INCLUDED
#define PAGE_INCLUDED

#include <LinkedList.h>
#include "Widget.h"

class LiquidCrystalPlus;
class Display;

class Page {
private:
    inline void updateWidget(Widget &widget);

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
    void add(Widget &widget, uint8_t col, uint8_t row);
    void add(Widget *widget, uint8_t col, uint8_t row);

    void inner_show();
    void inner_loop();

    virtual void show();
    virtual void loop();
    virtual ~Page() = 0;
};

#endif
