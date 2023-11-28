#pragma once
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <time.h>
#include "Queue.h"

using namespace std;

struct Task
{
	int remaining_execution_time = 0;
	int computing_node = 0;

	bool empty()
	{
		return (remaining_execution_time == 0);
	}
};

struct Statistics
{
	int time_of_working;
	int count_of_completed;
	int count_of_incompleted;
	double cluster_load;

	Statistics(int time, int done, int undone, double load) : time_of_working(time), count_of_completed(done),
		count_of_incompleted(undone), cluster_load(load) {};
};

class Cluster
{
	int count_of_computing_nodes;
	float probability_threshold;
	int max_count_of_tasks;
	int max_time_for_task;
	vector<pair<int, Task>> tasks;
	typedef Task(Cluster::* Meneger)(int&);
	Meneger Tasks_meneger;

public:
	Cluster(int N, float alpha, int k, int t, vector<pair<int, Task>> tz = {});

	Task Tasks_meneger1(int &tact);
	Task Tasks_meneger2(int &tact);
	Statistics Implementation(int full_time);

	~Cluster() = default;
};
