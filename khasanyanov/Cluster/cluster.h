#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>



using namespace std;

class Cluster {
	struct Statistic {
		size_t executed_tasks = 0;
		size_t failed_tasks = 0;
		size_t summary_tasks = 0;
		size_t free_tacts = 0;
		double I = 0.0;                  //процент загрузки
	};
private:
	const size_t MMinValueOfLambda = 333;
	const size_t MaxTasksForTact = 3;
	size_t nodes;
	size_t tacts;
	size_t busy_nodes;
	Queue<Task> queue;
	vector<Task> tasks;
	size_t lambda;
	Statistic statistic;
	void process_tasks();
	void generate_tasks();
	void update_stat();
public:
	Cluster();
	Cluster(size_t N, size_t T);
	Cluster(size_t N, size_t T, double L);
	void start();
	Statistic get_stat() const;
	size_t get_nodes() const noexcept;
	size_t get_busy_nodes() const noexcept;
	double get_lambda() const noexcept;
	vector<Task> get_tasks() const;
};

#endif
