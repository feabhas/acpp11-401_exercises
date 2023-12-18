// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <vector>
#include <optional>
#include "Event.h"

class Pipe {
public:
  using element_type = std::vector<Event>;

  void                        push(const element_type& in_val);
  std::optional<element_type> pull();

private:
  element_type element{};
};

#endif
