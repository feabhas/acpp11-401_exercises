// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "Pipe.h"

int main()
{
  Pipe      pipe{};
  Generator generator{ pipe };
  Display   display{ pipe };

  //   Generator generator{};
  //   Display   display{};
  //   connect(generator, pipe);
  //   connect(display, pipe);

  for (int i = 0; i < 10; ++i) {
    generator.execute();
    display.execute();
  }
}
