#include "Statictext.h"
#include "graphics.hpp"


StaticText::StaticText(Application* p,int x, int y, int sx, int sy, std::string txt)
    : Widget(p,x,y,sx,sy){
        _alltxt.push_back(txt);
        _disptxt = _alltxt[0];
        _sx = genv::gout.twidth(_disptxt)+10;
    }

void StaticText::draw() const{
    genv::gout<<genv::color(137, 133, 128)<<genv::move_to(_x ,_y )  <<genv::box(_sx,_sy);
    genv::gout<<genv::color(255,255,255)<<genv::move_to(_x+10,_y+_sy/2)<<genv::text(_disptxt);
}

void StaticText::setText(std::string tmp){
    _sx = genv::gout.twidth(_disptxt)+10;
    _disptxt=tmp;
}

void StaticText::addText(std::string tmp){
    _disptxt+=tmp;
}

std::string StaticText::getText() const{
    return _disptxt;
}
bool StaticText::isFocusable(){
    return false;
}
bool StaticText::mouseCanChangeTheLook(){
    return false;
}

/// HANDLE
// LEHET BELE SE KÉNE RAKNI A .h FÁJLBBA
void StaticText::handleFocus(genv::event ev){}
void StaticText::handleMouse(genv::event ev){}

