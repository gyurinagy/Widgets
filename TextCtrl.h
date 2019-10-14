#ifndef TEXTCTRL_H_INCLUDED
#define TEXTCTRL_H_INCLUDED

#include "Box.h"
#include "vector"
#include "sstream"

class Textctrl : public Box {

    std::string _disptxt;
    std::vector<std::string> _disptxtvec;
    std::stringstream ss;

public:
    Textctrl(Application *p,int x, int y,int sx, int sy);

    void draw() const;
    void drawText() const;

    std::string getText() const{return _disptxt;}
    void setText(std::string s);

    void handleFocus(genv::event ev);
    void handleMouse(genv::event ev);

};


#endif // TEXTCTRL_H_INCLUDED
