#include "task.h"


Task::Task(size_t Nodes = 64){
	srand(time(NULL));
	number = rand() % DefValue;
	tacts = 1 + rand() % (DefValue - 1);
	nodes = 1 + rand() % (Nodes - 1);
}
