#include <Task.h>
#include <helpers.h>
// #include <windows.h>
// #include <iostream>

class DummyTask2 : public Task
{
    public:
    DummyTask2(float rate_des);
    int init() override;
    int update() override;
    // DWORD tlast = GetTickCount();
};

DummyTask2::DummyTask2(float rate_des):Task(rate_des){}

int DummyTask2::init()
{
    // tlast = GetTickCount();
    log_m("bar");
    return 1;
}

int DummyTask2::update()
{
    // log_m("bar");
    // std::cout<<(float(GetTickCount()-tlast)/1000.0f)<<std::endl;
    // tlast = GetTickCount();
    std::cout<<("foo")<<std::endl;
    return 1;
}

DummyTask2 dt2 = DummyTask2(1.0f); //initialize at 1hz