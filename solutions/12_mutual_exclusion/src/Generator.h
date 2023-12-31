// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include "Filter.h"

class Pipe;

class Generator : public Filter {
public:
  bool execute();

private:
  Pipe*       output{};
  friend void connect(Generator& gen, Pipe& pipe);
};

#endif

