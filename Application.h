#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include "widgets.h"
#include "vector"

class Application
{
protected:
    int _width, _height;
    int _focus, _mouse;
    unsigned int _r;
    unsigned int _g;
    unsigned int _b;

    std::vector<Widget*> _widgets;
    virtual void refreshApp()=0;


public:
    Application(int w, int h);
    virtual ~Application();

    virtual void Run();
    virtual void RegisterWidget(Widget* w);
    virtual void setBackgroundColor(int r, int g, int b);


};

extern Application* CreateApplication(int w, int h);



#endif // APPLICATION_H_INCLUDED
