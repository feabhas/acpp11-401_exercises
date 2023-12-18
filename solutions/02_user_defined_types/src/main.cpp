// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Event.h"
#include <iostream>

int main()
{
  Event event1{};
  Event event2{ Alarm::warning };

  std::cout << event1.as_string() << '\n';
  std::cout << event2.as_string() << '\n';
}
