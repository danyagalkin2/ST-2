// Copyright 2022 UNN-CS
#include "tasks.h"

#include "circle.h"

namespace {
constexpr double kEarthRadiusKm = 6378.1;
constexpr double kRopeExtensionM = 1.0;
constexpr double kPoolRadiusM = 3.0;
constexpr double kWalkwayWidthM = 1.0;
constexpr double kConcretePricePerM2 = 1000.0;
constexpr double kFencePricePerM = 2000.0;
}

double ropeGap() {
  Circle earth(kEarthRadiusKm * 1000.0);
  Circle rope(0.0);

  rope.setFerence(earth.getFerence() + kRopeExtensionM);
  return rope.getRadius() - earth.getRadius();
}

PoolCosts poolCosts() {
  Circle pool(kPoolRadiusM);
  Circle outer(pool.getRadius() + kWalkwayWidthM);

  const double walkwayArea = outer.getArea() - pool.getArea();
  const double fenceLength = outer.getFerence();

  return {walkwayArea * kConcretePricePerM2, fenceLength * kFencePricePerM};
}
