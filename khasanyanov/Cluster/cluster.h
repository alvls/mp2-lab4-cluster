#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>

const size_t MaxTasksForTact = 5;

using namespace std;

class Cluster {
	struct Statistic {
		size_t executed_tasks = 0;
		size_t failed_tasks = 0;
		size_t summary_tasks = 0;
		double I = 0.0;                  //процент загрузки
	};
private:
	size_t nodes;
	size_t tacts;
	size_t busy_nodes;
	Queue<Task> queue;
	vector<Task> tasks;
	size_t lambda;
	Statistic statistic;
public:
	Cluster();
	Cluster(size_t N, size_t T);
	void start();
	void process_tasks();
	void generate_tasks();
	void update_stat();
	Statistic get_stat() const;

};

#endif
