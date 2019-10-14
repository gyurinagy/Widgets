#ifndef TBOX_HPP_INCLUDED
#define TBOX_HPP_INCLUDED

#include "Box.h"
#include "vector"

class  Scroll: public Box {
    std::vector<std::string> _disp;
    int _direction;
    std::vector<int> _serialnumbers;

    void scrolling(int b);
    int getListSize() const{return _disp.size();}
public:
    Scroll(Application *p,int x, int y, int sx, int sy,std::vector<std::string> disp,int dir);
    Scroll(Application *p,int x, int y, int sx, int sy,std::vector<std::string> disp);
    Scroll(Application *p,int x, int y, int sx, int sy);

    void drawText(int textColor,int x_offset,int y_offset,std::string txt) const;
    virtual void draw() const;

    virtual void handleFocus(genv::event ev);
    virtual void handleMouse(genv::event ev);


    std::string getValue() const;
    int getSerNum() const;
    void setList(std::vector<std::string> vec);
    std::vector<std::string> getList() const;
    void setDirection(int dir);
    void refreshSerialNumbers();//int prevSize);

    void deleteItem(int a);
    void deleteItem(std:: string s);
    void deleteItem();
    void deleteAll();
    void addItem(std::string s);
    void changeItem(std::string s);

};

#endif // TBOX_HPP_INCLUDED
