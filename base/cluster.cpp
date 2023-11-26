#include "tcluster.h"

Cluster::Node::Node() : isBusy(false), remainingTime(0), nodeCount(0) {}
Cluster::Cluster(int Nodes) : nodes(Nodes) {}

void Cluster::addTask(const Task& task) {
	taskQueue.enqueue(task);
	totalTasks++;
	uncompletedTask++;
}

// Распределение задач по узлам
void Cluster::distributeTasks() {
	while (!taskQueue.isEmpty()) {
		Task task = taskQueue.peek();
		int availableNodes = 0;
		for (auto& node : nodes) {
			if (!node.isBusy) {
				availableNodes++;
				if (availableNodes == task.p) {
					int count = task.p;
					for (auto& node : nodes) {
						if (!node.isBusy && count > 0) {
							node.isBusy = true;
							node.remainingTime = task.t;
							node.nodeCount = task.p;
							count--;
						}
					}
					progressTask++;
					taskQueue.dequeue();
					break;
				}
			}
		}
		if (availableNodes < task.p) {
			break;
		}
	}
}

// Обновление состояния задач в кластере
void Cluster::updateTasks() {
	vector<int> completedTasksIndices;
	for (size_t i = 0; i < nodes.size(); ++i) {
		auto& node = nodes[i];
		if (node.isBusy) {
			node.remainingTime--;
			if (node.remainingTime <= 0) {
				node.isBusy = false;
				completedTask++;
				if (find(completedTasksIndices.begin(), completedTasksIndices.end(), node.nodeCount) == completedTasksIndices.end()) {
					completedTasksIndices.push_back(node.nodeCount);
					progressTask--;
				}
				int nodesToFree = node.nodeCount;
				for (auto& innerNode : nodes) {
					if (innerNode.nodeCount == node.nodeCount && nodesToFree > 0) {
						innerNode.isBusy = false;
						nodesToFree--;
					}
				}
			}
		}
	}
	uncompletedTask = totalTasks - completedTask;
}

// Получение процентной загрузки кластера
double Cluster::getLoadPercentage() const {
	int busyCount = 0;
	for (const auto& node : nodes) {
		if (node.isBusy) busyCount++;
	}
	return static_cast<double>(busyCount) / nodes.size() * 100.0;
}

// Получение количества занятых узлов
int Cluster::getBusyNodeCount() const {
	int count = 0;
	for (const auto& node : nodes) {
		if (node.isBusy) count++;
	}
	return count;
}

// Получение статистики задач
int Cluster::getCurrentTaskCount() const { return progressTask; }
int Cluster::getTasksCompleted() const { return completedTask; }
int Cluster::getTasksUncompleted() const { return uncompletedTask; }
int Cluster::getTotalTasks() const { return totalTasks; }
double Cluster::getAverageLoadPercent(int T) const { return totalLoadPercent / T; }
void Cluster::updateLoadPercent(double load) { totalLoadPercent += load; }
