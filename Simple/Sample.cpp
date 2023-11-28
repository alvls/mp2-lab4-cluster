#include <iostream>
#include "Cluster.h"

int main()
{
	int N;
	float alpha;
	int k;
	int T;
	int t;

	setlocale(LC_ALL, "Russian");
	cout << "Введите количество узлов (от 16 до 64): ";
	cin >> N;
	cout << "Введите вероятность появления задания (0 < a < 1): ";
	cin >> alpha;
	cout << "Введите максимальное количество заданий, выпадающих за такт: ";
	cin >> k;
	cout << "Введите максимальное время выполнения одного задания (в тактах): ";
	cin >> t;
	cout << "Введите время работы (в тактах): ";
	cin >> T;
	try
	{
		Cluster c(N, alpha, k, t);
		Statistics s = c.Implementation(T);
		cout << endl << "Число тактов работы (в тактах): " << s.time_of_working << endl;
		cout << "Число выполненных задач: " << s.count_of_completed << endl;
		cout << "Число не выполненных задач: " << s.count_of_incompleted << endl;
		cout << "Загрузка кластера (в процентах): " << s.cluster_load << endl;
	}
	catch (const char* message)
	{
		cout << endl << message << endl;
	}

	return 0;
}