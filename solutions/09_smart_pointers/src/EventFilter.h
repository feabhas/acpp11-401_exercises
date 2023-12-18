// EventFilter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ID_FILTER
#define ID_FILTER

#include "Event.h"

class Pipe;

class EventFilter {
public:
  EventFilter(Alarm remove_this) : filter_value{ remove_this } {}

  void execute();

private:
  Alarm filter_value{ Alarm::unknown };

  Pipe*       input{};
  Pipe*       output{};
  friend void connect(EventFilter& filter, Pipe& in, Pipe& out);
};

#endif
