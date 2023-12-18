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

  if (input) {
    if (auto event = input->pull()) {
      std::cout << "Received event: " << event->as_string() << '\n';
      std::cout << '\n';
    }
  }
  else {
    std::cerr << "DISPLAY  : No input pipe connected" << '\n';
  }
}
