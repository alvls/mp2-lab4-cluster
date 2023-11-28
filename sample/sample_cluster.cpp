#include <iostream>
#include "Cluster.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	system("title Имитация системы управления кластером");

	unsigned int nodes, tacts;
	double alpha;

	cout << "Введите количество узлов (N) кластера (N >= 1): ";
	cin >> nodes;
	cout << "Введите количество тактов (T) работы кластера (T >= 1): ";
	cin >> tacts;
	cout << "Введите вероятность (a) появления задачи на такте (0 < a < 1): ";
	cin >> alpha;

	shared_ptr<TCluster> cluster;
	try
	{
		cluster = make_shared<TCluster>(nodes, tacts, alpha);
	}
	catch (const exception& e)
	{
		cerr << "Ошибка при создании кластера: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	TCluster cl(nodes, tacts, alpha);
	cl.exec();
	system("cls");
	cout << cl.get_stats();

	return EXIT_SUCCESS;
}