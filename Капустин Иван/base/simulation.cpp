#include "simul.h"
#include <iostream>
#include <cstdlib>


Simulation::Simulation(int Nodes, double limit, int maxPR)
	: cluster(Nodes), maxNodes(Nodes), limits(limit), max(maxPR), time(0), generation(rand()), distrib(0.0, 1.0) {}
void Simulation::displayState()
{
	cout << "������� ��������� ��������: " << endl;
	cout << "�������� ��������: " << cluster.getLoadPercentage() << "%" << endl;
	cout << "���������� ����������� �����: " << cluster.getCurrentTaskCount() << endl;
	cout << "���������� ������� �����: " << cluster.getBusyNodeCount() << endl;
	cout << "����� ����� � �������: " << cluster.taskQueue.getSize() << endl << endl;
	cout << "����� ����������� �����: " << cluster.getTasksCompleted() << endl;
	cout << "����� ������������� �����: " << cluster.TotalTasksUncompleted() << endl;
	cout << "����� ����� �����: " << cluster.TotalTasks() << endl << endl;
}

void Simulation::displayFinalStatistics(int time)
{
	cout << "�������� ���������� ���������: " << endl;
	cout << "����� ���������� ������: " << time << endl;
	cout << "����� ����������� �����: " << cluster.getTasksCompleted() << endl;
	cout << "����� ������������� �����: " << cluster.TotalTasksUncompleted() << endl;
	cout << "����� ����� �����: " << cluster.TotalTasks() << endl;
	cout << "������� ������� �������� ��������: " << cluster.getAverageLoadPercent(time) << "%" << endl;
}
void Simulation::generateTasks()
{
	for (int i = 0; i < max; i++)
	{
		if (distrib(generation) < limits)
		{
			int temp1 = rand() % 10 + 1;
			int temp2 = rand() % (maxNodes - 1) + 2;
			cluster.addTask(Task(temp1, temp2));
		}
	}
}
void Simulation::processTact()
{
	generateTasks();
	cluster.updateTasks();
	cluster.distributeTasks();
	cluster.updateLoadPercent(cluster.getLoadPercentage());
	time++;
}