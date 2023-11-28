#include "Cluster.h"
#include <iostream>

Cluster::Cluster(int total) : totalNodes(total) {}

bool Cluster::addTask(const Task& task) 
{
  if (usedNodes + task.nodesRequired <= totalNodes) 
  {
    usedNodes += task.nodesRequired;
    tasks.push_back(task);
    return true;
  }
  return false;
}

void Cluster::tick() 
{
  for (auto it = tasks.begin(); it != tasks.end();) 
  {
    if (--(it->ticksToComplete) == 0) 
    {
      usedNodes -= it->nodesRequired;
      it = tasks.erase(it);
    }
    else 
    {
      ++it;
    }
  }
}

void Cluster::printTasksInCluster() const 
{
  std::cout << "Задачи в кластере: ";
  for (const auto& task : tasks) 
  {
    std::cout << "q_" << task.id << "(" << task.ticksToComplete << ", " << task.nodesRequired << ") ";
  }
  std::cout << std::endl;
}

int Cluster::getUsedNodes() const 
{
  return usedNodes;
}

int Cluster::getTotalNodes() const 
{
  return totalNodes;
}

int Cluster::getUnfinishedTasksCount() const 
{
  return tasks.size();
}

double Cluster::getCurrentLoadPercentage() const 
{
  return (static_cast<double>(usedNodes) / totalNodes) * 100.0;
}
