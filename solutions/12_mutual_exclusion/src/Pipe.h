// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <optional>
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "Event.h"
#include "Buffer.h"

class Pipe {
public:
  using value_type    = std::vector<Event>;
  using element_type  = std::unique_ptr<value_type>;

  void                        push(element_type in_val);
  std::optional<element_type> pull();

private:
  static constexpr int capacity {8};
  Buffer<element_type, capacity> elements{};
  mutable std::mutex      mtx{};
  std::condition_variable has_data{};
  std::condition_variable has_space{};
};

#endif
