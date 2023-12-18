// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Pipe.h"
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>


void connect(Generator& gen, Pipe& pipe)
{
  gen.output = &pipe;
}

namespace
{
  inline Alarm random_alarm() { return static_cast<Alarm>((rand() % 3) + 1); }
  inline Event random_event() {return Event {random_alarm()}; }

  char const* warning_text[]{
    "It's all gone wrong!",   "Panic!",      "Run away!",
    "Danger, Will Robinson!", "Aaaaaaargh!", "Oh no!"
  };

  inline char const* random_text() { return warning_text[rand() % 6]; }

} // namespace

void Generator::execute()
{
  std::cout << "GENERATOR: ------------------------" << '\n';

  auto               num_events = rand() % 9 + 1;
  Pipe::element_type events{};

  std::cout << "Generating " << num_events << " event"
       << (num_events == 1 ? "" : "s") << '\n';

  std::generate_n(std::back_inserter(events), num_events, []() {
    return Event{ random_alarm(), random_text() };
  });

  output->push(events);

  std::cout << '\n';
}
