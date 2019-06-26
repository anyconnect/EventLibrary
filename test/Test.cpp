#include "Test.h"
#include "EventService.h"
#include <assert.h>
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>

Test::Test()
{

}

void Test::loadLib(std::string name) 
{
  instance = NULL;
  handle = dlopen(name.c_str(), RTLD_LAZY);
	 
  if (!handle) {
    printf("%s\n", dlerror());
    return;
  }

  create = (EventService* (*)()) dlsym(handle, "create");
  destroy = (void(*)(EventService*)) dlsym(handle, "destroy");

  char* error;
  if ((error = dlerror()) != NULL) {
    printf("%s\n", error);
    return;
  }

  instance = create();
}

bool Test::isLoaded() 
{
  return instance != NULL; 
}

void Test::setEventCallback() 
{
  instance->setEventReceiveCallback([this](EventSource &source, std::string &timestamp, std::string &data, std::string &description, unsigned char* snapshot, int &length) {
    if(source == EventSource::GPS) {
      std::cout<<"Event received from GPS tracker at: "<< timestamp <<" data: "<<data<<" description: "<<description<<" snapshotdata: "<<snapshot<<" length: "<<length<<std::endl;
    }
  });
}

Test::~Test() {
  destroy(instance);
  dlclose(handle);
  handle = NULL;
}

Test *pTest = new Test();

int main()
{
  pTest->loadLib("./libevent.so");

  if(pTest->isLoaded()) {
    printf("Your AnyConnect Event Library is loaded!\n");
  }
  else {
    printf("Your AnyConnect Event Library is not loaded!\n");
  }  
  pTest->setEventCallback(); 
  while(1) {
    sleep(3);
  }
  return 0;
}
