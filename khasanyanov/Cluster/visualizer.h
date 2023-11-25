#ifndef __VISUALIZER_H__
#define __VISUALIZER_H__

#include "cluster.h"
#include "console.h"

class Visualizer {
	const Cluster& cluster;                // ������ �� �������, ������ �������� ����� ���������������
	void draw_cluster_load(int x, int y);  // ����� ��������� ����� ��������
	void draw_status_fields(int x, int y); // ������������ �������� ��������
public:
	Visualizer(const Cluster& c);		   // �����������-�������������
	void draw(int x, int y);			   // ������������ ������ ��������
	void draw_result(int x, int y);		   // ����� ����������� ������

};
#endif
