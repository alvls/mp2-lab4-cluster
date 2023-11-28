#pragma once

using namespace std;


class cluster {

public:
	/** @param availableNodes количество узлов кластера.
		@param taktTime продолжительность такта в мс. 
		@param tasksPerTakt количество задач на такт, которые могут появиться. 
		@param taskTaktsLimit предел генерации тактов задач. 
		@param taskAppearLimit вероятность появления задачи. 
		*/
	cluster(
		int availableNodes,
		unsigned int taсtTime,
		unsigned int tasksPerTaсt,
		unsigned int taskTaсtsLimit,
		double taskAppearLimit);

	cluster() = default;
	/* Запуск эмитации работы кластера. */
	void runCluster();

private:
	int availableNodes = 48;      // Доступное количество узлов
	int initialNodes = 48;        // Исходное количество узлов (клонов)
	unsigned int taсtTime = 10000; // Продолжительность такта
	unsigned int tasksPerTaсt = 1; // Количество задач в каждом такте
	unsigned int taskTaсtsLimit = 5; // Лимит тактов на выполнение задачи
	double taskAppearLimit = 0.3;   // Предел появления задач
};