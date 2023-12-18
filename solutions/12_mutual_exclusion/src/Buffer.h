// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <optional>

template<typename T, size_t sz>
class Buffer {
public:
  using value_type = T;

  bool             add(const T& in);
  bool             add(T&& in);
  std::optional<T> get();
  bool             is_empty() const;
  size_t           size() const;

private:
  using Container = std::array<T, sz>;
  using Iterator  = typename Container::iterator;

  Container buffer{};
  Iterator  write{ std::begin(buffer) };
  Iterator  read{ std::begin(buffer) };
  size_t    num_items{ 0 };
};

template<typename T, size_t sz>
bool Buffer<T, sz>::add(const T& in)
{
  if (num_items == sz) return false;

  *write = in;
  ++write;
  ++num_items;
  if (write == std::end(buffer)) write = std::begin(buffer);
  return true;
}

template<typename T, size_t sz>
bool Buffer<T, sz>::add(T&& in)
{
  if (num_items == sz) return false;

  *write = std::move(in);
  ++write;
  ++num_items;
  if (write == std::end(buffer)) write = std::begin(buffer);
  return true;
}

template<typename T, size_t sz>
std::optional<T> Buffer<T, sz>::get()
{
  if (num_items == 0) return std::nullopt;

  auto out = std::move(*read);
  ++read;
  --num_items;
  if (read == std::end(buffer)) read = std::begin(buffer);

  return out;
}

template<typename T, size_t sz>
bool Buffer<T, sz>::is_empty() const
{
  return (num_items == 0);
}

template<typename T, size_t sz>
size_t Buffer<T, sz>::size() const
{
  return num_items;
}

#endif
