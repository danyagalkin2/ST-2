// Copyright 2022 UNN-CS
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.1415;
constexpr double kEps = 1e-6;
}

TEST(CircleTest, ConstructorStoresPositiveRadius) {
  Circle circle(10.0);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 10.0);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * 10.0, kEps);
  EXPECT_NEAR(circle.getArea(), kPi * 100.0, kEps);
}

TEST(CircleTest, ConstructorAllowsZeroRadius) {
  Circle circle(0.0);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleTest, ConstructorThrowsOnNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusRecalculatesFerenceAndArea) {
  Circle circle(1.0);

  circle.setRadius(7.5);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 7.5);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * 7.5, kEps);
  EXPECT_NEAR(circle.getArea(), kPi * 7.5 * 7.5, kEps);
}

TEST(CircleTest, SetRadiusAllowsZeroValue) {
  Circle circle(5.0);

  circle.setRadius(0.0);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusThrowsOnNegativeValue) {
  Circle circle(3.0);

  EXPECT_THROW(circle.setRadius(-2.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceRecalculatesRadiusAndArea) {
  Circle circle(1.0);
  const double ference = 10.0;
  const double expectedRadius = ference / (2 * kPi);

  circle.setFerence(ference);

  EXPECT_NEAR(circle.getRadius(), expectedRadius, kEps);
  EXPECT_NEAR(circle.getFerence(), ference, kEps);
  EXPECT_NEAR(circle.getArea(), kPi * expectedRadius * expectedRadius, kEps);
}

TEST(CircleTest, SetFerenceAllowsZeroValue) {
  Circle circle(5.0);

  circle.setFerence(0.0);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceThrowsOnNegativeValue) {
  Circle circle(2.0);

  EXPECT_THROW(circle.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaRecalculatesRadiusAndFerence) {
  Circle circle(1.0);
  const double area = 50.0;
  const double expectedRadius = std::sqrt(area / kPi);

  circle.setArea(area);

  EXPECT_NEAR(circle.getRadius(), expectedRadius, kEps);
  EXPECT_NEAR(circle.getArea(), area, kEps);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * expectedRadius, kEps);
}

TEST(CircleTest, SetAreaAllowsZeroValue) {
  Circle circle(3.0);

  circle.setArea(0.0);

  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
}

TEST(CircleTest, SetAreaThrowsOnNegativeValue) {
  Circle circle(2.0);

  EXPECT_THROW(circle.setArea(-20.0), std::invalid_argument);
}

TEST(CircleTest, MultipleSettersKeepObjectConsistent) {
  Circle circle(2.0);

  circle.setRadius(3.0);
  circle.setFerence(15.0);
  circle.setArea(10.0);

  const double expectedRadius = std::sqrt(10.0 / kPi);
  EXPECT_NEAR(circle.getRadius(), expectedRadius, kEps);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * expectedRadius, kEps);
  EXPECT_NEAR(circle.getArea(), 10.0, kEps);
}

TEST(CircleTest, LargeRadiusIsHandledCorrectly) {
  const double radius = 1e9;
  Circle circle(radius);

  EXPECT_DOUBLE_EQ(circle.getRadius(), radius);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * radius, kEps);
  EXPECT_NEAR(circle.getArea(), kPi * radius * radius, kEps);
}

TEST(CircleTest, SmallRadiusIsHandledCorrectly) {
  const double radius = 1e-9;
  Circle circle(radius);

  EXPECT_DOUBLE_EQ(circle.getRadius(), radius);
  EXPECT_NEAR(circle.getFerence(), 2 * kPi * radius, kEps);
  EXPECT_NEAR(circle.getArea(), kPi * radius * radius, kEps);
}

TEST(CircleTest, AreaAndFerenceMatchForRadiusThree) {
  Circle circle(3.0);

  EXPECT_NEAR(circle.getFerence(), 18.849, kEps);
  EXPECT_NEAR(circle.getArea(), 28.2735, kEps);
}

TEST(RopeGapTest, ReturnsExpectedGapFromReadmeTask) {
  const double expectedGap = 1.0 / (2 * kPi);

  EXPECT_NEAR(ropeGap(), expectedGap, kEps);
}

TEST(RopeGapTest, GapIsPositive) {
  EXPECT_GT(ropeGap(), 0.0);
}

TEST(RopeGapTest, GapDoesNotDependOnEarthRadiusValueInFormula) {
  const double expectedGap = 1.0 / (2 * kPi);

  EXPECT_NEAR(ropeGap(), expectedGap, kEps);
}

TEST(PoolCostsTest, ReturnsConcreteCostFromReadmeTask) {
  const PoolCosts costs = poolCosts();

  EXPECT_NEAR(costs.concrete, 21990.5, kEps);
}

TEST(PoolCostsTest, ReturnsFenceCostFromReadmeTask) {
  const PoolCosts costs = poolCosts();

  EXPECT_NEAR(costs.fence, 50264.0, kEps);
}

TEST(PoolCostsTest, ConcreteCostMatchesManualFormula) {
  const PoolCosts costs = poolCosts();
  const double expectedConcrete = kPi * (16.0 - 9.0) * 1000.0;

  EXPECT_NEAR(costs.concrete, expectedConcrete, kEps);
}

TEST(PoolCostsTest, FenceCostMatchesManualFormula) {
  const PoolCosts costs = poolCosts();
  const double expectedFence = 2 * kPi * 4.0 * 2000.0;

  EXPECT_NEAR(costs.fence, expectedFence, kEps);
}

TEST(PoolCostsTest, BothReturnedCostsArePositive) {
  const PoolCosts costs = poolCosts();

  EXPECT_GT(costs.concrete, 0.0);
  EXPECT_GT(costs.fence, 0.0);
}
