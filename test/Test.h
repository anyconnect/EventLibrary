#include "EventService.h"
#include <functional>

using namespace com::anyconnect::event;

class Test {
void* handle;
EventService* instance;
EventService* (*create)();
void (*destroy)(EventService*);

public:
  Test();
  ~Test();
void loadLib(std::string name);
bool isLoaded();
void setEventCallback();
 
};

