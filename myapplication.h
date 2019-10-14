#ifndef MYAPPLICATION_H_INCLUDED
#define MYAPPLICATION_H_INCLUDED

#include "Application.h"

class MyApplication : public Application
{


public:

    MyApplication(int w, int h);
    ~MyApplication();

    virtual void refreshApp();


};


#endif // MYAPPLICATION_H_INCLUDED
