#ifndef WIDGETS_H_INCLUDED
#define WIDGETS_H_INCLUDED

#include "graphics.hpp"

class Application;

class Widget {
protected:

    int _x, _y, _sx, _sy;
    Application *_parent;
    bool _infocus;
    bool _mouseOn;

public:

    Widget(Application *p,int x, int y, int sx, int sy);

    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handleFocus(genv::event ev) = 0;
    virtual void handleMouse(genv::event ev) = 0;

    /// Getterek
    virtual int getX() const{return _x;}
    virtual int getY() const{return _y;}
    virtual int getSizeX() const{return _sx;}
    virtual int getSizeY() const{return _sx;}

    /// Focuszálható-e egy widget, és segédfüggvények
    void setFocus(bool f);
    bool getFocus() const;
    virtual bool isFocusable();

    /// Egér rávitel megváltoztathatja-e a kinézetet
    void setMouse(bool m);
    virtual bool mouseCanChangeTheLook();

};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_H_INCLUDED
