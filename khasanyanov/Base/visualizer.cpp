#include "visualizer.h"

void Visualizer::draw_cluster_load(){
	Console::write(0, 0, L"Такт номер: " + to_wstring(cluster.get_stat().T));
	Console::write(0, 1, L"Задач в очереди: " + to_wstring(cluster.get_queue().size()));
	Console::write(0, 2, L"Задач на выполнении: " + to_wstring(cluster.get_tasks().size()));
}

void Visualizer::draw_status_fields()
{
}

void Visualizer::draw(){
	draw_cluster_load();
}

Visualizer::Visualizer(const Cluster& c) : cluster(c) {}
