#include "cluster.h"
#include <stdexcept>
#include <ctime>
#include <iostream>

using namespace std;

TCluster::TCluster(unsigned int _nodes, unsigned int _tacts, double _alpha)
	: alpha(_alpha)
{
	stat.free_nodes = stat.total_nodes = _nodes;
	stat.cycles = _tacts;

	if (_alpha <= 0 || _alpha >= 1)
	{
		throw invalid_argument("вероятность появления задачи a должна быть больше 0 и меньше 1");
	}

	if (_nodes <= 0)
	{
		throw invalid_argument("количество узлов должно быть целым и не меньшим 1");
	}

	if (_tacts <= 0)
	{
		throw invalid_argument("количество тактов должно быть целым и не меньшим 1");
	}

	srand(time(nullptr));
}

void TCluster::add_task(const Task& task)
{
	stat.total_tasks++;
	if (task.requiredNodes > stat.total_nodes)
	{
		stat.discarded_tasks++;
		return;
	}
	queue.push_back(task);
}

void TCluster::run_cycle()
{
	while (!queue.is_empty() && (stat.free_nodes >= queue.peek().requiredNodes))
	{
		stat.free_nodes -= queue.peek().requiredNodes;
		processing_tasks.push_back(queue.pull());
	}
	stat.workload += stat.get_current_workload();

	if (processing_tasks.empty())
	{
		stat.idle_cycles++;
		return;
	}
	size_t size = processing_tasks.size();
	for (size_t i = size; i-- > 0;)
	{
		Task& task = processing_tasks[i];
		task.tacts--;

		if (task.tacts == 0)
		{
			stat.free_nodes += task.requiredNodes;
			processing_tasks.erase(processing_tasks.begin() + i);
			stat.completed_tasks++;
		}
	}
}

void TCluster::exec()
{
	unsigned int tacts = stat.cycles;
	while (tacts > 0)
	{
		generate_tasks();
		run_cycle();
		tacts--;
	}
	stat.avg_workload = (stat.workload / stat.cycles) * 100;
	stat.discarded_tasks += (queue.size() + processing_tasks.size());
}

void TCluster::generate_tasks()
{
	for (int i = 0; i < 4; i++)
	{
		double p = static_cast<double>((rand() % 1000)) / 1000;
		if (p > alpha)
			continue;
		Task task;

		task.requiredNodes = 16 + (rand() % (64 - 16));
		task.tacts = 1 + (rand() % (4 - 1));
		add_task(task);
	}
}

TCluster::Stats TCluster::get_stats() const
{
	return stat;
}

double TCluster::Stats::get_current_workload()
{
	return static_cast<double>(total_nodes - free_nodes) / total_nodes;
}

ostream& operator<<(ostream& os, const TCluster::Stats& stat)
{
	os << "Время работы программы: " << stat.cycles << " тактов" << endl;
	os << "Всего создано: " << stat.total_tasks << " задач" << endl;
	os << "Выполнено: " << stat.completed_tasks << " задач" << endl;
	os << "Не выполнено: " << stat.discarded_tasks << " задач" << endl;
	os << "Технический простой кластера: " << stat.idle_cycles << " тактов" << endl;
	os << "Процент загрузки кластера (среднее значение): " << stat.avg_workload << "%" << endl;

	return os;
}