#ifndef SIMULATION_H
#define SIMULATION_H

#include "Cluster.h"
#include <queue>

// Определение класса Simulation
class Simulation {
  int totalTicks; // Общее количество тактов
  double taskProbability; // Вероятность появления задачи на каждом такте
  int maxTasksPerTick; // Максимальное количество задач на такт
  Cluster cluster; // Объект кластера
  std::queue<Task> taskQueue; // Очередь задач
  int totalGeneratedTasks = 0; // Общее количество сгенерированных задач
  int completedTasks = 0; // Количество выполненных задач
  int failedTasks = 0; // Количество проваленных задач
  double totalLoadPercentage = 0.0; // Общий процент загрузки

public:
  Simulation(int nodes, int ticks, double probability, int maxTasks); // Конструктор

  void run(); // Метод для запуска симуляции

private:
  void generateTasks(); // Генерация задач
  void processTasks(); // Обработка задач
  void printStatus() const; // Вывод текущего статуса
  void printFinalStatistics(double averageLoad) const; // Вывод итоговой статистики

  static int randomInt(int min, int max); // Генерация случайного целого числа
  static double randomDouble(); // Генерация случайного дробного числа
  void printTasksInQueue() const; // Вывод задач в очереди
};

#endif // SIMULATION_H
