// Event.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENT_H
#define EVENT_H

enum class Alarm { unknown, advisory, caution, warning };

class Event {
public:
  Event();
  Event(Alarm init);
  ~Event();

  // Copy interface
  //
  Event(const Event& src);
  Event& operator=(const Event& rhs);

  Alarm       type() const;
  char const* as_string() const;

private:
  Alarm event_type{ Alarm::unknown };
};

#endif
