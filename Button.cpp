#include "button.h"
#include "graphics.hpp"


using namespace genv;


Button::Button(Application* p,int x, int y, int sx, int sy ,std::function<void()> func)
    : Box(p,x,y,sx,sy), _func(func){

}
/// DRAW
void Button::draw() const{
    if(_infocus){
        drawBox(0,0,77, 204, 255,25);
    }else if(_mouseOn){
        drawBox(0,0,70,40);
    }else{
        drawBox(0,0,50,20);
    }

}
/// HANDLE
void Button::handleFocus(event ev){

    _infocus = true;

    if( ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y))
        { _func(); }

}
void Button::handleMouse(event ev){
    _mouseOn=true;
}

