#include "Application.h"

int main()
{
    auto app = CreateApplication(600,600);
    app->Run();
    delete app;

}
