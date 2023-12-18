// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "EventFilter.h"
#include "Pipe.h"
#include "Filter.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono_literals;

int main()
{
  Pipe pipe1{};
  Pipe pipe2{};

  Generator   generator{};
  Display     display{};
  EventFilter filter{ Alarm::advisory };

  connect(generator, pipe1);
  connect(filter, pipe1, pipe2);
  connect(display, pipe2);

  auto run_n_times = [](int num_times, Filter& filter) {
    for (int i{ 0 }; i < num_times; ++i) {
      filter.execute();
      // std::this_thread::sleep_for(1000ms);
    }
  };

  auto run_forever = [](Filter& filter) {
    while (filter.execute()) {
      std::this_thread::yield();
    }
  };

  std::thread gen_thread{ run_n_times, 5, std::ref(generator) };
  std::thread filter_thread{ run_forever, std::ref(filter) };
  std::thread display_thread{ run_forever, std::ref(display) };

  // Wait for the generator to finish
  //
  gen_thread.join();

  // close down the pipeline
  pipe1.push(nullptr);

  filter_thread.join();
  display_thread.join();
}
