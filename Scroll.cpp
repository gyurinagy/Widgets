#include "Scroll.h"
#include "graphics.hpp"


using namespace genv;

std::vector<int> setSerNums(int siz){
    std::vector<int> vec;
    if(siz>1){
        vec.push_back(0);
        vec.push_back(siz-1);
        vec.push_back(siz-2);
        vec.push_back(1);
    }else{

        for (int i = 0;i< 4;i++ ){ vec.push_back(0); }
    }

    return vec;
}
/// KONSTRUKTOR
Scroll::Scroll(Application *p,int x, int y, int sx, int sy,std::vector<std::string> disp,int dir)
    : Box(p,x,y,sx,sy),_disp(disp),_direction(dir),_serialnumbers(setSerNums(getListSize())){ }

Scroll::Scroll(Application *p,int x, int y, int sx, int sy,std::vector<std::string> disp)
    : Box(p,x,y,sx,sy),_disp(disp),_direction(1),_serialnumbers(setSerNums(getListSize())){ }

Scroll::Scroll(Application *p,int x, int y, int sx, int sy)
    : Box(p,x,y,sx,sy),_disp(std::vector<std::string> {}),_direction(1),_serialnumbers(setSerNums(getListSize())){ }


/// DRAW
void Scroll::drawText(int textColor,int x_offset,int y_offset,std::string txt) const{
    gout<<color(textColor,textColor,textColor)<<move_to(_x+x_offset,_y+y_offset)<<text(txt);
}

void Scroll::draw() const{


      if(_infocus){

        // FELSÕ ELEM
        drawBox(_direction*20,-_sy-5,15,15);
        if(_disp.size()>0)
            drawText(100,_direction*20+_sx/2 -gout.twidth(_disp[_serialnumbers[_serialnumbers.size()-1]])/2,_sy/2+4-_sy-5,_disp[_serialnumbers[3]]);

        // KÖZÉPSÕ ELEM
        drawBox(0,0,77, 204, 255,25);
        if(_disp.size()>0)
            drawText(255,_sx/2 -gout.twidth(_disp[_serialnumbers[0]])/2,+_sy/2+4,_disp[_serialnumbers[0]]);

        // ALSÓ ELEM 1
        drawBox(_direction*20,+_sy+5,15,15);
        if(_disp.size()>0)
            drawText(100,_direction*20+_sx/2 -gout.twidth(_disp[_serialnumbers[1]])/2,_sy/2+4+_sy+5,_disp[_serialnumbers[1]]);

        // ALSÓ ELEM 2
        drawBox(_direction*50,+2*_sy +10,15,15);
        if(_disp.size()>0)
            drawText(50,_direction*50 +_sx/2 -gout.twidth(_disp[_serialnumbers[2]])/2,+_sy/2+4 +2*_sy +10,_disp[_serialnumbers[2]]);

    }else if(_mouseOn){

        // FELSÕ ELEM
        drawBox(_direction*20,-_sy-5,50,15);
        if(_disp.size()>0)
            drawText(160,_direction*20+_sx/2 -gout.twidth(_disp[_serialnumbers[_serialnumbers.size()-1]])/2,_sy/2+4-_sy-5,_disp[_serialnumbers[3]]);

        // KÖZÉPSÕ ELEM
        drawBox(0,0,250,30);
        if(_disp.size()>0)
            drawText(255,_sx/2 -gout.twidth(_disp[_serialnumbers[0]])/2,+_sy/2+4,_disp[_serialnumbers[0]]);

        // ALSÓ ELEM 1
        drawBox(_direction*20,+_sy+5,50,15);
        if(_disp.size()>0)
            drawText(160,_direction*20+_sx/2 -gout.twidth(_disp[_serialnumbers[1]])/2,_sy/2+4+_sy+5,_disp[_serialnumbers[1]]);

        // ALSÓ ELEM 2
        drawBox(_direction*50,+2*_sy +10,25,15);
        if(_disp.size()>0)
            drawText(65,_direction*50 +_sx/2 -gout.twidth(_disp[_serialnumbers[2]])/2,+_sy/2+4 +2*_sy +10,_disp[_serialnumbers[2]]);


    }else{

        gout<<color(15,15,15)<<move_to(_x+_direction*20, _y-_sy-5)  <<box(_sx,_sy);
        gout<<color(15,15,15)<<move_to(_x+_direction*20, _y+_sy+5)  <<box(_sx,_sy);
        gout<<color(15,15,15)<<move_to(_x+_direction*50, _y +2*_sy +10)  <<box(_sx,_sy);
        gout<<color(15,15,15)<<move_to(_x,_y)   <<box(_sx,_sy);

        drawBox(0,0,150,15);
        if(_disp.size()>0)
            drawText(255,+_sx/2 -gout.twidth(_disp[_serialnumbers[0]])/2,+_sy/2+4,_disp[_serialnumbers[0]]);

    }

}
/// GETTER/SETTER
std::string Scroll::getValue() const{ return _disp[_serialnumbers[0]]; }

int Scroll::getSerNum() const{ return _serialnumbers[0];}

void Scroll::setList(std::vector<std::string> vec){
    _disp = vec;
}
std::vector<std::string> Scroll::getList() const{
    return _disp;
}

void Scroll::setDirection(int dir){
    if(dir<0) _direction = -1;
    else _direction=1;
}


void Scroll::refreshSerialNumbers(){//int prevSize){


    if(getListSize()<=1){
        for (int i = 0;i< 4;i++ ){ _serialnumbers[i]=0; }

    }else if(getListSize()==2){
        _serialnumbers[0]=0;
        _serialnumbers[1]=1;
        _serialnumbers[2]=0;
        _serialnumbers[3]=1;

    } else{
        _serialnumbers[0]=0;
        _serialnumbers[1]=1;
        _serialnumbers[2]=2;
        _serialnumbers[3]=_disp.size()-1;

    }

}

/// ADD / DELETE
void Scroll::deleteItem(int a){
    if(a<_disp.size() || a>0){
        if(_disp.size()>0){
            _disp.erase (_disp.begin()+a);
            refreshSerialNumbers();

        }
    }
}
void Scroll::deleteItem(std::string s){
    if(_disp.size()>0){
        for (int i = 0;i< _disp.size();i++ ){
            if(_disp[i]==s){
                _disp.erase (_disp.begin()+i);
            }
        }
        refreshSerialNumbers();


    }
}
void Scroll::deleteItem(){
    if(_disp.size()>0){
        _disp.erase(_disp.begin()+_serialnumbers[0]);
        refreshSerialNumbers();
    }

}
void Scroll::deleteAll(){
    _disp.clear();
    refreshSerialNumbers();

}

void Scroll::addItem(std::string s){
    if(s!=""){
        _disp.push_back(s);
        refreshSerialNumbers();
    }

}
void Scroll::changeItem(std::string s){
    _disp[_serialnumbers[0]] = s;
}

/// HANDLE
void Scroll::handleFocus(event ev){
    _infocus = true;
}
void Scroll::handleMouse(event ev){
    _mouseOn=true;

    if(ev.button==btn_wheeldown ){
        scrolling(-1);
    }else if(ev.button==btn_wheelup )
        scrolling(1);
}

///MECHANIKA

void Scroll::scrolling(int b){

    if(!_infocus){

        for (unsigned int i = 0;i< _serialnumbers.size();i++ ){

            _serialnumbers[i]+=b;

            if(_serialnumbers[i] < 0) {_serialnumbers[i] = _disp.size()-1;}
            else if(_serialnumbers[i] > _disp.size()-1) {_serialnumbers[i] = 0;}
        }
    }

}







