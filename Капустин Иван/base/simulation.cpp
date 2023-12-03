#include "simul.h"
#include <iostream>
#include <cstdlib>


Simulation::Simulation(int Nodes, double limit, int maxPR)
	: cluster(Nodes), maxNodes(Nodes), limits(limit), max(maxPR), time(0), generation(rand()), distrib(0.0, 1.0) {}
void Simulation::displayState()
{
	cout << "Текущее состояние кластера: " << endl;
	cout << "Загрузка кластера: " << cluster.getLoadPercentage() << "%" << endl;
	cout << "Количество исполняемых задач: " << cluster.getCurrentTaskCount() << endl;
	cout << "Количество занятых узлов: " << cluster.getBusyNodeCount() << endl;
	cout << "Число задач в очереди: " << cluster.taskQueue.getSize() << endl << endl;
	cout << "Число выполненных задач: " << cluster.getTasksCompleted() << endl;
	cout << "Число невыполненных задач: " << cluster.TotalTasksUncompleted() << endl;
	cout << "Общее число задач: " << cluster.TotalTasks() << endl << endl;
}

void Simulation::displayFinalStatistics(int time)
{
	cout << "Итоговая статистика симуляции: " << endl;
	cout << "Общее количество тактов: " << time << endl;
	cout << "Число выполненных задач: " << cluster.getTasksCompleted() << endl;
	cout << "Число невыполненных задач: " << cluster.TotalTasksUncompleted() << endl;
	cout << "Общее число задач: " << cluster.TotalTasks() << endl;
	cout << "Средний процент загрузки кластера: " << cluster.getAverageLoadPercent(time) << "%" << endl;
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