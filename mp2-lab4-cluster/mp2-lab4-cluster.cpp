#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <clocale>

class Task 
{
public:
  int id;
  int ticksToComplete;
  int nodesRequired;

  Task(int id, int duration, int nodes) : id(id), ticksToComplete(duration), nodesRequired(nodes) {}
};

class Cluster 
{
  int totalNodes;
  int usedNodes = 0;
  std::vector<Task> tasks;

public:
  Cluster(int total) : totalNodes(total) {}

  bool addTask(const Task& task) 
  {
    if (usedNodes + task.nodesRequired <= totalNodes) 
    {
      usedNodes += task.nodesRequired;
      tasks.push_back(task);
      return true;
    }
    return false;
  }

  void tick() {
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

  void printTasksInCluster() const 
  {
    std::cout << "Задачи в кластере: ";
    for (const auto& task : tasks) 
    {
      std::cout << "q_" << task.id << "(" << task.ticksToComplete << ", " << task.nodesRequired << ") ";
    }
    std::cout << std::endl;
  }

  int getUsedNodes() const 
  {
    return usedNodes;
  }

  int getTotalNodes() const 
  {
    return totalNodes;
  }

  int getUnfinishedTasksCount() const 
  {
    return tasks.size();
  }

  double getCurrentLoadPercentage() const 
  {
    return (static_cast<double>(usedNodes) / totalNodes) * 100.0;
  }
};

class Simulation 
{
  int totalTicks;
  double taskProbability;
  int maxTasksPerTick;
  Cluster cluster;
  std::queue<Task> taskQueue;
  int totalGeneratedTasks = 0;
  int completedTasks = 0;
  int failedTasks = 0;
  double totalLoadPercentage = 0.0;

public:
  Simulation(int nodes, int ticks, double probability, int maxTasks)
    : totalTicks(ticks), taskProbability(probability), maxTasksPerTick(maxTasks), cluster(nodes) {}

  void run() 
  {
    for (int tick = 1; tick <= totalTicks; ++tick) 
    {
      std::cout << "\n========================================\n";
      std::cout << "Такт " << tick << ":" << std::endl;

      // Обновляем состояние кластера
      cluster.tick();

      // Генерируем новые задачи и выводим информацию о них
      generateTasks();

      // Обрабатываем задачи
      processTasks();

      // Выводим информацию о задачах в очереди и в кластере
      printTasksInQueue();
      cluster.printTasksInCluster();
      printStatus();
      // Обновляем общий процент загрузки
      totalLoadPercentage += cluster.getCurrentLoadPercentage();
    }

    // Вычисляем средний процент загрузки
    double averageLoadPercentage = totalLoadPercentage / totalTicks;
    printFinalStatistics(averageLoadPercentage);
    std::cout << "========================================\n";
  }


private:
  void generateTasks() 
  {
    int tasksToGenerate = (randomDouble() < taskProbability) ? randomInt(1, maxTasksPerTick) : 0;
    std::cout << "Сгенерированные задачи на такт: ";
    for (int i = 0; i < tasksToGenerate; ++i) 
    {
      totalGeneratedTasks++;
      Task newTask(totalGeneratedTasks, randomInt(1, 10), randomInt(1, cluster.getTotalNodes()));
      std::cout << "q_" << newTask.id << "(t:" << newTask.ticksToComplete << ", p:" << newTask.nodesRequired << ") ";
      taskQueue.push(newTask);
    }
    std::cout << std::endl;
  }


  void processTasks() 
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

  void printStatus() const 
  {
    std::cout << "Используется узлов: " << cluster.getUsedNodes() << "\\" << cluster.getTotalNodes() << std::endl;
  }

  void printFinalStatistics(double averageLoad) const 
  {
    int unfinishedTasks = cluster.getUnfinishedTasksCount();
    std::cout << "Симуляция завершена." << std::endl
      << "Всего тактов: " << totalTicks << std::endl
      << "Выполненные задачи: " << (completedTasks - unfinishedTasks) << std::endl
      << "Проваленые задачи: " << (failedTasks + unfinishedTasks) << std::endl
      << "Всего задач: " << (completedTasks + failedTasks) << std::endl
      << "Средний процент загрузки: " << averageLoad << "%" << std::endl;
  }


  static int randomInt(int min, int max) 
  {
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
  }

  static double randomDouble() 
  {
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_real_distribution<> distr(0.0, 1.0);
    return distr(eng);
  }

  void printTasksInQueue() const 
  {
    std::queue<Task> tempQueue = taskQueue;
    std::cout << "Задачи в очереди: ";
    while (!tempQueue.empty()) 
    {
      const Task& task = tempQueue.front();
      std::cout << "q_" << task.id << "(" << task.ticksToComplete << ", " << task.nodesRequired << ") ";
      tempQueue.pop();
    }
    std::cout << std::endl;
  }

};

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
