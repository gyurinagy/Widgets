#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED


#include "Box.h"
#include "Application.h"

class Checkbox : public Box {
protected:
    bool _checked;
public:
    Checkbox(Application *p,int x, int y, int sx, int sy);

    virtual void drawX(int collour) const;
    virtual void draw() const;

    virtual void handleFocus(genv::event ev);
    virtual void handleMouse(genv::event ev);

    virtual bool is_checked() const;

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
