#include "TextCtrl.h"
#include "graphics.hpp"

using namespace genv;



char atalakito(int b){
    char a = 'A';
    char txt;

    for (int i = 65;i<91 ;i++ ){

        if(i == b){
            txt = a;
            return txt;
        }
        a++;
    }
    a='a';
    for (int i = 97;i<123 ;i++ ){

        if(i == b){
            txt = a;
            return txt;
        }
        a++;
    }
    return ' ';

}

/// KONSTRUKTOR
Textctrl::Textctrl(Application *p,int x, int y,int sx, int sy): Box(p,x,y,sx,sy),_disptxt(""){}



/// DRAW
void Textctrl::drawText() const{
    gout<<color(255,255,255)<<move_to(_x+10,_y+20)<<text(_disptxt);
}

void Textctrl::draw() const{
    if(_infocus){
        drawBox(0,0,30,10);
        drawText();
    }else if(_mouseOn){
        drawBox(0,0,70,40);
        drawText();
    }else{
        drawBox(0,0,50,20);
        drawText();
    }
}

/// GETTER/SETTER
void Textctrl::setText(std::string s){
    _disptxt = s;
}


/// HANDLE
void Textctrl::handleFocus(event ev){

    _infocus= true;

    if(ev.type == ev_key){
        if( (ev.keycode >64 && ev.keycode < 91) || (ev.keycode>=97 && ev.keycode<=122)){
            ss.put(atalakito(ev.keycode));
            if(_disptxt!=""){_disptxt += ss.str();}
            else{_disptxt = ss.str();}
                ss.str("");
        }
        if(ev.keycode == key_backspace){

            if(_disptxt.length()!=0){_disptxt = _disptxt.substr(0,_disptxt.length()-1);}
        }
    }
}
void Textctrl::handleMouse(genv::event ev){
    _mouseOn=true;
}
