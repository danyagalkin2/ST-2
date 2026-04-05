// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {
constexpr double kPi = 3.1415;
}

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  if (r < 0) {
    throw std::invalid_argument("Radius must be non-negative");
  }

  radius = r;
  ference = 2 * kPi * radius;
  area = kPi * radius * radius;
}

void Circle::setFerence(double f) {
  if (f < 0) {
    throw std::invalid_argument("Ference must be non-negative");
  }

  ference = f;
  radius = ference / (2 * kPi);
  area = kPi * radius * radius;
}

void Circle::setArea(double a) {
  if (a < 0) {
    throw std::invalid_argument("Area must be non-negative");
  }

  area = a;
  radius = std::sqrt(area / kPi);
  ference = 2 * kPi * radius;
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getFerence() const {
  return ference;
}

double Circle::getArea() const {
  return area;
}
