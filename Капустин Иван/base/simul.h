#ifndef __SIMULATION_H__
#define __SIMULATION_H__
#include "cluster.h"
#include <random>
using namespace std;
class Simulation {
private:
	Cluster cluster;
	double limits; // ����� ��������� �����
	int max;    // ������������ ���������� ����� �� ����
	int time;    // ����� ������ ���������
	int maxNodes;    // ������������ ���������� �����
	random_device rand;
	mt19937 generation;
	uniform_real_distribution<> distrib;

public:
	Simulation(int Nodes, double lim, int max);
	void generateTasks();
	void processTact();
	void displayState();
	void displayFinalStatistics(int T);
};
#endif

