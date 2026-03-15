// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

Circle::Circle(double radius_value) : radius(0.0), ference(0.0), area(0.0) {
  setRadius(radius_value);
}

void Circle::setRadius(double radius_value) {
  if (radius_value < 0.0) {
    throw std::invalid_argument("Radius must be non-negative");
  }

  radius = radius_value;
  ference = 2.0 * pi() * radius;
  area = pi() * radius * radius;
}

void Circle::setFerence(double ference_value) {
  if (ference_value < 0.0) {
    throw std::invalid_argument("Circumference must be non-negative");
  }

  ference = ference_value;
  radius = ference / (2.0 * pi());
  area = pi() * radius * radius;
}

void Circle::setArea(double area_value) {
  if (area_value < 0.0) {
    throw std::invalid_argument("Area must be non-negative");
  }

  area = area_value;
  radius = std::sqrt(area / pi());
  ference = 2.0 * pi() * radius;
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

double Circle::pi() {
  return std::acos(-1.0);
}
