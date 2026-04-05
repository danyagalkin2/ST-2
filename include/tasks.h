// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concrete;
  double fence;
};

// Задача "Земля и верёвка" из README.
// Возвращает величину зазора в метрах для радиуса Земли 6378.1 км
// и увеличения длины верёвки на 1 метр.
double ropeGap();

// Задача "Бассейн" из README.
// Возвращает стоимости материалов для бетонной дорожки и ограды
// для радиуса бассейна 3 м и ширины дорожки 1 м.
PoolCosts poolCosts();

#endif  // INCLUDE_TASKS_H_
