// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

void Pipe::push(const Pipe::element_type& in_val)
{
  element = in_val;
}

std::optional<Pipe::element_type> Pipe::pull()
{
  if (element.type() != Alarm::unknown)
    return element;
  else {
    return std::nullopt;
  }
}
