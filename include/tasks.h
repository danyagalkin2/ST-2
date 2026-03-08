// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double EarthRopeGapMeters();
double PoolConcreteCostRubles(double pool_radius_m, double walkway_width_m,
                              double concrete_cost_per_m2);
double PoolFenceCostRubles(double pool_radius_m, double walkway_width_m,
                           double fence_cost_per_m);

#endif  // INCLUDE_TASKS_H_
