// Event.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"
#include <cstring>
#include <functional>

#ifdef TRACE_ENABLED
#include <iostream>
#define TRACE(msg)                                                             \
  std::cout << "Event: " << as_string() << " : " << msg << '\n'
#else
#define TRACE(msg)
#endif


static char const* strings[]{ "unknown  ",
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

Event::Event(Alarm init, char const* str) : event_type{ init }
{
  TRACE("Non-default ctor with string");

  if (str) {
    description = new char[strlen(str) + 1];
    strcpy(description, str);
  }
}

Event::~Event()
{
  TRACE("Dtor");

  delete[] description;
}

Event::Event(const Event& src) : Event{ src.event_type, src.description }
{
  TRACE("Copy ctor");
}

Event& Event::operator=(const Event& rhs)
{
  TRACE("Copy assignment");
  Event temp{rhs};
  swap(*this, temp);
  return *this;
}

Alarm Event::type() const
{
  return event_type;
}

char const* Event::as_string() const
{
  return strings[static_cast<int>(event_type)];
}

char const* Event::what() const
{
  return (description ? description : "");
}

void swap(Event& lhs, Event& rhs)
{
  using std::swap;
  swap(lhs.event_type, rhs.event_type);
  swap(lhs.description, rhs.description);
}
