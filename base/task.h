#ifndef __TASK_H__
#define __TASK_H__

struct Task {
	int t; // Количество занимаемых тактов
	int p; // Количество занимаемых узлов
	Task(int t, int p) : t(t), p(p) {}
};

#endif
