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
			if (tmp.number_of_nodes > 64)
				throw "TooBigTask";
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
		std::vector<Task> NewOnGoingTasks;
		for (int i = 0; i < OngoingTasks.size(); i++) {
			OngoingTasks[i].time -= 1; 
			if (OngoingTasks[i].time != 0) {
				NewOnGoingTasks.push_back(OngoingTasks[i]);
			}else{
				MakeTask += 1;
			}
		}
		OngoingTasks = NewOnGoingTasks;
		double val = free_nodes / 64.;
		statistic.push_back(val);
	}
	int GetMakeTask() { return MakeTask; }
	int GetSize() { return OngoingTasks.size(); }
	double GetWorkload() {
		double sum = 0;
		for (int i = 0; i < statistic.size(); i++) {
			sum += statistic[i];
		}
		return sum / statistic.size();
	}
};
