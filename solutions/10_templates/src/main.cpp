// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "Pipe.h"
#include "EventFilter.h"

int main()
{
  Generator generator{};
  Display   display{};
  EventFilter filter{ Alarm::advisory };

  Pipe pipe1{};
  Pipe pipe2{};

  connect(generator, pipe1);
  connect(filter, pipe1, pipe2);
  connect(display, pipe2);

  for (int i = 0; i < 10; ++i) {
    generator.execute();
    filter.execute();
    display.execute();
  }
}
