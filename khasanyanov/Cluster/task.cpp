#include "task.h"


Task::Task(size_t Nodes) : closed(0) {
	number = rand() % 1000;
	tacts = 1 + (rand() % (MaxTactsOfTask - 1));
	nodes = 1 + (rand() % (Nodes - 1));
}

void Task::work() { 
	tacts--; 
	closed = tacts == 0;
}

bool Task::is_closed() const { return closed; }

size_t Task::get_nodes() const { return nodes; }

size_t Task::get_tacts() const { return tacts; }

size_t Task::get_number() const { return number; }
