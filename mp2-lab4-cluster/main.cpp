#include <iostream>
#include <clocale>
#include "Simulation.h"

int main() 
{
  int N, totalTicks, k;
  double L;

  setlocale(LC_ALL, "Russian");

  std::cout << "Введите количество узлов в кластере (от 16 до 64): ";
  std::cin >> N;

  std::cout << "Введите общее количество тактов для выполнения программы: ";
  std::cin >> totalTicks;

  std::cout << "Введите вероятность появления задачи на каждом такте (0 < L < 1): ";
  std::cin >> L;

  std::cout << "Введите максимальное количество задач на каждом такте (k >= 1): ";
  std::cin >> k;

  Simulation simulation(N, totalTicks, L, k);
  simulation.run();

  return 0;
}
