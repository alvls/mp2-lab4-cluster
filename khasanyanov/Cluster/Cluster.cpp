#include "cluster.h"
#include <iostream>

Cluster::Cluster() : Cluster(64, 1000) {}

Cluster::Cluster(size_t N, size_t T): nodes(N), tacts(T), busy_nodes(0) {
	if (N <= 0 || T <= 0) throw invalid_argument("invalid params");
	srand(time(NULL));
	lambda = rand() % 1000;
}

Cluster::Cluster(size_t N, size_t T, double L) : nodes(N), tacts(T), busy_nodes(0), lambda(L * 1000) { 
	if (N <= 0 || T <= 0 || lambda <= 0) throw invalid_argument("invalid params"); 
}

size_t Cluster::get_nodes() const noexcept { return nodes; }

size_t Cluster::get_busy_nodes() const noexcept { return busy_nodes; }

double Cluster::get_lambda() const noexcept { return static_cast<double>(lambda) / 1000; }

size_t Cluster::get_tacts() const noexcept { return tacts; }

vector<Task> Cluster::get_tasks() const { return tasks; }

void Cluster::start(){
	for(size_t i = tacts; i > 0; i--) {
		generate_tasks();
		process_tasks();
	}
	update_stat();
}

void Cluster::process_tasks(){	
	while (!queue.empty() && nodes - busy_nodes >= queue.first().get_nodes()) {
		busy_nodes += queue.first().get_nodes();
		tasks.push_back(queue.get());
	}
	statistic.I += static_cast<double>(busy_nodes) / nodes;
	if (!tasks.empty())
	{
		size_t size = tasks.size();
		for (size_t i = size; i-- > 0;) {
			Task& t = tasks[i];
			t.work();
			if (t.is_closed()) {
				busy_nodes -= t.get_nodes();
				tasks.erase(tasks.begin() + i);
				statistic.executed_tasks++;
			}
		}
	}
	else
		statistic.free_tacts++;
}

void Cluster::generate_tasks(){
	size_t k = rand() % MaxTasksForTact;
	for (size_t i = 0; i < k; i++) {
		size_t l = rand() % 1000;
		if (l < lambda)
			queue.add({nodes});
	}
}

void Cluster::update_stat(){
	statistic.I /= tacts;
	statistic.failed_tasks += (tasks.size() + queue.size());
	statistic.summary_tasks = statistic.failed_tasks + statistic.executed_tasks;
}

typename Cluster::Statistic Cluster::get_stat() const { return statistic; }
