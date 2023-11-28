#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "LinkedList.h"
#include "Queue.h"
#include <vector>
#include <iostream>

using namespace std;

struct Task
{
	size_t tacts; // время выполнения задачи (в тактах)
	int requiredNodes; // требуемое количество узлов для выполнения задачи
};

class TCluster
{
public:
	struct Stats
	{
		unsigned int total_tasks = 0;
		unsigned int completed_tasks = 0;
		unsigned int discarded_tasks = 0; // количество невыполненных задач
		unsigned int total_nodes = 0;
		unsigned int free_nodes = 0;
		unsigned int cycles = 0; // количество тактов
		unsigned int idle_cycles = 0; // количество тактов простоя
		double workload = 0; // загрузка кластера (отношение занятых узлов к свободным)
		double avg_workload = 0; // среднее значение загрузки кластера (в процентах)

		double get_current_workload();

		friend ostream& operator<< (ostream& os, const Stats& stat);
	};

private:
	Stats stat;
	double alpha;

	TQueue<Task> queue;
	vector<Task> processing_tasks;

public:
	TCluster(unsigned int _nodes, unsigned int _tacts, double _alpha);

	void add_task(const Task& task);
	void run_cycle();
	void exec();
	void generate_tasks();
	Stats get_stats() const;


};

#endif
