// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include <functional>

void Pipe::push(Pipe::element_type in_val)
{
  element = std::move(in_val);
}

std::optional<Pipe::element_type> Pipe::pull()
{
  return std::move(element);
}
