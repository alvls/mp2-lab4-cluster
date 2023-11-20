#ifndef __TASK_H__
#define __TASK_H__

#include"queue.h"
#include <ctime>

#define DefValue 10

using namespace std;

class Task {
	size_t number, tacts, nodes;
	bool closed;
public:
	Task(size_t Nodes);
	void work();
	bool is_closed() const;
	size_t get_nodes() const;
	size_t get_tacts() const;
	size_t get_number() const;
};



#endif
