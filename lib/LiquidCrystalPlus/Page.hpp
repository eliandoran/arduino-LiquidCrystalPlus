class LiquidCrystalPlus;
class Display;

#ifndef PAGE_INCLUDED
#define PAGE_INCLUDED

class Page {
protected:
    LiquidCrystalPlus *lcd;
    Display *display;
public:
    void init(LiquidCrystalPlus &lcd);
    virtual void show();
    virtual void loop();
};

#endif
