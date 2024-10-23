// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

Display::Display(Pipe& ip) : input{&ip} {}

bool Display::execute() {
  assert(input);

  if (auto alarm = input->pull()) {
      if (alarm->type() == Alarm::Type::invalid) {
        return false;
      }
      std::cout << "Display:  " << *alarm << '\n';
  }
  return true;
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
