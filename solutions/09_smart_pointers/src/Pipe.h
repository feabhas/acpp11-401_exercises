// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <optional>
#include <vector>
#include <memory>
#include "Event.h"

class Pipe {
public:
  using value_type    = std::vector<Event>;
  using element_type  = std::unique_ptr<value_type>;

  void                        push(element_type in_val);
  std::optional<element_type> pull();

private:
  element_type element{};
};

#endif
