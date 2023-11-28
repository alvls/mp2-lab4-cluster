#include "task.h"

Task::Task()
{
	p = 1 + rand() % 16;
	t = 1 + rand() % 15;
}
Task::Task(const Task& _t)
{
	p = _t.p;
	t = _t.t;
}
void Task::ChangeT()
{
	t--;
}