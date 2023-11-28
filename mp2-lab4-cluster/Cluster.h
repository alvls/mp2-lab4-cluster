#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include "Task.h" // ����������� ����������� ������ Task

// ����������� ������ Cluster
class Cluster {
  int totalNodes;     // ����� ���������� ����� � ��������
  int usedNodes = 0;  // ���������� ������� �����
  std::vector<Task> tasks; // ������ ����� � ��������

public:
  Cluster(int total); // �����������

  bool addTask(const Task& task); // ���������� ������ � �������
  void tick(); // ��������� ������ ����� �������
  void printTasksInCluster() const; // ����� ���������� � ������� � ��������

  int getUsedNodes() const; // ��������� ���������� ������������ �����
  int getTotalNodes() const; // ��������� ������ ���������� �����
  int getUnfinishedTasksCount() const; // ��������� ���������� ������������� �����
  double getCurrentLoadPercentage() const; // ��������� �������� �������� ��������
};

#endif // CLUSTER_H
