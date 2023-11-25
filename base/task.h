#ifndef __TASK_H__
#define __TASK_H__

struct Task {
	int t; //сколько тактов выполняется
	int p; //сколько узлов занимает
	Task(int t, int p) : t(t), p(p) {}
};

#endif
