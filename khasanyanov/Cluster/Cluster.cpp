#include "cluster.h"

Cluster::Cluster() : Cluster(64, 1000) {}

Cluster::Cluster(size_t N, size_t T): nodes(N), tacts(T), busy_nodes(0) {
	lambda = (rand() % 1000) / 1000.;
}

void Cluster::start(){
	for(size_t i = tacts; i > 0; i--) {
		generate_tasks();
		process_tasks();
	}
}

void Cluster::process_tasks(){	
	while (!queue.empty() && nodes - busy_nodes >= queue.first().get_nodes()) {
		busy_nodes += queue.first().get_nodes();
		tasks.push_back(queue.get());
	}
	statistic.I += busy_nodes / nodes;
	if(!tasks.empty())
	{
		size_t size = tasks.size();
		for (size_t i = 0; i < size; i++) {
			Task* t = &tasks[i];
			t->work();
			if (t->is_closed()) {
				busy_nodes -= t->get_nodes();
				tasks.erase(tasks.begin() + i);
				statistic.executed_tasks++;
			}
		}
	}
}

void Cluster::generate_tasks(){
	srand(time(NULL));
	size_t k = 1 + rand() % MaxTasksForTact;
	for (size_t i = 0; i < k; i++) {
		size_t l = (rand() % 1000);
		if (l < size_t(lambda * 1000))
			queue.add({nodes});
	}
}

void Cluster::update_stat(){
	statistic.I /= tacts;
	statistic.failed_tasks += (tasks.size() + queue.size());
	statistic.summary_tasks = statistic.failed_tasks + statistic.executed_tasks;
}

typename Cluster::Statistic Cluster::get_stat() const { return statistic; }
