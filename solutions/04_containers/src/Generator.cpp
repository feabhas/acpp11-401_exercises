// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
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

  auto               num_events = rand() % 9 + 1;
  Pipe::element_type events{};

  std::cout << "Generating " << num_events << " event"
       << (num_events == 1 ? "" : "s") << '\n';

  for (int i{ 0 }; i < num_events; ++i) {
    events.emplace_back(random_alarm());
  }

  output->push(events);

  std::cout << '\n';
}
