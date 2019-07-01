#ifndef _EVENT_SERVICE_H_
#define _EVENT_SERVICE_H_

#include <string>
#include <vector>

namespace com {
namespace anyconnect {
namespace event {

///
/// \brief Event source.
///
/// Supported event sources: accelerometer, GPS, gyrometer, and mixed.
///
enum  class EventSource { 
  ACCELEROMETER,
  GPS,
  GYROMETER,
  MIXED
};


///
/// Handler for received event.
///
/// \param[out] source - source of the event as enum.
/// \param[out] data - event data in json format. (e.g., {\"latitude\": \"1.3521 N\", \"longitude\": \"103.8198 E\"} )
/// \param[out] timestamp - time of the event in seconds (epoch unix time: 1560167845 [Monday, June 10, 2019 5:57:25 PM GMT+06:00]).
/// \param[out] description - description of the event.
/// \param[out] snapshot - pointer to snapshot data.
/// \param[out] length - length of the snapshot data.
///
typedef std::function<void(EventSource &source, std::string &timestamp, std::string &data, std::string &description, unsigned char* snapshot, int &length)> EventReceiveHandler;

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
