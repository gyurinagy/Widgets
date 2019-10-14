#ifndef STATICTEXT_H_INCLUDED
#define STATICTEXT_H_INCLUDED

#include "widgets.h"
#include "vector"


class StaticText : public Widget {
    std::vector<std::string> _alltxt;
    std::string _disptxt;


public:
    StaticText(Application* p,int x, int y, int sx, int sy,std::string txt);
    virtual void draw() const;
    virtual void handleFocus(genv::event ev);
    virtual void handleMouse(genv::event ev);

    void setText(std::string tmp);
    void addText(std::string tmp);
    std::string getText() const;
    virtual bool isFocusable();
    virtual bool mouseCanChangeTheLook();

};

#endif // STATICTEXT_H_INCLUDED
