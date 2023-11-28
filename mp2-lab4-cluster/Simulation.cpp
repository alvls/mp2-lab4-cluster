#include "Simulation.h"
#include <iostream>
#include <random>

Simulation::Simulation(int nodes, int ticks, double probability, int maxTasks)
  : totalTicks(ticks), taskProbability(probability), maxTasksPerTick(maxTasks), cluster(nodes) {}

void Simulation::run() 
{
  for (int tick = 1; tick <= totalTicks; ++tick) 
  {
    std::cout << "\n========================================\n";
    std::cout << "���� " << tick << ":" << std::endl;

    cluster.tick();
    generateTasks();
    processTasks();
    printTasksInQueue();
    cluster.printTasksInCluster();
    printStatus();
    totalLoadPercentage += cluster.getCurrentLoadPercentage();
  }

  double averageLoadPercentage = totalLoadPercentage / totalTicks;
  printFinalStatistics(averageLoadPercentage);
  std::cout << "========================================\n";
}

void Simulation::generateTasks() 
{
  int tasksToGenerate = (randomDouble() < taskProbability) ? randomInt(1, maxTasksPerTick) : 0;
  std::cout << "��������������� ������ �� ����: ";
  for (int i = 0; i < tasksToGenerate; ++i) 
  {
    totalGeneratedTasks++;
    Task newTask(totalGeneratedTasks, randomInt(1, 10), randomInt(1, cluster.getTotalNodes()));
    std::cout << "q_" << newTask.id << "(t:" << newTask.ticksToComplete << ", p:" << newTask.nodesRequired << ") ";
    taskQueue.push(newTask);
  }
  std::cout << std::endl;
}

void Simulation::processTasks() 
{
  while (!taskQueue.empty()) 
  {
    const Task& task = taskQueue.front();
    if (cluster.addTask(task)) 
    {
      taskQueue.pop();
      completedTasks++;
    }
    else 
    {
      failedTasks++;
      break;
    }
  }
}

void Simulation::printStatus() const 
{
  std::cout << "������������ �����: " << cluster.getUsedNodes() << "\\" << cluster.getTotalNodes() << std::endl;
}

void Simulation::printFinalStatistics(double averageLoad) const 
{
  int unfinishedTasks = cluster.getUnfinishedTasksCount();
  std::cout << "��������� ���������." << std::endl
    << "����� ������: " << totalTicks << std::endl
    << "����������� ������: " << (completedTasks - unfinishedTasks) << std::endl
    << "���������� ������: " << (failedTasks + unfinishedTasks) << std::endl
    << "����� �����: " << (completedTasks + failedTasks) << std::endl
    << "������� ������� ��������: " << averageLoad << "%" << std::endl;
}

int Simulation::randomInt(int min, int max) 
{
  static std::random_device rd;
  static std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(eng);
}

double Simulation::randomDouble() 
{
  static std::random_device rd;
  static std::mt19937 eng(rd());
  std::uniform_real_distribution<> distr(0.0, 1.0);
  return distr(eng);
}

void Simulation::printTasksInQueue() const 
{
  std::queue<Task> tempQueue = taskQueue;
  std::cout << "������ � �������: ";
  while (!tempQueue.empty()) 
  {
    const Task& task = tempQueue.front();
    std::cout << "q_" << task.id << "(" << task.ticksToComplete << ", " << task.nodesRequired << ") ";
    tempQueue.pop();
  }
  std::cout << std::endl;
}
