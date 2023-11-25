#include "task.h"

Task::Task() : Task(64) {}

Task::Task(size_t Nodes) : closed(0) {
	tacts = 1 + (rand() % (MaxTactsOfTask - 1));
	nodes = 1 + (rand() % (Nodes - 1));
}

void Task::work() { 
	tacts--; 
	closed = tacts == 0;
}

bool Task::is_closed() const noexcept{ return closed; }

size_t Task::get_nodes() const noexcept { return nodes; }

size_t Task::get_tacts() const noexcept { return tacts; }
