#include "graphics.hpp"
#include "myapplication.h"

#include "sstream"
#include "vector"

using namespace genv;

std::string convertS(int a){
    std::stringstream ss;
    ss<<a;
    return ss.str();
}

Application* CreateApplication(int w, int h){
    return new MyApplication(w,h);
}


MyApplication::MyApplication(int w, int h): Application(w,h){
    //std::vector<std::string> disp1 = {"Red","Blue","Green","Purple","Orange","Yellow","Black","Grey","White"};

}

MyApplication::~MyApplication(){}

void MyApplication::refreshApp(){

}





