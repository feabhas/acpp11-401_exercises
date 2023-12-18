// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Event.h"
#include "Pipe.h"
#include <iostream>


void connect(Display& disp, Pipe& pipe)
{
  disp.input = &pipe;
}

void Display::execute()
{
  std::cout << "DISPLAY  : ------------------------" << '\n';

  // Using the return value from pull to
  // initialise events => copy elision;
  // therefore no move required
  //
  auto events = input->pull();

  for (auto& event : *events) {
    std::cout << event.as_string() << " : " << event.what() << '\n';
  }

  std::cout << '\n';
}
