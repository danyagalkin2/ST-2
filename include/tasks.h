// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concrete_cost;
  double fence_cost;
};

double EarthRopeGapMeters();
PoolCosts PoolCostsRubles();

#endif  // INCLUDE_TASKS_H_
