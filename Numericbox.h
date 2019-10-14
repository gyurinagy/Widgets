#ifndef Numericbox_H_INCLUDED
#define Numericbox_H_INCLUDED

#include "Box.h"

class Numericbox : public Box {

    int _num,_min,_max,_scale;
    std::string _numinstr;

    void change(int multi, bool dir);
public:
    Numericbox(Application *p,int x, int y, int sx, int sy);
    Numericbox(Application *p,int x, int y, int sx, int sy, int num, int minn, int maxx,int scale);

    void drawText(int textColor,int x_offset,int y_offset,std::string txt) const;
    virtual void draw() const;

    virtual void handleFocus(genv::event ev);
    virtual void handleMouse(genv::event ev);

    void setScale(int num);
    void setMin(int num);
    void setMax(int num);
    void setDefNum(int num);
    void setVelues(int num, int minn, int maxx, int scl);
    int getValue() const;


};

#endif // Numericbox_H_INCLUDED
