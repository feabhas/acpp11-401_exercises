// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include <iostream>
#include <vector>

static constexpr int run_count {4};

int main()
{
  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 };
  AlarmFilter filter{ Alarm::Type::advisory, pipe1, pipe2 };
  Display     display{ pipe2 };

  for (int i{0}; i < run_count; ++i) {
    generator.execute();
    filter.execute();
    display.execute();
  }

  std::cout << "\nCompleted OK\n";
}

