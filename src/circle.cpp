// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double PI = 3.1415;

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  radius = r;
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

void Circle::setFerence(double f) {
  ference = f;
  radius = ference / (2 * PI);
  area = PI * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  radius = std::sqrt(area / PI);
  ference = 2 * PI * radius;
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
