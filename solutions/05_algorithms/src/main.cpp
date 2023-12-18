// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "Pipe.h"

int main()
{
  Generator generator{};
  Display   display{};
  Pipe      pipe{};

  connect(generator, pipe);
  connect(display, pipe);

  for (int i = 0; i < 10; ++i) {
    generator.execute();
    display.execute();
  }
}
