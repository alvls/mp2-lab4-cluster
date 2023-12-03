#ifndef __TCLUSTER_H__
#define __TCLUSTER_H__

#include <vector>
#include "q.h"
#include "task.h"

using namespace std;

class Cluster
{
private:
	struct Node {
		bool isBusy; // ����, �����������, ����� �� ���� ����������� ������.
		int nodeCount; // ���������� ����� (��������) � ���� ����.
		int remainingTime; //���������� ����� ���������� ������ �� ���� ����.
		Node();
	};
	int progressTask = 0;
	int completedTask = 0;
	int uncompletedTask = 0;
	int totalTasks = 0;
	double totalLoadPercent = 0.0;
	vector<Node> nodes;
public:
	MyQueue<Task> taskQueue;
	Cluster(int totalNodes); //�������������� ������� � �������� ����� ����������� �����.
	void updateLoadPercent(double load);
	int getTasksCompleted() const;
	int TotalTasksUncompleted() const;
	int TotalTasks() const;
	double getAverageLoadPercent(int T) const;
	void addTask(const Task& task);
	void distributeTasks();
	void updateTasks();
	double getLoadPercentage() const;
	int getCurrentTaskCount() const;
	int getBusyNodeCount() const;
};
#endif
