// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

class Pipe;

class Generator {
public:
  void execute();

private:
  Pipe*       output{};
  friend void connect(Generator& gen, Pipe& pipe);
};

#endif
