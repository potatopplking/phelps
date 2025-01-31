#pragma once
#include "vec.hpp"
#include "particles.hpp"
#include <vector>
#include <map>
#include <iostream>

class Grid { 
public:
  using ParticlesView = std::vector<unsigned int>;
public:
  Grid(Vec &boundSize, float &cellSize): 
    cellSize(cellSize),
    adjacentOffsets{
      Vec(-1, -1) * cellSize, Vec(0, -1) * cellSize, Vec(1, -1) * cellSize,
      Vec(-1, 0) * cellSize,  Vec(0, 0) * cellSize,  Vec(1, 0) * cellSize,
      Vec(-1, 1) * cellSize,  Vec(0, 1) * cellSize,  Vec(1, 1) * cellSize
      },
    nCells((boundSize.x / cellSize) * (boundSize.y / cellSize))
  {
  }
  const ParticlesView* viewCell(const Vec &) const;
  void gridify(Particles &);
  static const unsigned short ADJACENT_CELLS = 9;
  const float cellSize;
  const Vec adjacentOffsets[ADJACENT_CELLS];
  const int nCells;
  int hashCell(const Vec &) const;
private: 
  std::unordered_map<int, ParticlesView> cells;
};