#include "cluster.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	int _alpha, _k;
	double _Tmax, _N;
	cout << "Введите начальные данные" << endl;
	cout << "Максимальное кол-во тактов работы: ";
	cin >> _Tmax;
	cout << "Кол-во вычислительных узлов (16 <= n <= 64): ";
	cin >> _N;
	cout << "Допустимое кол-во новых задач на каждом такте: ";
	cin >> _k;
	cout << "Вероятность возникновения новой задачи (1 <= alpha <= 100): ";
	cin >> _alpha;
	Cluster c(_Tmax, _alpha, _N, _k);
	c.ClusterWork();
	cout << c;
	system("pause");
	return 0;
}