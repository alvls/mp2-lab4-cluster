#include "visualizer.h"

void Visualizer::draw_cluster_load(){
	console.write(0, 0, L"Задач на выполнении: " + to_wstring(cluster.get_tasks().size()));
}

void Visualizer::draw_status_fields()
{
}

void Visualizer::draw(){
	draw_cluster_load();
}

Visualizer::Visualizer(Cluster c, Console con) : cluster(c), console(con) {}
