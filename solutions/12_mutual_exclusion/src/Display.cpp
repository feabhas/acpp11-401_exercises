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

bool Display::execute()
{
  if (auto opt = input->pull()) {
    auto events = std::move(opt.value());
    if (!events) {
      return false;
    }
    std::cout << "DISPLAY  : ------------------------" << '\n';

    for (auto& event : *events) {
      std::cout << event.as_string() << " : " << event.what() << '\n';
    }
    std::cout << '\n';
  }

  return true;
}
