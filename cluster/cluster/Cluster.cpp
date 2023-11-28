#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "Interface.h"
#include <windows.h>
#include "Cluster.h"
#include "Console.h"
#include "Queue.h"
#include <conio.h>
#include "Task.h"

using namespace std;


cluster::cluster(
	int availableNodes,
	unsigned int tactTime,
	unsigned int tasksPerTact,
	unsigned int taskTaktsLimit,
	double taskAppearLimit) :
	tañtTime(tactTime),
	tasksPerTañt(tasksPerTact),
	taskTañtsLimit(taskTaktsLimit) {

	if (availableNodes < 16 || availableNodes > 64) { throw runtime_error("Invalid count of nodes"); }

	this->availableNodes = availableNodes;
	initialNodes = availableNodes;

	if (taskAppearLimit <= 0 || taskAppearLimit >= 1.0) { throw runtime_error("Invalid taskAppearLimit"); }

	this->taskAppearLimit = taskAppearLimit;
}

void cluster::runCluster() {

	random_device rd;
	mt19937 gen(rd());

	cluster_interface newInterface;
	TStackQueue<task> queue;
	vector<task> runningTasks;
	vector<task> tasks;
	
	double taskProbability = 0.0;
	double loadPercentage = 0.0;
	int tañtsCount = 0;
	int complCount = 0;
	int labelsCount = 1;
	int newTasksCount = 0;
	int runtimeTañtsCount = 0;

	gotoxy(30, 22);
	cout << "Äëÿ âûõîäà íàæìèòå: q/Q.";
	newInterface.drawField();
	newInterface.label("----------------------------------------", 3, 4);
	newInterface.label("----------------------------------------------", 44, 4);
	newInterface.label("Âûïîëíÿþòñÿ:", 65, 3);
	newInterface.label("\t\tÍîâûå çàäà÷è:", 5, 5);
	
	while (true)
	{
		if (_kbhit()) 
		{
			char ch = _getch();
			if (ch == 'q' || ch == 'Q') { break; }
		}

		newInterface.label("\t\tÒåêóùèé òàêò: ¹" + to_string(tañtsCount), 5, 3);
		tasks.clear();

		for (int i = 1; i <= newTasksCount; i++) { newInterface.label("                    ", 5, 6 + i); }

		for (int i = 1; i <= labelsCount; i++)
		{
			newInterface.label("                                     ", 5, 7 + tasksPerTañt + i);
		}

		for (int i = 0; i < runtimeTañtsCount; i++)
		{
			newInterface.label("                                     ", 50, 5 + i);
		}

		for (int i = 0; i < tasksPerTañt; i++)
		{
			if (uniform_real_distribution<double>{0.1, 0.9}(gen) <= taskAppearLimit)
			{
				task newTask(taskTañtsLimit, initialNodes);
				
				tasks.push_back(newTask);
				newInterface.label("çàäà÷à ¹" + to_string(newTask.getId()) + " [" + to_string(newTask.getTañts()) + ", " + to_string(newTask.getNodes()) + "]", 5, 6 + tasks.size());
			}
		}
		newInterface.label("----------------------------------------", 3, 7 + tasksPerTañt);
		newTasksCount = tasks.size();
		labelsCount = 1;
		
		for (int i = 0; i < tasks.size(); i++)
		{
			if (tasks[i].getNodes() <= availableNodes && queue.isEmpty())
			{
				availableNodes -= tasks[i].getNodes();
				runningTasks.push_back(tasks[i]);

				textcolor(LIGHTGREEN);
				newInterface.label("çàäà÷à ¹" + to_string(tasks[i].getId()) + " îòïðàâèëàñü íà âûïîëíåíèå.", 5, 7 + tasksPerTañt + labelsCount);
				textcolor(WHITE);
				labelsCount++;
			}
			else
			{
				queue.push(tasks[i]);
				textcolor(BLUE);
				newInterface.label("çàäà÷à ¹" + to_string(tasks[i].getId()) + " îòïðàâëÿåòñÿ â î÷åðåäü.", 5, 7 + tasksPerTañt + labelsCount);
				textcolor(WHITE);
				labelsCount++;
			}
		}
		runtimeTañtsCount = 0;
		for (int i = 0; i < runningTasks.size(); i++)
		{
			if (runningTasks[i].runTañt())
			{
				newInterface.drawProcess(runningTasks[i], 50, 5 + i);
				runtimeTañtsCount++;
				continue;
			}

			textcolor(YELLOW);
			newInterface.label("çàäà÷à ¹" + to_string(runningTasks[i].getId()) + " çàâåðøåíà!", 5, 7 + tasksPerTañt + labelsCount);
			textcolor(WHITE);
				
			complCount++;
			labelsCount++;
			runtimeTañtsCount++;

			availableNodes += runningTasks[i].getNodes();
			runningTasks.erase(runningTasks.begin() + i);
			i--;

			if (!queue.isEmpty())
			{
				for (int j = 0; j < queue.size(); j++)
				{
					if (queue.top().getNodes() <= availableNodes)
					{
						runningTasks.push_back(queue.pop());
						availableNodes -= runningTasks.back().getNodes();		

						textcolor(LIGHTGREEN);
						newInterface.label("çàäà÷à ¹" + to_string(runningTasks.back().getId()) + " îòïðàâèëàñü íà âûïîëíåíèå.", 5, 7 + tasksPerTañt + labelsCount);
						textcolor(WHITE);

						labelsCount++;
						j--;
					}
					else { break; }
				}
			}	
		}
		tañtsCount++;
		loadPercentage += static_cast<double>(initialNodes - availableNodes) / initialNodes;
		Sleep(tañtTime);
	}
	clrscr();
	cout << "\n~~~~~~~~~~ÑÒÀÒÈÑÒÈÊÀ~~~~~~~~~~\n";
	cout << "Òàêòîâ îòðàáîòàíî: " << tañtsCount << endl;
	cout << "Çàäà÷ âûïîëíåíî: " << complCount << endl;
	cout << "Çàäà÷ íå âûïîëíåíî: " << queue.size() + runningTasks.size() << endl;
	cout << "Âñåãî  çàäà÷: " << queue.size() + runningTasks.size() + complCount << endl;
	cout << "Ïðîöåíò çàãðóçêè êëàñòåðà: " << static_cast<int>(round(loadPercentage / tañtsCount * 100)) << "%\n\n" << endl;
}
