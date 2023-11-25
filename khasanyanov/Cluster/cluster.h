#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>
#include <functional>

using namespace std;

typedef const function<void(void)>& func;

class Cluster {
	struct Statistic {						   // статистика работы кластера
		size_t executed_tasks = 0;			   // выполненные задачи
		size_t failed_tasks = 0;			   // невыполненные задачи
		size_t summary_tasks = 0;			   // общее кол-во задач
		size_t free_tacts = 0;				   // такты простоя
		size_t T = 1;						   // кол-во оставшихся тактов
		double I = 0.0;                        // процент загрузки
	};										 
private:						
	const size_t MaxValueOfNodes = 10000;      // максимальное число узлов 
	const double MinValueOfLambda = 0.333;	   // нижняя граница лямбды
	const size_t MaxTasksForTact = 3;		   // максимальное количество новых задач за такт
	size_t nodes;							   // кол-во узлов
	size_t tacts;							   // кол-во тактов работы кластера
	size_t busy_nodes;						   // занятые узлы
	Queue<Task> queue;						   // очередь задач
	vector<Task> tasks;						   // выполняемые задачи
	double lambda;							   // вероятность появления задачи на такте
	Statistic statistic;					   // статистика
	void process_tasks();					   // выполнение задач
	void generate_tasks();					   // генерация задач
	void update_stat();						   // подсчёт статистики
public:										   
	Cluster();								   // конструктор по умолчанию
	Cluster(size_t N, size_t T);			   // конструктор-инициализатор
	Cluster(size_t N, size_t T, double L);	   // конструктор-инициализатор
	void start(func f);                        // запуск работы кластера
											   
	size_t get_nodes() const noexcept;		   //геттеры
	size_t get_tacts() const noexcept;		
	size_t get_busy_nodes() const noexcept; 
	double get_lambda() const noexcept;
	vector<Task> get_tasks() const;
	Queue<Task> get_queue() const; 
	Statistic get_stat() const;
};

#endif
