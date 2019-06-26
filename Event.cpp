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
  // EventSource source = EventSource::GPS;
  // std::string timestamp = "1560167845";
  // std::string data = "{\"latitude\": \"1.3521 N\", \"longitude\": \"103.8198 E\"}";
  // std::string description = "Singapore, Asia";
  // unsigned char* snapshot = (unsigned char*) malloc(yourSnapshotSize);
  // int length = yourSnapshotSize;
  // memcpy(snapshot, *yourSnapshotPointer, length);
  // this->handler(source, timestamp, data, description, snapshot, length);
  
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
