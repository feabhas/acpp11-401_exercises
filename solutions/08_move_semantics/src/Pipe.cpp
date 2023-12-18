// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include <functional>


// void Pipe::push(const Pipe::element_type& in_val)
// {
//   element = in_val;
// }

void Pipe::push(Pipe::element_type&& in_val)
{
  // in_val is an Lvalue expression
  // here, so must be moved again
  //
  element = std::move(in_val);
}

std::optional<Pipe::element_type> Pipe::pull()
{
  // element is an Lvalue (it
  // will exist after pull ends)
  // so we must turn it into an
  // Xvalue so as to move from it
  //
  return std::move(element);
}
