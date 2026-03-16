// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"

const double PI = 3.1415;

double ropeGap(double earth_radius_km) {
  double earth_radius_m = earth_radius_km * 1000.0;
  Circle earth(earth_radius_m);
  double new_ference = earth.getFerence() + 1.0;
  Circle new_circle(0);
  new_circle.setFerence(new_ference);
  return new_circle.getRadius() - earth.getRadius();
}

double poolConcreteCost(double pool_radius_m, double walkway_width_m,
                        double concrete_price_per_m2) {
  Circle pool(pool_radius_m);
  Circle outer(pool_radius_m + walkway_width_m);
  double walkway_area = outer.getArea() - pool.getArea();
  return walkway_area * concrete_price_per_m2;
}

double poolFenceCost(double pool_radius_m, double walkway_width_m,
                     double fence_price_per_m) {
  Circle outer(pool_radius_m + walkway_width_m);
  double fence_length = outer.getFerence();
  return fence_length * fence_price_per_m;
}

double poolTotalCost(double pool_radius_m, double walkway_width_m,
                     double concrete_price_per_m2, double fence_price_per_m) {
  return poolConcreteCost(pool_radius_m, walkway_width_m, concrete_price_per_m2)
         + poolFenceCost(pool_radius_m, walkway_width_m, fence_price_per_m);
}
