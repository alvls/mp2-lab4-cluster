#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>

#define MaxTasksForTact 5

using namespace std;

class Cluster {
	struct Statistic {
		size_t executed_tasks = 0, 
		failed_tasks = 0, 
		summary_tasks = 0;
		double I = 0.0;                  //процент загрузки
	};
private:
	size_t nodes;
	size_t tacts;
	size_t busy_nodes;
	Queue<Task> queue;
	vector<Task> tasks;
	double lambda;
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
