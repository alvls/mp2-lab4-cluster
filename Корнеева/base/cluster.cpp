#include "cluster.h"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

TCluster::TCluster(size_t nodes)
	: nodes(nodes), nodes_free(nodes), total_tasks(0), completed_tasks(0), total_load(0.0), T(0)
{
	if (nodes < 16 || nodes > 64) 
	{
		throw std::invalid_argument("Некорректное количество узлов (должно быть от 16 до 64)");
	}

	std::srand(std::time(nullptr));
}

void TCluster::generate_tasks(float alpha, int k, int max_tacts)
{
	if (alpha <= 0.0 || alpha >= 1.0)
	{
		throw std::invalid_argument("Некорректное число alpha (должно быть в диапазоне от 0 до 1)");
	}

	if (max_tacts < 1)
	{
		throw std::invalid_argument("Максимальное время выполнения одного задания должно быть не менее 1");
	}

	if (k < 1)
	{
		throw std::invalid_argument("Число k должно быть не менее 1");
	}

	for (int i = 0; i < k; ++i)
	{
		float random_value = static_cast<float>(std::rand()) / RAND_MAX;
		if (random_value < alpha)
		{
			Task new_task;
			new_task.tacts = rand() % max_tacts + 1;
			new_task.required_nodes = rand() % nodes + 1;
			new_task.status = Task::Waiting;
			tasks.push_back(new_task);
			waiting_queue.enqueue(new_task);
			++total_tasks;
		}
	}
}
void TCluster::process()
{
	while (!waiting_queue.empty() && waiting_queue.peek().required_nodes <= nodes_free)
	{
		auto waiting_task = waiting_queue.dequeue();
		nodes_free -= waiting_task.required_nodes;
		waiting_task.status = Task::Processing;
		processing_queue.enqueue(waiting_task);
	}


	for (size_t i = processing_queue.size(); i-- > 0;)
	{
		auto& task = processing_queue.peek();
		task.tacts--;

		if (task.tacts == 0)
		{
			nodes_free += task.required_nodes;
			task.status = Task::Completed;
			processing_queue.dequeue();
			++completed_tasks;
		}
		else
		{
			processing_queue.enqueue(task);
			processing_queue.dequeue();
		}
	}

	total_load += get_cluster_load();
	T++;
}

float TCluster::get_cluster_load() const
{
	return 100.0 * (nodes - nodes_free) / nodes;
}

TCluster::Statistics TCluster::get_statistics() const
{
	Statistics stats;
	stats.time_of_working = total_tasks;
	stats.count_of_completed = completed_tasks;
	stats.count_of_incompleted = total_tasks - completed_tasks;

	if (T > 0)
		stats.cluster_load = total_load / T;
	else
		stats.cluster_load = 0.0;

	return stats;
}
