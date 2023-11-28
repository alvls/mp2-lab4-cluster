#include <random>
#include "Task.h"

using namespace std;


task::task(int tañtsLimit, int nodesLimit) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> rand_tañts(1, tañtsLimit);
	uniform_int_distribution<int> rand_nodes(1, nodesLimit - 1);
	tañts = rand_tañts(gen);
	nodes = rand_nodes(gen);
	id = nextId++;
}

bool task::runTañt() { 
	
	if (tañts == 0) { return false; }
	
	--tañts;
	return true;
}

int task::getNodes() const { return nodes; }

int task::getTañts() const { return tañts; }

int task::getId() const { return id; }

int task::nextId = 0;
