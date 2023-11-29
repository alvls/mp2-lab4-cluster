#include "simulation.h"
#include <iostream>

Simulation::Simulation(int totalNodes, double _L, int _k)
   : cluster(totalNodes),
   randomDevice(),
   randomGenerator(randomDevice()),
   uniformDistribution(0.0, 1.0),
   k(_k),
   N(totalNodes),
   T(0),
   L(_L) {
}

void Simulation::generateRandomTasks() {
   for (int i = 0; i < k; ++i) {
      if (uniformDistribution(randomGenerator) < L) {
         uniform_int_distribution<int> timeDistribution(1, 10);
         uniform_int_distribution<int> nodeDistribution(2, N);
         int t = timeDistribution(randomGenerator);
         int p = nodeDistribution(randomGenerator);
         cluster.enqueueTask(Task(t, p));
      }
   }
}

void Simulation::processingTact() {
   generateRandomTasks();
   cluster.updateTaskStatus();
   showState();
   cluster.assignTasks();
   cluster.updateLoadPercent(cluster.calculateLoadPercentage());
   T++;
}

void Simulation::showFinalStatistics(int T) {
   cout << "\nСтатистика симуляции: " << endl;
   cout << "Общее количество тактов: " << T << endl;
   cout << "Средний процент загрузки кластера: " << cluster.getAverageLoadPercent(T) << "%" << endl;
   cout << "Выполненных задач: " << cluster.getCompletedTaskCount() << endl;
   cout << "Невыполненных задач: " << cluster.getUncompletedTaskCount() << endl;
   cout << "Всего задач: " << cluster.getTotalTaskCount() << endl;
}

void Simulation::showState() {
   cout << "Загрузка кластера: " << cluster.calculateLoadPercentage() << "%" << endl;
   cout << "Исполняемых задач: " << cluster.getCurrentTaskCount() << endl;
   cout << "Занятых узлов: " << cluster.calculateBusyNodeCount() << endl;
   cout << "Задач в очереди: " << cluster.TaskQueue.getSize() << endl << endl;
}
