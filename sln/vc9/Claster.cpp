#include "Queue_task.cpp"
#include<vector>
class Claster {
	std::vector<Task> OngoingTasks;
	int free_nodes = 64;
	int MakeTask = 0;
	std::vector<double> statistic;
public:
	Queue_task SetTask(Queue_task New_tasks) {
		Task tmp;
		while (New_tasks.GetSize() != 0) {
			tmp = New_tasks.WatchFirst();
			if (tmp.number_of_nodes < free_nodes) {
				tmp = New_tasks.Pop()->date;
				OngoingTasks.push_back(tmp);
				free_nodes -= tmp.number_of_nodes;
			}
			else { return New_tasks; }
		}
		return New_tasks;
	}
	void maketakt() {
		for (int i = 0; i < OngoingTasks.size(); i++) {
			OngoingTasks[i].time -= 1;
			if (OngoingTasks[i].time == 0) {
				OngoingTasks.erase(OngoingTasks.begin() + i);
				MakeTask += 1;
				free_nodes += OngoingTasks[i].number_of_nodes;
			}
		}
		statistic.push_back(free_nodes / 64);
	}
	int GetMakeTask() { return MakeTask; }
};
