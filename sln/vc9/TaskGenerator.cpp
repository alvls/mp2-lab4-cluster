#include <ctime>
#include <random>
#include "Queue_task.cpp"
class TaskGenerator {
	int Max_time = 15;
	int Max_nodes = 15;
	double p;
	Queue_task Tasks;
public:
	TaskGenerator(double _p) { p = _p; }
	void createTask() {
		srand(time(0));
		double chanse;
		Task tmp;
		for (int i = 0; i < 10; i++) {
			chanse = rand() % 100;
			if (chanse < p * 100) {
				tmp.time = rand() % Max_time;
				tmp.number_of_nodes = rand() % Max_nodes;
				Tasks.Push(tmp);
			}
		}
	}
	Queue_task GetTasks() { return Tasks; }
	void SetTasks(Queue_task tmp) { Tasks = tmp; }
	void ChangeP(double _p) { p = _p; }
};