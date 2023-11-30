#include <iostream>
#include <ctime>
#include "cluster.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		size_t N;
		float alpha;
		int k, T, t;

		std::cout << "Введите количество узлов (от 16 до 64): ";
		std::cin >> N;

		std::cout << "Введите вероятность появления задания (0 < alpha < 1): ";
		std::cin >> alpha;

		std::cout << "Введите максимальное количество заданий, выпадающих за такт: ";
		std::cin >> k;

		std::cout << "Введите максимальное время выполнения одного задания (в тактах): ";
		std::cin >> t;

		std::cout << "Введите время работы (в тактах): ";
		std::cin >> T;

		TCluster cluster(N);

		while (T > 0)
		{
			cluster.generate_tasks(alpha, k, t);
			cluster.process();
			--T;
		}

		auto stats = cluster.get_statistics();

		std::cout << "\nСтатистика работы кластера:\n";
		std::cout << "Общее количество циклов работы: " << stats.time_of_working << "\n";
		std::cout << "Количество завершенных задач: " << stats.count_of_completed << "\n";
		std::cout << "Количество незавершенных задач: " << stats.count_of_incompleted << "\n";
		std::cout << "Загрузка кластера: " << stats.cluster_load << "%\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}

	return 0;
}