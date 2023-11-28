#include "Cluster.h"

Cluster::Cluster(int N, float alpha, int k, int t, vector<pair<int, Task>> tz)
{
	if ((N < 16) || (N > 64))
		throw "Incorrect count of computing nodes";
	if ((alpha <= 0) || (alpha >= 1))
		throw "Incorrect probability threshold";
	if (k < 1)
		throw "Incorrect maximum count of new tasks";
	if (t < 1)
		throw "Incorrect maximum time for one task";

	count_of_computing_nodes = N;
	probability_threshold = alpha;
	max_count_of_tasks = k;
	max_time_for_task = t;
	tasks = tz;
	Tasks_meneger = (tasks.size() == 0) ? &Cluster::Tasks_meneger1 : &Cluster::Tasks_meneger2;

	srand(time(NULL));
}

Task Cluster::Tasks_meneger1(int &tact)
{
	Task task;

	if ((double)(rand() % 999 + 1) / 1000 > probability_threshold)
		task = { rand() % max_time_for_task + 1, rand() % count_of_computing_nodes + 1 };

	return task;
}

Task Cluster::Tasks_meneger2(int &tact)
{
	Task task;

	if (tasks.size() > 0)
	{
		while ((tasks.size() > 0) && (tasks[0].first < tact))
			tasks.erase(tasks.begin());
		if (tasks[0].first == tact)
		{
			task = tasks[0].second;
			tasks.erase(tasks.begin());
		}
	}

	return task;
}

Statistics Cluster::Implementation(int time)
{
	if (time < 1)
		throw "Incorrect full time of working";

	Queue<Task> pending;
	vector<Task> running;
	Task new_task;
	int count_of_completed = 0;
	int count_of_free_nodes = count_of_computing_nodes;
	double cluster_load = 0.0;
	int tact;
	int counter;

	for (tact = 0; tact <= time; tact++)
	{
		if (_kbhit())
			break;
		counter = 0;
		do
		{
			counter++;
			new_task = (this->*Tasks_meneger)(tact);
			if (!new_task.empty())
				pending.push_back(new_task);
		} while ((counter < max_count_of_tasks) && (!new_task.empty()));

		for (counter = 0; counter < running.size(); )
		{
			running[counter].remaining_execution_time--;
			if (running[counter].remaining_execution_time < 1)
			{
				count_of_completed++;
				count_of_free_nodes += running[counter].computing_node;
				running.erase(running.begin() + counter);
			}
			else counter++;
		}

		while ((!pending.empty()) && (pending.get_next().computing_node <= count_of_free_nodes))
		{
			count_of_free_nodes -= pending.get_next().computing_node;
			running.push_back(pending.pop());
		}
		cluster_load += (double)(count_of_computing_nodes - count_of_free_nodes) / count_of_computing_nodes;
	}

	tact--;
	cluster_load = cluster_load / tact * 100;

	return (Statistics(tact, count_of_completed, running.size() + pending.size(), cluster_load));
}