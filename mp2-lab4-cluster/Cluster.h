#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "Task.h" // Подключение определения класса Task

// Определение класса Cluster
class Cluster {
  int totalNodes;     // Общее количество узлов в кластере
  int usedNodes = 0;  // Количество занятых узлов
  std::vector<Task> tasks; // Список задач в кластере

public:
  Cluster(int total); // Конструктор

  bool addTask(const Task& task); // Добавление задачи в кластер
  void tick(); // Обработка одного такта времени
  void printTasksInCluster() const; // Вывод информации о задачах в кластере

  int getUsedNodes() const; // Получение количества используемых узлов
  int getTotalNodes() const; // Получение общего количества узлов
  int getUnfinishedTasksCount() const; // Получение количества незавершенных задач
  double getCurrentLoadPercentage() const; // Получение текущего процента загрузки
};

#endif // CLUSTER_H
