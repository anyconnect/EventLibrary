#ifndef _EVENT_H_
#define _EVENT_H_

#include <functional>
#include <thread>
#include "EventService.h"

using namespace com::anyconnect::event;

class Event: public EventService {
public:
  Event();

  virtual ~Event();

  void setEventReceiveCallback(EventReceiveHandler handler);

private:
  void eventReceiveThread();  

private:
  EventReceiveHandler handler;
  bool eventThreadRunning;
  std::thread eventThread;
  
};
#endif