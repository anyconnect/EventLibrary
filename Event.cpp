#include <string>
#include <vector>
#include <unistd.h>
#include "Event.h"

Event::Event()
{
  eventThreadRunning = false;
  //Write your initialization code
}

Event::~Event()
{
  // Write your de-initialization code.
  eventThread.join();
  eventThreadRunning = false;
}

void Event::setEventReceiveCallback(EventReceiveHandler handler)
{
  // This function must be non-blocking, so we created eventReceiveThread(),
  // which must call the ADAS or sensor event receive API.
  this->handler = handler;
  if(eventThreadRunning == false) {
    eventReceiveThread();
    eventThreadRunning = true;
  }
}

void Event::eventReceiveThread()
{
  eventThread = std::thread([this] {

  // Receive data from the camera hardware (ADAS, sensor)
  // and write the data to the callback.
  //
  // For example:
  // std::string source = "ADAS";
  // std::string data = "Zebra crossing 2 meter way";
  // int length = data.length();
  // this->handler(source, data, length);
  });
}

// Create and destroy the camera's Event library instance.
extern "C" {
Event* create() {
	return new Event();
}
void destroy(Event* event) {
	delete event;
}
}
