// EventFilter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventFilter.h"
#include "Pipe.h"
#include <algorithm>
#include <iostream>


void connect(EventFilter& filter, Pipe& in, Pipe& out)
{
  filter.input  = &in;
  filter.output = &out;
}

void EventFilter::execute()
{
  std::cout << "FILTER   : ------------------------" << '\n';
  if (auto events = input->pull()) {
    auto initial_size = events->size();

    auto it = remove_if(
      std::begin(*events), end(*events), [this](const Event& event) {
        return event.type() == filter_value;
      });

    events->erase(it, std::end(*events));

    auto event_removed = initial_size - events->size();

    std::cout << "Removed " << event_removed << " event";
    std::cout << (event_removed == 1 ? "" : "s") << '\n';

    output->push(*events);

    std::cout << '\n';
  }
}
