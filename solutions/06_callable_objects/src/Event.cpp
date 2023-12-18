// Event.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"

#ifdef TRACE_ENABLED
#include <iostream>
#define TRACE(msg)                                                             \
  std::cout << "Event: " << as_string() << " : " << msg << '\n'
#else
#define TRACE(msg)
#endif

static const char* strings[]{ "unknown  ",
                              "advisory ",
                              "caution  ",
                              "warning  " };

Event::Event()
{
  TRACE("Default ctor");
}

Event::Event(Alarm init) : event_type{ init }
{
  TRACE("Non-default ctor");
}

Event::~Event()
{
  TRACE("Dtor");
}

Event::Event(const Event& src) : Event{ src.event_type }
{
  TRACE("Copy ctor");
}

Event& Event::operator=(const Event& rhs)
{
  TRACE("Copy assignment");

  event_type = rhs.event_type;
  return *this;
}

Alarm Event::type() const
{
  return event_type;
}

const char* Event::as_string() const
{
  return strings[static_cast<int>(event_type)];
}
