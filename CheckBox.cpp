#include "CheckBox.h"
#include "graphics.hpp"


using namespace genv;


Checkbox::Checkbox(Application *p,int x, int y, int sx, int sy)
    : Box(p,x,y,sx,sy), _checked(false){}

/// DRAW
void Checkbox::drawX(int collour) const{
    gout << color(collour,collour,collour);
    gout << move_to(_x+2, _y+2) << line(_sx-2, _sy-2);
    gout << move_to(_x+3, _y+2) << line(_sx-2, _sy-2);
    gout << move_to(_x+2, _y+_sy) << line(_sx-2, -_sy+4);
    gout << move_to(_x+3, _y+_sy) << line(_sx-2, -_sy+4);
}

void Checkbox::draw() const{


    if(_infocus){

        drawBox(2,2,255,0);
        if (_checked)
            { drawX(255); }

    }else if(_mouseOn){
        drawBox(2,2,180,0);
        if (_checked)
            { drawX(255); }
    }else{

        drawBox(2,2,100,0);
        if (_checked)
            { drawX(255); }

    }
}
/// HANDLE
void Checkbox::handleFocus(event ev)
{
    _infocus= true;

    if ( is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left ) {
        _checked = !_checked;
    }
}

void Checkbox::handleMouse(event ev){

    _mouseOn=true;
    if ( ev.keycode == key_enter )
        { _checked = !_checked; }


}

/// MECHANIKA
bool Checkbox::is_checked() const
    { return _checked; }

