#ifndef __TASK_H__
#define __TASK_H__

#include <ctime>
#include <iostream>
using namespace std;

class Task
{
	int p; //кол-во узлов для выполнения
	int t; //время выполнения в тактах
public:
	Task();
	Task(const Task& t);
	int GetNode() { return p; }
	int GetTime() { return t; }
	void ChangeT();
};
#endif
