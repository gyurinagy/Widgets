#include "Numericbox.h"
#include "graphics.hpp"


#include <sstream>

using namespace genv;

std::string intToString(int num){
    std::stringstream ss;
    ss<<num;
    return ss.str();
}

/// KONSTRUKTOROK
Numericbox::Numericbox(Application *p,int x, int y, int sx, int sy, int num,int minn, int maxx, int scale)
    : Box(p,x,y,sx,sy), _num(num), _min(minn), _max(maxx), _scale(scale),_numinstr(intToString(_num)){}

Numericbox::Numericbox(Application *p,int x, int y, int sx, int sy)
    : Box(p,x,y,sx,sy), _num(1), _min(0), _max(10), _scale(1),_numinstr(intToString(_num)){}

/// DRAW
void Numericbox::drawText(int textColor,int x_offset,int y_offset,std::string txt) const{

    gout<<color(textColor,textColor,textColor)<<move_to(_x+x_offset,_y+y_offset)<<text(txt);
}


void Numericbox::draw() const{

    if(_infocus){
        drawBox(0,0,77, 204, 255,25);
        drawText(255,10,_sy/2+4,_numinstr);

    }else if(_mouseOn){
        drawBox(0,0,200,25);
        drawText(255,10,_sy/2+4,_numinstr);

    }else{
        drawBox(0,0,150,15);
        drawText(255,10,_sy/2+4,_numinstr);
    }
}

/// SETTER/GETTER
void Numericbox::setScale(int num)  { _scale = num; }
void Numericbox::setMin(int num)    { _min = num; }
void Numericbox::setMax(int num)    { _max = num; }
void Numericbox::setDefNum(int num) { _num = num; }
void Numericbox::setVelues(int num, int minn, int maxx, int scl)
    { _scale = num; _min = num; _max = num; _num = num; }
int Numericbox::getValue() const{ return _num; }

/// HANDLE
void Numericbox::handleFocus(event ev){

    _infocus= true;

    if(ev.keycode == key_down)    { change(1,false); }
    else if(ev.keycode == key_up) { change(1,true);  }

    if(ev.keycode == key_pgdn)    { change(10,false); }
    else if(ev.keycode == key_pgup) { change(10,true);  }

}
void Numericbox::handleMouse(event ev){
    _mouseOn=true;
}

/// MECHANIKA
void Numericbox::change(int multi,bool dir){

    if(dir) { _num+=multi*_scale; }
    else    { _num-=multi*_scale; }

    if(_num>_max)      { _num=_min; }
    else if(_num<_min) { _num=_max; }

    _numinstr = intToString(_num);
}






