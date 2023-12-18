// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Event.h"
#include "Pipe.h"
#include <cstdlib>
#include <iostream>


void connect(Generator& gen, Pipe& pipe)
{
  gen.output = &pipe;
}

namespace
{
  inline Alarm random_alarm() { return static_cast<Alarm>((rand() % 3) + 1); }
} // namespace

void Generator::execute()
{
  std::cout << "GENERATOR: ------------------------" << '\n';

  if (output) {
    Event event{ random_alarm() };
    output->push(event);
    std::cout << "Pushed event: " << event.as_string() << '\n';
    std::cout << '\n';
  }
  else {
    std::cerr << "GENERATOR  : No output pipe connected" << '\n';
  }
}
