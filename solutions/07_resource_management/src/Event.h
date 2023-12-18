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
  Event(Alarm init, char const* str);

  // Copy and move policy
  //
  ~Event();
  Event(const Event& src);
  Event&      operator=(const Event& rhs);
  friend void swap(Event& lhs, Event& rhs);

  Alarm       type() const;
  char const* as_string() const;
  char const* what() const;

private:
  Alarm event_type{ Alarm::unknown };
  char* description{};
};

#endif
