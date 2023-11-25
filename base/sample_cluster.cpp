#include <iostream>
#include <locale>
#include "Simulation.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	double L;
	int k, N, T;

	cout << "Введите L (0 < L < 1), порог появления задач: ";
	cin >> L;
	cout << "Введите k (>= 1), максимальное количество задач, которое может появится в один так: ";
	cin >> k;
	cout << "Введите N (16 - 64), количество узлов в кластере: ";
	cin >> N;
	cout << "Введите T, общее количество тактов работы: ";
	cin >> T;

	if (L <= 0 || L >= 1 || k < 1 || N < 16 || N > 64 || T < 1) {
		cerr << "Неверные параметры. Завершение программы." << endl;
		return 1;
	}

	Simulation simulation(N, L, k);

	for (int i = 0; i < T; ++i) {
		cout << "\nТакт " << i + 1 << ":" << endl;
		simulation.processTact();
		simulation.displayState();
		system("pause");
	}
	system("cls");
	simulation.displayFinalStatistics(T);
	return 0;
}
