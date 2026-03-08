// Copyright 2026 UNN-CS
#include "tasks.h"

#include <stdexcept>

#include "circle.h"

double EarthRopeGapMeters() {
  constexpr double kEarthRadiusMeters = 6'378'100.0;
  Circle earth(kEarthRadiusMeters);
  earth.setFerence(earth.getFerence() + 1.0);
  return earth.getRadius() - kEarthRadiusMeters;
}

double PoolConcreteCostRubles(double pool_radius_m, double walkway_width_m,
                              double concrete_cost_per_m2) {
  if (pool_radius_m < 0.0 || walkway_width_m < 0.0 ||
      concrete_cost_per_m2 < 0.0) {
    throw std::invalid_argument("Input values must be non-negative");
  }

  Circle pool(pool_radius_m);
  Circle outer(pool_radius_m + walkway_width_m);
  const double walkway_area = outer.getArea() - pool.getArea();
  return walkway_area * concrete_cost_per_m2;
}

double PoolFenceCostRubles(double pool_radius_m, double walkway_width_m,
                           double fence_cost_per_m) {
  if (pool_radius_m < 0.0 || walkway_width_m < 0.0 || fence_cost_per_m < 0.0) {
    throw std::invalid_argument("Input values must be non-negative");
  }

  Circle outer(pool_radius_m + walkway_width_m);
  return outer.getFerence() * fence_cost_per_m;
}
