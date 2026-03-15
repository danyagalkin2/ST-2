// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kEps = 1e-9;
}

TEST(Circle, ConstructorWithZeroRadius) {
  Circle circle(0.0);
  EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
  EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(Circle, ConstructorSetsValuesForPositiveRadius) {
  const double r = 2.5;
  Circle circle(r);
  EXPECT_NEAR(circle.getRadius(), r, kEps);
  EXPECT_NEAR(circle.getFerence(), 2.0 * std::acos(-1.0) * r, kEps);
  EXPECT_NEAR(circle.getArea(), std::acos(-1.0) * r * r, kEps);
}

TEST(Circle, ConstructorThrowsForNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(Circle, SetRadiusRecalculatesAreaAndFerence) {
  Circle circle(1.0);
  circle.setRadius(10.0);
  EXPECT_NEAR(circle.getRadius(), 10.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 20.0 * std::acos(-1.0), kEps);
  EXPECT_NEAR(circle.getArea(), 100.0 * std::acos(-1.0), kEps);
}

TEST(Circle, SetRadiusToZeroClearsDerivedValues) {
  Circle circle(8.0);
  circle.setRadius(0.0);
  EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
  EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(Circle, SetRadiusThrowsForNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setRadius(-0.1), std::invalid_argument);
}

TEST(Circle, SetFerenceRecalculatesRadiusAndArea) {
  Circle circle(2.0);
  const double c = 2.0 * std::acos(-1.0) * 3.0;
  circle.setFerence(c);
  EXPECT_NEAR(circle.getRadius(), 3.0, kEps);
  EXPECT_NEAR(circle.getFerence(), c, kEps);
  EXPECT_NEAR(circle.getArea(), std::acos(-1.0) * 9.0, kEps);
}

TEST(Circle, SetFerenceToZeroSetsRadiusAndAreaToZero) {
  Circle circle(5.0);
  circle.setFerence(0.0);
  EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
  EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(Circle, SetFerenceThrowsForNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setFerence(-1.0), std::invalid_argument);
}

TEST(Circle, SetAreaRecalculatesRadiusAndFerence) {
  Circle circle(1.0);
  circle.setArea(16.0 * std::acos(-1.0));
  EXPECT_NEAR(circle.getRadius(), 4.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 8.0 * std::acos(-1.0), kEps);
}

TEST(Circle, SetAreaToZeroSetsRadiusAndFerenceToZero) {
  Circle circle(2.0);
  circle.setArea(0.0);
  EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
}

TEST(Circle, SetAreaThrowsForNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setArea(-0.001), std::invalid_argument);
}

TEST(Circle, ConsecutiveUpdatesKeepCircleConsistent) {
  Circle circle(1.0);
  circle.setRadius(2.0);
  circle.setFerence(2.0 * std::acos(-1.0) * 5.0);
  circle.setArea(std::acos(-1.0) * 36.0);

  EXPECT_NEAR(circle.getRadius(), 6.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 12.0 * std::acos(-1.0), kEps);
  EXPECT_NEAR(circle.getArea(), 36.0 * std::acos(-1.0), kEps);
}

TEST(Circle, RadiusFromAreaRoundTrip) {
  Circle circle(7.5);
  const double original_radius = circle.getRadius();
  const double area = circle.getArea();
  circle.setArea(area);
  EXPECT_NEAR(circle.getRadius(), original_radius, kEps);
}

TEST(Circle, RadiusFromFerenceRoundTrip) {
  Circle circle(12.0);
  const double original_radius = circle.getRadius();
  const double c = circle.getFerence();
  circle.setFerence(c);
  EXPECT_NEAR(circle.getRadius(), original_radius, kEps);
}

TEST(Circle, GetterValuesStayNonNegative) {
  Circle circle(3.0);
  EXPECT_GE(circle.getRadius(), 0.0);
  EXPECT_GE(circle.getFerence(), 0.0);
  EXPECT_GE(circle.getArea(), 0.0);
}

TEST(Circle, LargeRadiusProducesExpectedValues) {
  const double radius = 1000.0;
  Circle circle(radius);
  EXPECT_NEAR(circle.getFerence(), 2.0 * std::acos(-1.0) * radius, kEps);
  EXPECT_NEAR(circle.getArea(), std::acos(-1.0) * radius * radius, kEps);
}

TEST(Circle, SetAreaAndSetFerenceLeadToSameRadius) {
  Circle from_area(1.0);
  Circle from_ference(1.0);

  from_area.setArea(25.0 * std::acos(-1.0));
  from_ference.setFerence(10.0 * std::acos(-1.0));

  EXPECT_NEAR(from_area.getRadius(), 5.0, kEps);
  EXPECT_NEAR(from_ference.getRadius(), 5.0, kEps);
}

TEST(Circle, RadiusToFerenceToRadiusKeepsValue) {
  Circle circle(9.25);
  const double initial_radius = circle.getRadius();

  circle.setFerence(circle.getFerence());

  EXPECT_NEAR(circle.getRadius(), initial_radius, kEps);
}

TEST(Circle, RadiusToAreaToRadiusKeepsValue) {
  Circle circle(4.75);
  const double initial_radius = circle.getRadius();

  circle.setArea(circle.getArea());

  EXPECT_NEAR(circle.getRadius(), initial_radius, kEps);
}

TEST(Circle, FerenceAndAreaMatchSameRadius) {
  Circle circle(11.0);
  const double expected_ference = 22.0 * std::acos(-1.0);
  const double expected_area = 121.0 * std::acos(-1.0);

  EXPECT_NEAR(circle.getFerence(), expected_ference, kEps);
  EXPECT_NEAR(circle.getArea(), expected_area, kEps);
}

TEST(Circle, RepeatedZeroAssignmentsStayStable) {
  Circle circle(3.0);

  circle.setRadius(0.0);
  circle.setFerence(0.0);
  circle.setArea(0.0);

  EXPECT_NEAR(circle.getRadius(), 0.0, kEps);
  EXPECT_NEAR(circle.getFerence(), 0.0, kEps);
  EXPECT_NEAR(circle.getArea(), 0.0, kEps);
}

TEST(Tasks, EarthRopeGapFormula) {
  const double expected = 1.0 / (2.0 * std::acos(-1.0));
  EXPECT_NEAR(EarthRopeGapMeters(), expected, 1e-9);
}

TEST(Tasks, PoolConcreteCostMatchesManualCalculation) {
  const PoolCosts costs = PoolCostsRubles();
  const double expected_area = std::acos(-1.0) * (4.0 * 4.0 - 3.0 * 3.0);
  const double expected_cost = expected_area * 1000.0;
  EXPECT_NEAR(costs.concrete_cost, expected_cost, kEps);
}

TEST(Tasks, PoolFenceCostMatchesManualCalculation) {
  const PoolCosts costs = PoolCostsRubles();
  const double expected = 2.0 * std::acos(-1.0) * 4.0 * 2000.0;
  EXPECT_NEAR(costs.fence_cost, expected, kEps);
}

TEST(Tasks, PoolConcreteCostIsPositive) {
  const PoolCosts costs = PoolCostsRubles();
  EXPECT_GT(costs.concrete_cost, 0.0);
}

TEST(Tasks, PoolFenceCostIsPositive) {
  const PoolCosts costs = PoolCostsRubles();
  EXPECT_GT(costs.fence_cost, 0.0);
}

TEST(Tasks, PoolFenceCostIsGreaterThanConcreteCost) {
  const PoolCosts costs = PoolCostsRubles();
  EXPECT_GT(costs.fence_cost, costs.concrete_cost);
}

TEST(Tasks, PoolTotalCostMatchesSumOfComponents) {
  const PoolCosts costs = PoolCostsRubles();
  const double expected_area = std::acos(-1.0) * (16.0 - 9.0);
  const double expected_concrete = expected_area * 1000.0;
  const double expected_fence = 2.0 * std::acos(-1.0) * 4.0 * 2000.0;

  EXPECT_NEAR(costs.concrete_cost + costs.fence_cost,
              expected_concrete + expected_fence, kEps);
}

TEST(Tasks, PoolCostsFunctionReturnsStableValues) {
  const PoolCosts first = PoolCostsRubles();
  const PoolCosts second = PoolCostsRubles();

  EXPECT_NEAR(first.concrete_cost, second.concrete_cost, kEps);
  EXPECT_NEAR(first.fence_cost, second.fence_cost, kEps);
}

TEST(Tasks, PoolConcretePartMatchesDifferenceOfCircleAreas) {
  const PoolCosts costs = PoolCostsRubles();
  Circle pool(3.0);
  Circle outer(4.0);

  EXPECT_NEAR(costs.concrete_cost,
              (outer.getArea() - pool.getArea()) * 1000.0, kEps);
}

TEST(Tasks, PoolFencePartMatchesOuterCircleFerence) {
  const PoolCosts costs = PoolCostsRubles();
  Circle outer(4.0);

  EXPECT_NEAR(costs.fence_cost, outer.getFerence() * 2000.0, kEps);
}
