// Copyright 2026 UNN-CS
#include "tasks.h"

#include "circle.h"

namespace {
constexpr double kPoolRadiusMeters = 3.0;
constexpr double kWalkwayWidthMeters = 1.0;
constexpr double kConcreteCostPerSquareMeter = 1000.0;
constexpr double kFenceCostPerMeter = 2000.0;
}  // namespace

double EarthRopeGapMeters() {
  constexpr double kEarthRadiusMeters = 6'378'100.0;
  Circle earth(kEarthRadiusMeters);
  earth.setFerence(earth.getFerence() + 1.0);
  return earth.getRadius() - kEarthRadiusMeters;
}

PoolCosts PoolCostsRubles() {
  Circle pool(kPoolRadiusMeters);
  Circle outer(kPoolRadiusMeters + kWalkwayWidthMeters);
  const double walkway_area = outer.getArea() - pool.getArea();

  PoolCosts costs{};
  costs.concrete_cost = walkway_area * kConcreteCostPerSquareMeter;
  costs.fence_cost = outer.getFerence() * kFenceCostPerMeter;
  return costs;
}
