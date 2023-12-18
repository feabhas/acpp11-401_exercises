// Event.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"

static char const* strings[]{ "unknown  ",
                              "advisory ",
                              "caution  ",
                              "warning  " };

Event::Event(Alarm init) : event_type{ init } {}

Alarm Event::type() const
{
  return event_type;
}

char const* Event::as_string() const
{
  return strings[static_cast<int>(event_type)];
}
