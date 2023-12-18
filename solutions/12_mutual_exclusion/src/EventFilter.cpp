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

bool EventFilter::execute()
{
  if (auto opt = input->pull()) {
    auto events = std::move(opt.value());
    if (!events) {
      // pass on closedown action
      output->push(std::move(events));
      return false;
    }

    std::cout << "FILTER   : ------------------------" << '\n';

    auto initial_size = events->size();

    auto it = remove_if(
      std::begin(*events), end(*events), [this](const Event& event) {
        return event.type() == filter_value;
      });

    events->erase(it, std::end(*events));

    auto event_removed = initial_size - events->size();

    std::cout << "Removed " << event_removed << " event";
    std::cout << (event_removed == 1 ? "" : "s") << '\n';

    output->push(std::move(events));

    std::cout << '\n';
  }

  return true;
}
