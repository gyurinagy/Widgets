#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <functional>
#include "Box.h"

class Button : public Box {

    std::function<void()> _func;


public:
    Button(Application* p,int x, int y, int sx, int sy,std::function<void()> func);

    virtual void draw() const;

    virtual void handleFocus(genv::event ev);
    virtual void handleMouse(genv::event ev);

};

#endif // BUTTON_H_INCLUDED
