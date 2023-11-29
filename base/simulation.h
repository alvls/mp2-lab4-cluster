#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include <random>
#include "cluster.h"

using namespace std;

class Simulation {
private:

   Cluster cluster;
   random_device randomDevice;
   mt19937 randomGenerator;
   uniform_real_distribution<> uniformDistribution;

   int k;    // количество задач на такт, которые могут появиться
   int N;    // Максимальное количество узлов
   int T;    // Время работы(в тактах)
   double L; // порог для появления задач

public:

   Simulation(int totalNodes, double _L, int _k);
   void generateRandomTasks();
   void processingTact();
   void showFinalStatistics(int T);
   void showState();
};

#endif