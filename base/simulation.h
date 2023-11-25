#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "tcluster.h"
#include <random>

using namespace std;

class Simulation {
private:
	Cluster cluster;
	double L; // Порог появления задач
	int k;    // Максимальное количество задач на такт
	int T;    // Время работы симуляции
	int N;    // Максимальное количество узлов
	random_device rd;
	mt19937 gen;
	uniform_real_distribution<> dis;

public:
	Simulation(int Nodes, double L, int k);
	void generateTasks();
	void processTact();
	void displayState();
	void displayFinalStatistics(int T);
};

#endif
