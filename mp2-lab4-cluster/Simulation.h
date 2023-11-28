#ifndef SIMULATION_H
#define SIMULATION_H

#include "Cluster.h"
#include <queue>

// ����������� ������ Simulation
class Simulation {
  int totalTicks; // ����� ���������� ������
  double taskProbability; // ����������� ��������� ������ �� ������ �����
  int maxTasksPerTick; // ������������ ���������� ����� �� ����
  Cluster cluster; // ������ ��������
  std::queue<Task> taskQueue; // ������� �����
  int totalGeneratedTasks = 0; // ����� ���������� ��������������� �����
  int completedTasks = 0; // ���������� ����������� �����
  int failedTasks = 0; // ���������� ����������� �����
  double totalLoadPercentage = 0.0; // ����� ������� ��������

public:
  Simulation(int nodes, int ticks, double probability, int maxTasks); // �����������

  void run(); // ����� ��� ������� ���������

private:
  void generateTasks(); // ��������� �����
  void processTasks(); // ��������� �����
  void printStatus() const; // ����� �������� �������
  void printFinalStatistics(double averageLoad) const; // ����� �������� ����������

  static int randomInt(int min, int max); // ��������� ���������� ������ �����
  static double randomDouble(); // ��������� ���������� �������� �����
  void printTasksInQueue() const; // ����� ����� � �������
};

#endif // SIMULATION_H
