#ifndef _EVENT_SERVICE_H_
#define _EVENT_SERVICE_H_

#include <string>
#include <vector>

namespace com {
namespace anyconnect {
namespace event {

///
/// Handler for received event.
///
/// \param[out] source - source of the event.
/// \param[out] data - event data.
/// \param[out] length - Length of the event data.
///
typedef std::function<void(std::string &source, std::string &data, int &length)> EventReceiveHandler;

class EventService{
public:
  EventService()
  {
    ;
  }
  
  ///
  /// Set a callback for receiving event from the camera hardware.
  /// (e.g., ADAS, humidity sensor, proximity sensor etc.)
  ///
  /// \param[in] EventReceiveHandler - Handler function for the received event.
  ///
  virtual void setEventReceiveCallback(EventReceiveHandler handler) = 0;

  ~EventService()
  {
    ;
  }
};

}
}
}
#endif
