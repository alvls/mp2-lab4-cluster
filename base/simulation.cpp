#include "simulation.h"
#include <iostream>
#include <cstdlib>

Simulation::Simulation(int Nodes, double L, int k)
	: cluster(Nodes), N(Nodes), L(L), k(k), T(0), gen(rd()), dis(0.0, 1.0) {}

void Simulation::generateTasks() {
	for (int i = 0; i < k; ++i) {
		if (dis(gen) < L) {
			int t = rand() % 10 + 1;
			int p = rand() % (N-1) + 2;  // Случайное количество узлов от 1 до N
			cluster.addTask(Task(t, p));
		}
	}
}

// Обработка такта
void Simulation::processTact() {
	generateTasks();
	cluster.updateTasks();
	cluster.distributeTasks();
	cluster.updateLoadPercent(cluster.getLoadPercentage());
	T++;
}

// Отображение текущего состояния кластера
void Simulation::displayState() {
	cout << "Текущее состояние кластера: " << endl;
	cout << "Загрузка кластера: " << cluster.getLoadPercentage() << "%" << endl;
	cout << "Количество исполняемых задач: " << cluster.getCurrentTaskCount() << endl;
	cout << "Количество занятых узлов: " << cluster.getBusyNodeCount() << endl;
	cout << "Число задач в очереди: " << cluster.taskQueue.getSize() << endl << endl;
	cout << "Число выполненных задач: " << cluster.getTasksCompleted() << endl;
	cout << "Число невыполненных задач: " << cluster.getTasksUncompleted() << endl;
	cout << "Общее число задач: " << cluster.getTotalTasks() << endl << endl;
}

// Отображение итоговой статистики симуляции
void Simulation::displayFinalStatistics(int T) {
	cout << "Итоговая статистика симуляции: " << endl;
	cout << "Общее количество тактов: " << T << endl;
	cout << "Число выполненных задач: " << cluster.getTasksCompleted() << endl;
	cout << "Число невыполненных задач: " << cluster.getTasksUncompleted() << endl;
	cout << "Общее число задач: " << cluster.getTotalTasks() << endl;
	cout << "Средний процент загрузки кластера: " << cluster.getAverageLoadPercent(T) << "%" << endl;
}