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
	cout << "������� ����� ��������� ����� (0 < x < 1): ";
	cin >> limits;
	cout << "������� ������������ ���������� �����, ������� ����� �������� � ���� ���: ";
	cin >> counts_task;
	cout << "������� ���������� ����� � ��������(16-64): ";
	cin >> nodes;
	cout << "������� ����� ���������� ������ ������: ";
	cin >> tacts;


	Simulation simulation(nodes, limits, counts_task);

	for (int i = 0; i < tacts; ++i) {
		cout << "\n���� " << i + 1 << ":" << endl;
		simulation.processTact();
		simulation.displayState();
		std::this_thread::sleep_for(std::chrono::milliseconds(650));
	}
	system("cls");
	simulation.displayFinalStatistics(tacts);
	return 0;


}