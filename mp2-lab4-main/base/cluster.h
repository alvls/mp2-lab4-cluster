#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include "task.h"
#include <vector>

class Cluster
{
	double Tmax;//допустимое время работы
	double T;//число тактов работы
	int alpha;//порог появления задачи
	double N;//кол-во узлов
	double n;//кол-во свободных узлов
	double busy;//процент загрузки
	int k;//сколько задач может появиться на каждом такте
	int zv;//число выполненных задач
	int zn;//число невыполненных хадач
public:
	Cluster(double _Tmax, int _alpha, double _N, int _k);
	bool GenerateNewTask();
	void ClusterWork();
	int CountZv() { return zv; }//для проверки тестов
	friend ostream& operator<<(ostream& out, const Cluster& c)
	{
		out << "Статистика работы:" << endl << "Число тактов работы: " << c.T << endl <<
			"Число выполненных задач: " << c.zv << endl << "Число невыполненных задач: " << c.zn
			<< endl << "Процент загрузки кластера: " << c.busy << "%" << endl;
		return out;
	}
};
#endif
