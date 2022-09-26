#include "Ardutask.h"
#include "helpers.h"

Taskmanager* taskMan;

#ifdef EMBEDDED
#include <Arduino.h>
#include "dummyTask.hpp"

void setup() {
  // put your setup code here, to run once:
  // while(!Serial.available()){};
  taskMan = new Taskmanager();
  taskMan->addtask(&dt);
  // taskMan->addtask(&dt2);
}

void loop() {
  // put your main code here, to run repeatedly:
  taskMan->run();
  }
#endif

#ifdef NATIVE
#include <iostream>
#include <windows.h>
#include "dummyTask2.hpp"
#include <stdio.h>

bool firstRun = true;
// MSG msg;

int main()
{
  while(true)
  {
    if(firstRun)
    {
      taskMan = new Taskmanager();
      // taskMan->addtask(&dt);
      taskMan->addtask(&dt2);
      firstRun = false;
    }
    // log_m("begin");
    taskMan->run();
    
    runMsgPump();
  }
}

#endif