// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  if (radius < 0.0) {
    throw std::invalid_argument("Radius must be non-negative");
  }

  radius_ = radius;
  ference_ = 2.0 * pi() * radius_;
  area_ = pi() * radius_ * radius_;
}

void Circle::setFerence(double ference) {
  if (ference < 0.0) {
    throw std::invalid_argument("Circumference must be non-negative");
  }

  ference_ = ference;
  radius_ = ference_ / (2.0 * pi());
  area_ = pi() * radius_ * radius_;
}

void Circle::setArea(double area) {
  if (area < 0.0) {
    throw std::invalid_argument("Area must be non-negative");
  }

  area_ = area;
  radius_ = std::sqrt(area_ / pi());
  ference_ = 2.0 * pi() * radius_;
}

double Circle::getRadius() const {
  return radius_;
}

double Circle::getFerence() const {
  return ference_;
}

double Circle::getArea() const {
  return area_;
}

double Circle::pi() {
  return std::acos(-1.0);
}
