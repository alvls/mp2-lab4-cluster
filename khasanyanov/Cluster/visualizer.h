#ifndef __VISUALIZER_H__
#define __VISUALIZER_H__

#include "cluster.h"
#include "console.h"

class Visualizer {
	const Cluster& cluster;                // ссылка на кластер, работу которого нужно визуализировать
	void draw_cluster_load(int x, int y);  // вывод состояния полей кластера
	void draw_status_fields(int x, int y); // визуализация загрузки кластера
public:
	Visualizer(const Cluster& c);		   // конструктор-инициализатор
	void draw(int x, int y);			   // визуализация работы кластера
	void draw_result(int x, int y);		   // вывод результатов работы

};
#endif
