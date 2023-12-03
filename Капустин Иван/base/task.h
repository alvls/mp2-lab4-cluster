#ifndef TASK_H
#define TASK_H

struct Task
{
	int ticks;
	int nodes;
	Task(int t, int n) : ticks(t), nodes(n) {}
};
#endif

