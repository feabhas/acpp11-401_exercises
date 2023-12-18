// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include <functional>

void Pipe::push(Pipe::element_type in_val)
{
  {
    std::unique_lock<std::mutex> lock{ mtx };
    while (elements.size() == capacity) {
      has_space.wait(lock);
    }
    elements.add(std::move(in_val));
  }
  has_data.notify_all();
}

std::optional<Pipe::element_type> Pipe::pull()
{
  std::optional<Pipe::element_type> opt;
  {
    std::unique_lock<std::mutex> lock{ mtx };
    while ((opt = elements.get()) == std::nullopt) {
      has_data.wait(lock);
    }
  }
  has_space.notify_all();
  return std::move(opt.value());
}
