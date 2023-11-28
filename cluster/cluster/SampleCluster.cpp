#include <iostream>
#include "Console.h"
#include "Cluster.h"


int main() {

	setlocale(LC_ALL, "ru_RU");

	cluster newCluster(48, 10000, 3, 5, 0.5);
	newCluster.runCluster();

	return 0;
}
