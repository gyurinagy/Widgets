#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include "widgets.h"

class Box : public Widget {

protected:
    virtual void drawBox(int x_offset,int y_offset,int contourColor,int boxColor) const;
    virtual void drawBox(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const;

public:
    Box(Application *p, int x, int y, int sx, int sy);

    virtual void draw() const;

};

#endif // BOX_H_INCLUDED
