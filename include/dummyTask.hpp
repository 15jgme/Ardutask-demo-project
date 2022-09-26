#include <Task.h>
#include <helpers.h>
// #include <windows.h>
// #include <iostream>

class DummyTask : public Task
{
    public:
    DummyTask(float rate_des);
    int init() override;
    int update() override;
    bool ledOn = false;
    // DWORD tlast = GetTickCount();
};

DummyTask::DummyTask(float rate_des):Task(rate_des){}

int DummyTask::init()
{
    // tlast = GetTickCount();
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    log_m("hello world");
    return 1;
}

int DummyTask::update()
{
    // std::cout<<(float(GetTickCount()-tlast)/1000.0f)<<std::endl;
    // tlast = GetTickCount();
    if(ledOn)
    {
        digitalWrite(13, LOW);
        ledOn = false;
    }else{
        digitalWrite(13, HIGH);
        ledOn = true;
    }
    // log_m("foo");
    return 1;
}

DummyTask dt = DummyTask(99.0f); //initialize at 1hz