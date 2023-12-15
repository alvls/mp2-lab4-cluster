#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include <vector>
#include <random>

using namespace std;


class TCluster
{
public:
	struct Task
	{
		int tacts;                     // Время выполнения задачи в тактах
		int required_nodes;            // Количество узлов, необходимых для выполнения задачи
		enum Status
		{
			Waiting,
			Processing,
			Completed
		} status;                      // Статус задачи
	};

	struct Statistics
	{
		size_t time_of_working;         // Общее количество циклов работы
		size_t count_of_completed;      // Количество завершенных задач
		size_t count_of_incompleted;    // Количество незавершенных задач
		float cluster_load;             // Загрузка кластера в процентах
	};

private:
	size_t nodes;                        // Общее количество узлов в кластере
	size_t nodes_free;                   // Количество свободных узлов
	size_t total_tasks;                  // Общее количество созданных задач
	size_t completed_tasks;              // Количество завершенных задач
	vector<Task> tasks;                  // Список всех созданных задач
	TQueue<Task> waiting_queue;          // Очередь ожидания задач
	TQueue<Task> processing_queue;       // Очередь задач на выполнении

	float total_load;                    // Переменная для вычисления суммы нагрузки на кадом такте
	size_t T;                            // Количество тактов

public:
	// Конструктор, устанавливает общее количество узлов
	explicit TCluster(size_t nodes); 

	// Генерация задач согласно заданным параметрам
	void generate_tasks(float alpha, int k, int max_tacts); 

	// Обработка задач в очереди ожидания и на выполнении
	void process();

	// Получение статистики о работе кластера
	Statistics get_statistics() const;

	const vector<Task>& get_waiting_tasks() const { return tasks; }                // Получение списка задач в ожидании
	const TQueue<Task>& get_processing_queue() const { return processing_queue; }  // Получение очереди задач на выполнении
	const TQueue<Task>& get_waiting_queue() const { return waiting_queue; }        // Получение очереди задач в ожидании

	float get_cluster_load() const;                                // Вычисление процента загрузки кластера
	size_t get_total_tasks() const { return total_tasks; }         // Получение общего количества созданных задач
	size_t get_completed_tasks() const { return completed_tasks; } // Получение количества завершенных задач
};

#endif // __CLUSTER_H__