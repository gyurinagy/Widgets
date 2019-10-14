 #include "graphics.hpp"
 #include "Application.h"

#include "iostream"

using namespace genv;


Application::Application(int w, int h) : _width(w), _height(h), _focus(-1),_mouse(-1), _r(0), _g(0), _b(0){

}

Application::~Application(){

}
void Application::RegisterWidget(Widget* w){
    _widgets.push_back(w);
}

void Application::setBackgroundColor(int r, int g, int b){
    _r=r;
    _g=g;
    _b=b;
}

void Application::Run(){


    gout.open(_width,_height);
    gout<<move_to(0,0)<<color(_r,_g,_b)<<box_to(_width-1,_height-1)<<refresh;
    event ev;


    while(gin >> ev && ev.keycode != key_escape) {


        ///EGÉR RÁVITEL
        if (ev.type == ev_mouse) {

            for (size_t i=0;i<_widgets.size();i++)
                { _widgets[i]->setMouse(false);_mouse=-1;}

            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)){
                    _mouse=i;

                    //if((_widgets[_mouse]->mouseCanChangeTheLook())) {_widgets[i]->setMouse(true);}
                }

            }

            /// KATTINTÁS KEZELÉSE
            if(ev.button == btn_left){
                for (size_t i=0;i<_widgets.size();i++)
                    {_widgets[i]->setFocus(false);_focus=-1;}

                for (size_t i=0;i<_widgets.size();i++) {
                    if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)){
                        _focus = i;
                        //if((_widgets[_focus]->isFocusable())) {_widgets[i]->setFocus(true);}

                    }
                }
            }
        }





         /// TAB
        if(ev.keycode == key_tab){


            for (size_t i=0;i<_widgets.size();i++){
                if(_widgets[i]->getFocus()){
                    _focus = i;
                    break;
                }

            }
            if(_focus!=-1) _widgets[_focus]->setFocus(false);


            if(_widgets.size()>1){

                if(_focus==-1 || _focus==_widgets.size()-1){
                    _focus=0;

                    if(!(_widgets[_focus]->isFocusable())) {_focus++;}

                }else{
                    _focus++;

                    if(!(_widgets[_focus]->isFocusable())) {_focus++;}

                    if(_focus>_widgets.size()-1) {_focus =0;}

                }
            }

        }


        if (_mouse!=-1) { _widgets[_mouse]->handleMouse(ev); }
        if (_focus!=-1) { _widgets[_focus]->handleFocus(ev); }

        for( auto w : _widgets){ w->draw();}
        gout<<refresh;

    }

}

