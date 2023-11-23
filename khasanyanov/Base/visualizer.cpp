#include "visualizer.h"

void Visualizer::draw_status_fields(int x, int y){
	Console::write(x + 20, y + 0, L"Состояние кластера");
	Console::write(x + 0, y + 2, L"Такт номер: " + to_wstring(cluster.get_stat().T));
	Console::write(x + 0, y + 4, L"Задач в очереди: " + to_wstring(cluster.get_queue().size()));
	Console::write(x + 0, y + 6, L"Задач на выполнении: " + to_wstring(cluster.get_tasks().size()));
	Console::write(x + 0, y + 8, L"Свободных узлов: " + to_wstring(cluster.get_nodes() - cluster.get_busy_nodes()));
	Console::write(x + 0, y + 10, L"Выполнено задач: " + to_wstring(cluster.get_stat().executed_tasks));
	Console::write(x + 0, y + 12, L"Тактов простоя: " + to_wstring(cluster.get_stat().free_tacts));
	Console::write(x + 0, y + 14, L"Нагрузка на кластер: " + to_wstring(cluster.get_stat().I / cluster.get_stat().T * 100.) + L"%");
}

void Visualizer::draw_cluster_load(int x, int y) {
	size_t load_percent = size_t((cluster.get_stat().I / cluster.get_stat().T) * 100);
	Console::write(x + 44, y + 2, to_wstring(load_percent) + L"%");
	Console::set_pixel_foreground(Console::DARKGRAY);
	size_t i = 4;
	for (; i < 14; i++) {
		Console::set_pixel(x + 40, y + i, L'█');
		Console::set_pixel(x + 50, y + i, L'█');
	}
	Console::write(x + 40, y + i, L"███████████");

	Console::set_pixel_foreground(load_percent < 70 ? Console::GREEN : Console::RED);
	int full = load_percent / 10, remains = load_percent % 10;
	for (; full >= 0; full--, i--) {
		Console::write(x + 41, y + i - 1, L"█████████");
	}
	if (remains >= 5) Console::write(x + 41, y + i - 1, L"▄▄▄▄▄▄▄▄▄");
}

void Visualizer::draw(int x, int y){
	draw_status_fields(x, y);
	draw_cluster_load(x, y);
	Console::set_pixel_foreground(Console::GREEN);
}

void Visualizer::draw_result(int x, int y){
	Console::clear();
	Console::write(x + 0, y + 0,L"Выполнено задач: " + to_wstring(cluster.get_stat().executed_tasks));
	Console::write(x + 0, y + 1,L"Не выполнено задач: " + to_wstring( cluster.get_stat().failed_tasks));
	Console::write(x + 0, y + 2,L"Всего задач: " + to_wstring( cluster.get_stat().summary_tasks));
	Console::write(x + 0, y + 3,L"Тактов простоя: " + to_wstring( cluster.get_stat().free_tacts));
	Console::write(x + 0, y + 4,L"Средняя загрузка кластера: " + to_wstring(cluster.get_stat().I * 100.) + L"%");
	Console::flush();
}

Visualizer::Visualizer(const Cluster& c) : cluster(c) {}
