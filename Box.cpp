#include "Box.h"
#include "graphics.hpp"

using namespace genv;

Box::Box(Application *p, int x, int y, int sx, int sy):Widget(p,x,y,sx,sy){}

void Box::drawBox(int x_offset,int y_offset,int contourColor,int boxColor) const{
    gout<<color(contourColor,contourColor,contourColor)<<move_to(_x + x_offset,_y + y_offset)  <<box(_sx,_sy);
    gout<<color(boxColor,boxColor,boxColor) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<box(_sx-2,_sy-2);
}
void Box::drawBox(int x_offset,int y_offset,int contour_r,int contour_g,int contour_b,int boxColor) const{
    gout<<color(contour_r,contour_g,contour_b)<<move_to(_x + x_offset,_y + y_offset)  <<box(_sx,_sy);
    gout<<color(boxColor,boxColor,boxColor) <<move_to(_x+x_offset +1, _y+1 +y_offset)<<box(_sx-2,_sy-2);
}

void Box::draw() const{
    drawBox(0,0,30,40);
}
