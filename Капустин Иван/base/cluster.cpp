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
	while (!taskQueue.isEmpty()) //Цикл будет выполняться, пока очередь задач taskQueue не станет пустой.
	{
		Task task = taskQueue.frontValue();  //Извлекаем задачу из вершины очереди и сохраняем ее в переменной task, но не удаляем из очереди.
		int availableNodes = 0; // Инициализация счетчика доступных узлов в кластере.
		for (auto& node : nodes) // Начало цикла перебора узлов в кластере.
		{
			if (!node.isBusy) // Проверка, свободен ли текущий узел.
			{
				availableNodes++; // Увеличение счетчика доступных узлов.
				if (availableNodes == task.nodes) // Проверка, достаточно ли доступных узлов для выполнения текущей задачи.
				{
					int count = task.nodes; // Инициализация счетчика узлов, которые нужно занять для выполнения задачи.
					for (auto& node : nodes)
					{
						if (!node.isBusy && count > 0) // Проверка, свободен ли текущий узел и есть ли еще узлы, которые нужно занять.
						{
							node.isBusy = true; // Помечаем узел как занятый.
							node.remainingTime = task.ticks; // Устанавливаем время выполнения задачи для узла.
							node.nodeCount = task.nodes; // Устанавливаем количество узлов, которые задача занимает.
							count--; // Уменьшаем счетчик занятых узлов.
						}
					}
					progressTask++; //Увеличение счетчика выполненных задач.
					taskQueue.pop(); // Извлечение задачи из очереди.
					break;
				}
			}
		}
		if (availableNodes < task.nodes) //Проверка, если доступных узлов меньше, чем нужно для выполнения задачи.
		{
			break; //Выход из цикла, так как не хватает узлов для выполнения задачи.
		}
	}
}
void Cluster::updateTasks()
{
	vector<int> completedTasksIndices; // отслеживания индексов завершенных задач.
	for (size_t i = 0; i < nodes.size(); ++i)  // Начало цикла перебора всех узлов в кластере.
	{
		auto& node = nodes[i]; // Создание ссылки node на текущий узел в итерации цикла.
		if (node.isBusy) // Проверка, занят ли текущий узел
		{
			node.remainingTime--; // Уменьшение оставшегося времени выполнения задачи на текущем узле.
			if (node.remainingTime <= 0) // Проверка, завершилась ли задача на текущем узле (осталось 0 или меньше времени).
			{
				node.isBusy = false; // Пометка узла как свободного, так как задача завершена.
				completedTask++; // Увеличение счетчика выполненных задач.
				if (find(completedTasksIndices.begin(), completedTasksIndices.end(), node.nodeCount) == completedTasksIndices.end()) // Проверка, не была ли эта задача уже учтена в завершенных.
				{
					completedTasksIndices.push_back(node.nodeCount);
					progressTask--;
				}
				int nodesToFree = node.nodeCount; // Инициализация счетчика узлов, которые нужно освободить от задачи.
				for (auto& innerNode : nodes)
				{
					if (innerNode.nodeCount == node.nodeCount && nodesToFree > 0)  // Проверка, является ли текущий внутренний узел тем же типом задачи и есть ли еще узлы для освобождения.
					{
						innerNode.isBusy = false;  // Освобождение узла от задачи.
						nodesToFree--; // Уменьшение счетчика оставшихся узлов для освобождения.
					}
				}
			}
		}
	}
	uncompletedTask = totalTasks - completedTask; // Обновление количества невыполненных задач в кластере.
}

double Cluster::getLoadPercentage() const
{
	int busyCount = 0;
	for (const auto& node : nodes)
	{
		if (node.isBusy) busyCount++; // Проверка, является ли текущий узел занятым. Увеличение счетчика занятых узлов, если текущий узел занят.
	}
	return static_cast<double>(busyCount) / nodes.size() * 100.0; // Возвращение процентного значения занятых узлов в кластере.
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
