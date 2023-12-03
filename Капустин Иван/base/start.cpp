#include <iostream>
#include <locale>
#include "Simul.h"
#include <thread>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double limits;
	int counts_task, nodes, tacts;
	cout << "Введите порог появления задач (0 < x < 1): ";
	cin >> limits;
	cout << "Введите максимальное количество задач, которое может появится в один так: ";
	cin >> counts_task;
	cout << "Введите количество узлов в кластере(16-64): ";
	cin >> nodes;
	cout << "Введите общее количество тактов работы: ";
	cin >> tacts;


	Simulation simulation(nodes, limits, counts_task);

	for (int i = 0; i < tacts; ++i) {
		cout << "\nТакт " << i + 1 << ":" << endl;
		simulation.processTact();
		simulation.displayState();
		std::this_thread::sleep_for(std::chrono::milliseconds(650));
	}
	system("cls");
	simulation.displayFinalStatistics(tacts);
	return 0;


}