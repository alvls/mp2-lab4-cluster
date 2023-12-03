#include "cluster.h"


Cluster::Node::Node() : isBusy(false), remainingTime(0), nodeCount(0) {}
Cluster::Cluster(int Nodes) : nodes(Nodes) {}

void Cluster::addTask(const Task& task) {
	taskQueue.push(task);
	totalTasks++;
	uncompletedTask++;
}
void Cluster::distributeTasks()
{
	while (!taskQueue.isEmpty()) //���� ����� �����������, ���� ������� ����� taskQueue �� ������ ������.
	{
		Task task = taskQueue.frontValue();  //��������� ������ �� ������� ������� � ��������� �� � ���������� task, �� �� ������� �� �������.
		int availableNodes = 0; // ������������� �������� ��������� ����� � ��������.
		for (auto& node : nodes) // ������ ����� �������� ����� � ��������.
		{
			if (!node.isBusy) // ��������, �������� �� ������� ����.
			{
				availableNodes++; // ���������� �������� ��������� �����.
				if (availableNodes == task.nodes) // ��������, ���������� �� ��������� ����� ��� ���������� ������� ������.
				{
					int count = task.nodes; // ������������� �������� �����, ������� ����� ������ ��� ���������� ������.
					for (auto& node : nodes)
					{
						if (!node.isBusy && count > 0) // ��������, �������� �� ������� ���� � ���� �� ��� ����, ������� ����� ������.
						{
							node.isBusy = true; // �������� ���� ��� �������.
							node.remainingTime = task.ticks; // ������������� ����� ���������� ������ ��� ����.
							node.nodeCount = task.nodes; // ������������� ���������� �����, ������� ������ ��������.
							count--; // ��������� ������� ������� �����.
						}
					}
					progressTask++; //���������� �������� ����������� �����.
					taskQueue.pop(); // ���������� ������ �� �������.
					break;
				}
			}
		}
		if (availableNodes < task.nodes) //��������, ���� ��������� ����� ������, ��� ����� ��� ���������� ������.
		{
			break; //����� �� �����, ��� ��� �� ������� ����� ��� ���������� ������.
		}
	}
}
void Cluster::updateTasks()
{
	vector<int> completedTasksIndices; // ������������ �������� ����������� �����.
	for (size_t i = 0; i < nodes.size(); ++i)  // ������ ����� �������� ���� ����� � ��������.
	{
		auto& node = nodes[i]; // �������� ������ node �� ������� ���� � �������� �����.
		if (node.isBusy) // ��������, ����� �� ������� ����
		{
			node.remainingTime--; // ���������� ����������� ������� ���������� ������ �� ������� ����.
			if (node.remainingTime <= 0) // ��������, ����������� �� ������ �� ������� ���� (�������� 0 ��� ������ �������).
			{
				node.isBusy = false; // ������� ���� ��� ����������, ��� ��� ������ ���������.
				completedTask++; // ���������� �������� ����������� �����.
				if (find(completedTasksIndices.begin(), completedTasksIndices.end(), node.nodeCount) == completedTasksIndices.end()) // ��������, �� ���� �� ��� ������ ��� ������ � �����������.
				{
					completedTasksIndices.push_back(node.nodeCount);
					progressTask--;
				}
				int nodesToFree = node.nodeCount; // ������������� �������� �����, ������� ����� ���������� �� ������.
				for (auto& innerNode : nodes)
				{
					if (innerNode.nodeCount == node.nodeCount && nodesToFree > 0)  // ��������, �������� �� ������� ���������� ���� ��� �� ����� ������ � ���� �� ��� ���� ��� ������������.
					{
						innerNode.isBusy = false;  // ������������ ���� �� ������.
						nodesToFree--; // ���������� �������� ���������� ����� ��� ������������.
					}
				}
			}
		}
	}
	uncompletedTask = totalTasks - completedTask; // ���������� ���������� ������������� ����� � ��������.
}

double Cluster::getLoadPercentage() const
{
	int busyCount = 0;
	for (const auto& node : nodes)
	{
		if (node.isBusy) busyCount++; // ��������, �������� �� ������� ���� �������. ���������� �������� ������� �����, ���� ������� ���� �����.
	}
	return static_cast<double>(busyCount) / nodes.size() * 100.0; // ����������� ����������� �������� ������� ����� � ��������.
}
int Cluster::getBusyNodeCount() const {
	int count = 0;
	for (const auto& node : nodes) {
		if (node.isBusy) count++;
	}
	return count;
}
void Cluster::updateLoadPercent(double load) { totalLoadPercent += load; }
int Cluster::getCurrentTaskCount() const { return progressTask; }
int Cluster::getTasksCompleted() const { return completedTask; }
int Cluster::TotalTasksUncompleted() const { return uncompletedTask; }
int Cluster::TotalTasks() const { return totalTasks; }
double Cluster::getAverageLoadPercent(int T) const { return totalLoadPercent / T; }
