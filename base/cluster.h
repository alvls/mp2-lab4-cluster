#pragma once
#ifndef _Cluster_
#define _Cluster_
#include "queue.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Task {
	int node; // количество узлов для выполнения
	int tact; // количество тактов для выполнения
};

struct Statistics {
	int AllTasks = 0; // Число появившихся заданий 
	int CompletedTasks = 0; //Число выполненных заданий
	int UnfulfilledTasks = 0;// Число невыполненных заданий
	int TasksLeftInQueue = 0; // Число заданий оставшихся в очереди
	int TasksInProgress = 0; // Количество выполняемых задач на момент завершения
	int СlusterIdleTacts = 0; // Число тактов простоя кластера
	double AverageClusterLoad = 0.0; // Средняя загрузка кластера
	int ttime = 0; // количество тактов работы программы

	friend ostream& operator<< (ostream& out, const Statistics& st); //оператор вывода
};

class Cluster {
private:
	int size = 0; // размер очереди
	int N = 0; // количество узлов
	int K = 0; // максимальное количество задач которые могут появится на одном такте
	int tacts = 0; // количество такотов работы программы
	double frequency = 0.0; // вероятность появления задачи

public:
	Cluster(int s, int t, int n, int k, double f); //конструктор
	Task CreateTask(int n); // создание задачи
	Statistics Process(); // симуляция работы кластера
};

#endif