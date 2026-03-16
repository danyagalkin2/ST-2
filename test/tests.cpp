// Copyright 2022 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.1415;
const double EPS = 1e-6;

// Тесты для класса Circle
TEST(CircleTest, ConstructorPositiveRadius) {
  Circle c(10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 10.0, EPS);
  EXPECT_NEAR(c.getArea(), PI * 100.0, EPS);
}

TEST(CircleTest, ConstructorZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeRadius) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
  EXPECT_NEAR(c.getFerence(), 2 * PI * (-5.0), EPS);
  EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, SetRadiusPositive) {
  Circle c(1.0);
  c.setRadius(7.5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 7.5);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 7.5, EPS);
  EXPECT_NEAR(c.getArea(), PI * 7.5 * 7.5, EPS);
}

TEST(CircleTest, SetRadiusZero) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusNegative) {
  Circle c(3.0);
  c.setRadius(-2.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), -2.0);
  EXPECT_NEAR(c.getFerence(), 2 * PI * (-2.0), EPS);
  EXPECT_NEAR(c.getArea(), PI * 4.0, EPS);
}

TEST(CircleTest, SetFerencePositive) {
  Circle c(1.0);
  double f = 10.0;
  c.setFerence(f);
  double expected_r = f / (2 * PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
  EXPECT_NEAR(c.getFerence(), f, EPS);
  EXPECT_NEAR(c.getArea(), PI * expected_r * expected_r, EPS);
}

TEST(CircleTest, SetFerenceZero) {
  Circle c(5.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceNegative) {
  Circle c(2.0);
  double f = -10.0;
  c.setFerence(f);
  double expected_r = f / (2 * PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
  EXPECT_NEAR(c.getFerence(), f, EPS);
  EXPECT_NEAR(c.getArea(), PI * expected_r * expected_r, EPS);
}

TEST(CircleTest, SetAreaPositive) {
  Circle c(1.0);
  double a = 50.0;
  c.setArea(a);
  double expected_r = std::sqrt(a / PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
  EXPECT_NEAR(c.getArea(), a, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI * expected_r, EPS);
}

TEST(CircleTest, SetAreaZero) {
  Circle c(3.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaNegative) {
  Circle c(2.0);
  double a = -20.0;
  c.setArea(a);
  // При отрицательной площади радиус становится NaN
  EXPECT_TRUE(std::isnan(c.getRadius()));
  EXPECT_TRUE(std::isnan(c.getFerence()));
  EXPECT_DOUBLE_EQ(c.getArea(), a);
}

TEST(CircleTest, GetRadiusAfterSetFerence) {
  Circle c(5.0);
  c.setFerence(20.0);
  double expected_r = 20.0 / (2 * PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
}

TEST(CircleTest, GetAreaAfterSetFerence) {
  Circle c(5.0);
  c.setFerence(20.0);
  double r = 20.0 / (2 * PI);
  double expected_a = PI * r * r;
  EXPECT_NEAR(c.getArea(), expected_a, EPS);
}

TEST(CircleTest, GetFerenceAfterSetArea) {
  Circle c(5.0);
  c.setArea(30.0);
  double r = std::sqrt(30.0 / PI);
  double expected_f = 2 * PI * r;
  EXPECT_NEAR(c.getFerence(), expected_f, EPS);
}

TEST(CircleTest, GetRadiusAfterSetArea) {
  Circle c(5.0);
  c.setArea(30.0);
  double expected_r = std::sqrt(30.0 / PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
}

TEST(CircleTest, ConsistencyAfterMultipleSets) {
  Circle c(2.0);
  c.setRadius(3.0);
  c.setFerence(15.0);
  double expected_r = 15.0 / (2 * PI);
  EXPECT_NEAR(c.getRadius(), expected_r, EPS);
  c.setArea(10.0);
  double expected_r2 = std::sqrt(10.0 / PI);
  EXPECT_NEAR(c.getRadius(), expected_r2, EPS);
}

TEST(CircleTest, LargeRadius) {
  double r = 1e9;
  Circle c(r);
  EXPECT_DOUBLE_EQ(c.getRadius(), r);
  EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
  EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

TEST(CircleTest, SmallRadius) {
  double r = 1e-9;
  Circle c(r);
  EXPECT_DOUBLE_EQ(c.getRadius(), r);
  EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
  EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

TEST(CircleTest, PrecisionTest) {
  double r = 7.123456;
  Circle c(r);
  EXPECT_NEAR(c.getFerence(), 2 * PI * r, EPS);
  EXPECT_NEAR(c.getArea(), PI * r * r, EPS);
}

// Тесты для ropeGap
TEST(RopeGapTest, EarthRadius) {
  double earth_radius_km = 6371.0;
  double gap = ropeGap(earth_radius_km);
  double expected_gap = 1.0 / (2 * PI);
  EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(RopeGapTest, ZeroRadius) {
  double gap = ropeGap(0.0);
  double expected_gap = 1.0 / (2 * PI);
  EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(RopeGapTest, NegativeRadius) {
  double gap = ropeGap(-10.0);
  double expected_gap = 1.0 / (2 * PI);
  EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(RopeGapTest, VerySmallRadius) {
  double gap = ropeGap(1e-9);
  double expected_gap = 1.0 / (2 * PI);
  EXPECT_NEAR(gap, expected_gap, EPS);
}

TEST(RopeGapTest, Consistency) {
  double gap1 = ropeGap(1000.0);
  double gap2 = ropeGap(5000.0);
  EXPECT_NEAR(gap1, gap2, EPS);
}

// Тесты для функций бассейна
TEST(PoolCostTest, ConcreteCostBasic) {
  double r = 5.0, w = 1.0, price = 10.0;
  double cost = poolConcreteCost(r, w, price);
  double expected_area = PI * ((r + w) * (r + w) - r * r);
  double expected_cost = expected_area * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, ConcreteCostZeroWalkway) {
  double r = 5.0, w = 0.0, price = 10.0;
  double cost = poolConcreteCost(r, w, price);
  EXPECT_NEAR(cost, 0.0, EPS);
}

TEST(PoolCostTest, ConcreteCostZeroPoolRadius) {
  double r = 0.0, w = 2.0, price = 10.0;
  double cost = poolConcreteCost(r, w, price);
  double expected_area = PI * w * w;
  double expected_cost = expected_area * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, ConcreteCostNegativeRadius) {
  double r = -5.0, w = 2.0, price = 10.0;
  double cost = poolConcreteCost(r, w, price);
  double expected_area = PI * ((r + w) * (r + w) - r * r);
  double expected_cost = expected_area * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, ConcreteCostNegativeWalkway) {
  double r = 5.0, w = -1.0, price = 10.0;
  double cost = poolConcreteCost(r, w, price);
  double expected_area = PI * ((r + w) * (r + w) - r * r);
  double expected_cost = expected_area * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, FenceCostBasic) {
  double r = 5.0, w = 1.0, price = 20.0;
  double cost = poolFenceCost(r, w, price);
  double expected_length = 2 * PI * (r + w);
  double expected_cost = expected_length * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, FenceCostZeroWalkway) {
  double r = 5.0, w = 0.0, price = 20.0;
  double cost = poolFenceCost(r, w, price);
  double expected_length = 2 * PI * r;
  double expected_cost = expected_length * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, FenceCostZeroPoolRadius) {
  double r = 0.0, w = 2.0, price = 20.0;
  double cost = poolFenceCost(r, w, price);
  double expected_length = 2 * PI * w;
  double expected_cost = expected_length * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, FenceCostNegativeRadius) {
  double r = -5.0, w = 2.0, price = 20.0;
  double cost = poolFenceCost(r, w, price);
  double expected_length = 2 * PI * (r + w);
  double expected_cost = expected_length * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, FenceCostNegativeWalkway) {
  double r = 5.0, w = -1.0, price = 20.0;
  double cost = poolFenceCost(r, w, price);
  double expected_length = 2 * PI * (r + w);
  double expected_cost = expected_length * price;
  EXPECT_NEAR(cost, expected_cost, EPS);
}

TEST(PoolCostTest, TotalCostBasic) {
  double r = 5.0, w = 1.0, concrete_price = 10.0, fence_price = 20.0;
  double total = poolTotalCost(r, w, concrete_price, fence_price);
  double expected_concrete = poolConcreteCost(r, w, concrete_price);
  double expected_fence = poolFenceCost(r, w, fence_price);
  double expected_total = expected_concrete + expected_fence;
  EXPECT_NEAR(total, expected_total, EPS);
}

TEST(PoolCostTest, TotalCostZeroWalkway) {
  double r = 5.0, w = 0.0, concrete_price = 10.0, fence_price = 20.0;
  double total = poolTotalCost(r, w, concrete_price, fence_price);
  double expected_concrete = poolConcreteCost(r, w, concrete_price);
  double expected_fence = poolFenceCost(r, w, fence_price);
  double expected_total = expected_concrete + expected_fence;
  EXPECT_NEAR(total, expected_total, EPS);
}

TEST(PoolCostTest, TotalCostZeroPoolRadius) {
  double r = 0.0, w = 2.0, concrete_price = 10.0, fence_price = 20.0;
  double total = poolTotalCost(r, w, concrete_price, fence_price);
  double expected_concrete = poolConcreteCost(r, w, concrete_price);
  double expected_fence = poolFenceCost(r, w, fence_price);
  double expected_total = expected_concrete + expected_fence;
  EXPECT_NEAR(total, expected_total, EPS);
}

TEST(PoolCostTest, TotalCostNegativeRadius) {
  double r = -5.0, w = 2.0, concrete_price = 10.0, fence_price = 20.0;
  double total = poolTotalCost(r, w, concrete_price, fence_price);
  double expected_concrete = poolConcreteCost(r, w, concrete_price);
  double expected_fence = poolFenceCost(r, w, fence_price);
  double expected_total = expected_concrete + expected_fence;
  EXPECT_NEAR(total, expected_total, EPS);
}

TEST(PoolCostTest, TotalCostLargeValues) {
  double r = 1e6, w = 1e5, concrete_price = 1e3, fence_price = 2e3;
  double total = poolTotalCost(r, w, concrete_price, fence_price);
  double expected_concrete = poolConcreteCost(r, w, concrete_price);
  double expected_fence = poolFenceCost(r, w, fence_price);
  double expected_total = expected_concrete + expected_fence;
  EXPECT_NEAR(total, expected_total, EPS);
}
